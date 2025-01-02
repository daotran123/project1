//C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int start = (100/n > 0) ? 100/n : 1;
    int end = 999/n;
    if (start * n >= 100) cout << start*n << " ";
    for (int i = start + 1; i<= end; i++) cout << n*i << " ";
}
