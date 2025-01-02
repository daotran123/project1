#include<bits/stdc++.h>

using namespace std;

struct Transaction{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

typedef struct Transaction Transaction;

vector<Transaction> transactions;
set<string> accounts;
unordered_map<string, int> money_from_account;
map<string, vector<string > > adj;
bool res = false;
map<string, bool> visited;

void dfs(string start, string account, int k, int deep){
    if (deep == k-1){
        for (auto x : adj[account]){
            if (x == start){
                res = true;
                return;
            }
        }
    }

    for (auto x : adj[account]){
        if (!visited[x]){
            visited[x] = 1;
            dfs(start, x, k, deep+1);
            visited[x] = 0;
        }
    }
}

void cycle(string account, int k){
    res = false;

    for (auto x : accounts){
        visited[x] = false;
    }
    visited[account] = true;
    dfs(account, account, k, 0);

    if (res){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}


int main(){
    string s;
    int number_transactions = 0;
    int total_money = 0;

    while(getline(cin, s) && s != "#"){
        istringstream ss(s);
        Transaction trans;
        ss >> trans.from_account >> trans.to_account >> trans.money >> trans.time_point >> trans.atm;
        transactions.push_back(trans);

        number_transactions++;
        total_money += trans.money;
        accounts.insert(trans.from_account);
        accounts.insert(trans.to_account);
        money_from_account[trans.from_account] += trans.money;
        if (trans.from_account != trans.to_account)
            adj[trans.from_account].push_back(trans.to_account);
    }

    while(getline(cin, s) && s!= "#"){
        istringstream ss(s);
        string command;
        ss >> command;

        if (command == "?number_transactions"){
            cout << number_transactions << endl;
        }else if (command == "?total_money_transaction"){
            cout << total_money << endl;
        }else if (command == "?list_sorted_accounts"){
            for (auto x : accounts){
                cout << x << " ";
            }
            cout << endl;
        }else if (command == "?total_money_transaction_from"){
            string account;
            ss >> account;
            cout << money_from_account[account] << endl;
        }else{
            string account;
            int k;
            ss >> account;
            ss >> k;
            cycle(account, k);

        }
    }
}
