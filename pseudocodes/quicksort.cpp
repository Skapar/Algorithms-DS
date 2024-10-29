#include <iostream>
using namespace std;

int partition(int low, int high, int arr[]){
    int i = low -1;
    int pi = arr[high];

    for(int j = 0; j<high; j++){
        if(arr[j] < pi){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
int heaps(int low, int high, int arr){
    if(low < high){
        
        int pi = partition(low, high, arr);

        heaps(low, pi+1, arr);
        heaps(pi - 1, high, arr);
    }
}