#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, M;
    cin >> n >> M;
    int a[n];
    for (int i = 0; i< n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    int i = 0;
    int j = n-1;
    int count = 0;
    while (i < j){
        if (a[i]+a[j] == M){
            count ++;
            i++;
            j--;
        }else if (a[i] + a[j] < M){
            i++;
        }else j--;
    }
    cout << count;
}
