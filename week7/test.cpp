#include<bits/stdc++.h>

using namespace std;


int arr[10] = {1,2,4,7,9,12,14,17,24,50};

int binarySearch(int time1){
    int left = 0;
    int right = 10 - 1;

    while (left < right){
        int mid = (left + right)/2;
        if (arr[mid] > time1){
            right = mid;
        }else if (arr[mid] < time1){
            left = mid + 1;
        }else{
            left = mid;
            break;
        }

        cout << arr[left] << " " << arr[right] << endl;
    }

    return left;
}

int main(){

    while(1){

        int x;
        cin >> x;
        cout << binarySearch(x) << endl;
    }

}
