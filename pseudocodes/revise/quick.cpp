#include <iostream>
using namespace std;

int partition(int left, int right, int arr[]){
    int i = left - 1;
    int pi = arr[right];

    for(int j = 0; j<right; j++){
        if(arr[j] < pi){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}
int heap(int left, int right, int arr[]){
    if(right > left){
        int pi = partition(left, right, arr);

        heap(left, pi+1, arr);
        heap(pi -1, right, arr);
    }
}