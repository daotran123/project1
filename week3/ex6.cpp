#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<int > dq;
    string command;
    while(1){
        cin >> command;
        if (command == "#"){
            break;
        }

        if (command == "PUSH"){
            int x;
            cin >> x;
            dq.push(x);
        }else if (command == "POP"){
            if (dq.empty()){
                cout << "NULL" << endl;
            }else{
                int x = dq.front();
                cout << x << endl;
                dq.pop();
            }
        }
    }
}
