#include<bits/stdc++.h>

using namespace std;

vector<int > vt; // kiểm tra đã tồn tại chưa
deque<int> dq; // danh sách

int main(){
    int n;
    cin >> n;
    for (int i = 0; i< n; i++){
        int x;
        cin >> x;
        vt.push_back(x);
        dq.push_back(x);
    }

    string command;
    while (1){
        cin >> command;
        if (command == "#"){
            break;
        }else if (command == "addlast"){
            int x;
            cin >> x;
            if (find(vt.begin(), vt.end(), x) == vt.end()){
                vt.push_back(x);
                dq.push_back(x);
            }
        }else if (command == "addfirst"){
            int x;
            cin >> x;
            if (find(vt.begin(),vt.end(),x) == vt.end()){
                vt.push_back(x);
                dq.push_front(x);
            }
        }else if (command == "addafter"){
            int u, v;
            cin >> u >> v;
            if (find(vt.begin(),vt.end(),v) != vt.end() && find(vt.begin(),vt.end(),u) == vt.end()){
                vt.push_back(u);
                auto it = dq.begin();
                while (it != dq.end() && *it != v) it++;
                it++;
                dq.insert(it, u);
            }
        }else if (command == "addbefore"){
            int u, v;
            cin >> u >> v;
            if (find(vt.begin(), vt.end(),v) != vt.end() && find(vt.begin(), vt.end(),u) == vt.end()){
                vt.push_back(u);
                auto it = dq.begin();
                while (it != dq.end() && *it != v) it++;
                dq.insert(it, u);

            }
        }else if (command == "remove") {
            int k;
            cin >> k;
            if (find(vt.begin(), vt.end(), k) != vt.end()) {
                auto it = dq.begin();
                while (it != dq.end() && *it != k) ++it;
                if (it != dq.end()) {
                    dq.erase(it);
                }
                vt.erase(remove(vt.begin(), vt.end(), k), vt.end());
            }
        }else if (command == "reverse") {
            reverse(dq.begin(), dq.end());
        }



    }

    for (auto x : dq){
        cout << x << " ";
    }

}
