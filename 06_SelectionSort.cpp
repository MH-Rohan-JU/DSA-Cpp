#include <algorithm>
#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int n, i, j;
    cout << "Enter the total number of array: ";
    cin >> n;
    int arr[n];

    cout << "\nEnter " << n << " elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for (i = n - 1; i >= 1; i--) {
        int maxEl = arr[0];
        int maxInd = 0;
        for (j = 0; j <= i; j++) {
            if (arr[j] > maxEl) {
                maxEl = arr[j];
                maxInd = j;
            }
        }
        swap(arr[maxInd], arr[--j]);
    }

    cout << "\nAfter applying selection sort, the sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}