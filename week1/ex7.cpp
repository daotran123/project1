#include<bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(){
    int a, b, c;
    cin >> a>> b >> c;
    float detal = b*b - 4*a*c;
    if (detal < 0) cout << "NO SOLUTION" << endl;
    else if (detal == 0){
        float x = (-b/(2*a));
        printf("%.2f\n", x);
    }else{
        detal = sqrt(detal);
        float x1 = (-b - detal)/(2*a);
        float x2 = (-b + detal)/(2*a);
        printf("%.2f %.2f", x1, x2);
    }
}
