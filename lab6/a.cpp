#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(const vector<int>& v) {
    int n = v.size();
    if (n <= 1) {
        return v;
    }

    vector<int> left(v.begin(), v.begin() + n/2);
    vector<int> right(v.begin() + n/2, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> result;
    int leftIdx = 0, rightIdx = 0;
    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] < right[rightIdx]) {
            result.push_back(left[leftIdx]);
            leftIdx++;
        } else {
            result.push_back(right[rightIdx]);
            rightIdx++;
        }
    }

    while (leftIdx < left.size()) {
        result.push_back(left[leftIdx]);
        leftIdx++;
    }

    while (rightIdx < right.size()) {
        result.push_back(right[rightIdx]);
        rightIdx++;
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    a = mergeSort(a);
    b = mergeSort(b);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return 0;
}
