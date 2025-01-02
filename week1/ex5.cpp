#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    int count = 0;
    int res = 0;
    while(1){
        getline(cin, a);
        if (a.empty()) {
            count ++;
        }
        else{
            count = 0;
        }
        if (count > 5){
            cout << res;
            break;
        }
        if (!a.empty()){
            int start = 0;
            while(a[start] == ' ') start++;
            if (start < a.length())res++;
            for (int i = start; i< a.length()-1; i++){
                if (a[i] == ' ' && a[i+1] != ' ') res++;
            }
            cout << res << endl;
        }
        if (a == "*****"){
            cout << res;
            break;
        }
    }

}
