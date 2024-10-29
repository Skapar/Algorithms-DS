#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minLen = n + 1;
    int currSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        currSum += arr[right];

        while (currSum >= k) {
            minLen = min(minLen, right - left + 1);
            currSum -= arr[left];
            left++;
        }
    }

    cout << minLen << endl;

    return 0;
}
