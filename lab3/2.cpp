#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 1, 3, 4, 10, 40 };
    int x = 10;
    float n = sizeof(arr) / sizeof(arr[0]);

    cout << n;
    return 0;
}