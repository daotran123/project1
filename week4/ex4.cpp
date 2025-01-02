#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int > st;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i< n; i++){
        cin >> a[i];
        if (st.find(a[i]) == st.end()){
            cout << 0 << endl;
            st.insert(a[i]);
        }else{
            cout << 1 << endl;
        }
    }


}
