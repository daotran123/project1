//C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    int count = 0;
    cin >> n >> k;
    int a[n+1];
    for (int i = 0; i< n; i++){
        cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i< k; i++){
        sum += a[i];
    }
    if (sum % 2 == 0) count++;
    for (int i = k; i< n; i++){
        sum = sum + a[i] - a[i-k];
        if (sum % 2 ==0) count++;
    }
    cout << count;
}
