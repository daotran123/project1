#include<bits/stdc++.h>

using namespace std;

int n;
int a[10001];

int find_max(){
    int a_max = -99999;
    for (int i = 1; i<= n; i++){
        a_max = max(a_max, a[i]);
    }
    return a_max;
}

int find_min(){
    int a_min = 99999;
    for (int i = 1; i<= n; i++){
        a_min = min(a_min, a[i]);
    }
    return a_min;
}

int sum(){
    int a_sum = 0;
    for (int i = 1; i<= n; i++)
        a_sum += a[i];

    return a_sum;
}

int find_max_segment(int s, int e){
    int a_max = -99999;
    for (int i = s; i<= e; i++){
        a_max = max(a_max, a[i]);
    }
    return a_max;
}

int main(){
    cin >> n;
    for (int i = 1; i<= n; i++) cin >> a[i];

    string x;
    cin >> x;
    if (x == "*"){
        int check_find_max = -9999;
        int check_find_min = -9999;
        int check_sum = -9999;
        string command = "";
        while(command != "***"){
            cin >> command;
            if (command == "find-max"){
                if (check_find_max == -9999){
                    check_find_max = find_max();
                    cout << check_find_max << endl;
                }else{
                    cout << check_find_max << endl;
                }
            }else if (command == "find-min"){
                if (check_find_min == -9999){
                    check_find_min = find_min();
                    cout << check_find_min << endl;
                }else{
                    cout << check_find_min << endl;
                }
            }else if (command == "sum"){
                if (check_sum == -9999){
                    check_sum = sum();
                    cout << check_sum << endl;
                }else{
                    cout << check_sum << endl;
                }
            }else if (command == "find-max-segment"){
                int s, e;
                cin >> s >> e;
                cout << find_max_segment(s, e) << endl;
            }
        }

    }
}
