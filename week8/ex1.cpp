#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Citizen {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

map<string, Citizen> citizens;

int main() {
    string line;

    // Reading citizen data until '*' is encountered
    while (getline(cin, line) && line != "*") {
        stringstream ss(line);
        Citizen c;
        ss >> c.code >> c.date_of_birth >> c.father_code >> c.mother_code >> c.is_alive >> c.region_code;
        citizens[c.code] = c;
    }

    vector<string> queries;
    // Reading queries until "***" is encountered
    while (getline(cin, line) && line != "***") {
        queries.push_back(line);
    }

    // Process each query
    for (const string& query : queries) {
        stringstream ss(query);
        string cmd;
        ss >> cmd;

        if (cmd == "NUMBER_PEOPLE") {
            // Return the number of people
            cout << citizens.size() << endl;
        }
        else if (cmd == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            ss >> date;
            int count = 0;
            for (const auto& [code, c] : citizens) {
                if (c.date_of_birth == date) {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (cmd == "MOST_ALIVE_ANCESTOR") {
            string code;
            ss >> code;

            // Find the most alive ancestor
            set<string> visited;
            string current = code;
            int generation = 0;
            while (citizens[current].father_code != "0000000" || citizens[current].mother_code != "0000000") {
                visited.insert(current);
                string father = citizens[current].father_code;
                string mother = citizens[current].mother_code;

                // Priority to go upwards with alive parents
                if (father != "0000000" && visited.find(father) == visited.end()) {
                    current = father;
                } else if (mother != "0000000" && visited.find(mother) == visited.end()) {
                    current = mother;
                }
                generation++;
            }
            cout << generation << endl;
        }
        else if (cmd == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date;
            ss >> from_date >> to_date;
            int count = 0;
            for (const auto& [code, c] : citizens) {
                if (c.date_of_birth >= from_date && c.date_of_birth <= to_date) {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (cmd == "MAX_UNRELATED_PEOPLE") {
            // Calculate the maximum number of unrelated people
            set<string> unrelated_people;
            map<string, bool> visited;

            for (const auto& [code, c] : citizens) {
                if (visited[code]) continue;
                set<string> group;
                group.insert(code);
                visited[code] = true;

                // Traverse the family tree to find relations
                string current = code;
                while (citizens[current].father_code != "0000000" || citizens[current].mother_code != "0000000") {
                    string father = citizens[current].father_code;
                    string mother = citizens[current].mother_code;

                    if (father != "0000000" && !visited[father]) {
                        group.insert(father);
                        visited[father] = true;
                    }
                    if (mother != "0000000" && !visited[mother]) {
                        group.insert(mother);
                        visited[mother] = true;
                    }
                    current = father != "0000000" ? father : mother;
                }
                unrelated_people.insert(group.begin(), group.end());
            }
            cout << unrelated_people.size() << endl;
        }
    }

    return 0;
}
