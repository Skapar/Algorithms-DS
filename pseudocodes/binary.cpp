#include <iostream>
using namespace std;

void binary(int l, int r, int arr[], int m){
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] == m){
            cout << mid;
            return;
        }
        else if(arr[mid] < m){
            l = mid +1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    binary(0, 4, arr, 5);
}