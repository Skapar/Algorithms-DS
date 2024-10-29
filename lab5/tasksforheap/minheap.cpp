#include <iostream>
using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void heapUp(long long arr[], int i) {
    while (i > 0) {
        int p = parent(i);
        if (arr[i] > arr[p]) {
            swap(arr[i], arr[p]);
            i = p;
        } else {
            break;
        }
    }
}

void heapDown(long long arr[], int size, int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapDown(arr, size, largest);
    }
}

int main() {
    int q, k;
    cin >> q >> k;

    long long arr[k];
    int size = 0;

    while (q--) {
        string s;
        cin >> s;

        if (s == "insert") {
            long long x;
            cin >> x;

            if (size < k) {
                arr[size] = x;
                size++;
                heapUp(arr, size - 1);
            } else {
                int minIdx = 0;

                for (int i = 1; i < k; i++) {
                    if (arr[i] < arr[minIdx]) {
                        minIdx = i;
                    }
                }

                if (x > arr[minIdx]) {
                    arr[minIdx] = x;
                    heapUp(arr, minIdx);
                }
            }
        }

        if (s == "print") {
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                sum += arr[i];
            }
            cout << sum << endl ;
        }
    }

    return 0;
}
