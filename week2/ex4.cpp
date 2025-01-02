#include<bits/stdc++.h>

using namespace std;

int a[9][9];
int res = 0;

bool check_square(int r, int c, int value){
    int r_start = (r/3) * 3;
    int c_start = (c/3) * 3;
    for (int i = r_start; i< r_start + 3; i++){
        for (int j = c_start; j< c_start + 3; j++){
            if (a[i][j] == value){
                return false;
            }
        }
    }
    return true;
}

bool check_rc(int r, int c, int value){
    for (int i = 0; i< 9; i++){
        if (a[r][i] == value || a[i][c] == value){
            return false;
        }
    }
    return true;
}

void Try(int r, int c){
    if (r == 9){
        res++;
        return;
    }
    if (a[r][c] == 0){
        for (int i = 1; i<= 9; i++){
            if (check_square(r, c, i) && check_rc(r, c, i)){
                a[r][c] = i;
                if (c == 8){
                    Try(r+1, 0);
                }else{
                    Try(r, c+1);
                }
                a[r][c] = 0;
            }
        }
    }else{
        if (c == 8){
            Try(r+1, 0);
        }else{
            Try(r, c+1);
        }
    }
    return;
}

int main(){
    for (int i = 0; i< 9; i++){
        for (int j = 0; j< 9; j++){
            cin >> a[i][j];
        }
    }
    Try(0, 0);
    cout << res;
}
