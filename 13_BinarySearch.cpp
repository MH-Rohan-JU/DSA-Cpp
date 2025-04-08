#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int binarySearch(int arr[], int l, int r, int val) {

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == val) {
            return mid;
        }
        if (arr[mid] < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, val;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter a value to search: ";
    cin >> val;

    sort(arr, arr + n);
    cout << endl;
    cout << binarySearch(arr, 0, n - 1, val) << endl;

    return 0;
}