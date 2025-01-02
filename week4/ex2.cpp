#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_set<string> u_st;
    string x, x1;
    while(1){
        cin >> x;
        if (x == "*"){
            break;
        }
        u_st.insert(x);
    }

    while(1){
        cin >> x;
        if (x == "***"){
            break;
        }
        cin >> x1;
        if (x == "find"){
            if (u_st.find(x1) != u_st.end()){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            if (u_st.find(x1) != u_st.end()){
                cout << 0 << endl;
            }else{
                cout << 1 << endl;
                u_st.insert(x1);
            }
        }
    }
}
