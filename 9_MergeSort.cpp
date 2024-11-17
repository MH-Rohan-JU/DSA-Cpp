#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void merge(int arr[], int l, int mid, int r) {
    int s1 = mid - l + 1, s2 = r - l;
    int a[s1], b[s2], i, j, k;

    for (i = 0; i < s1; i++) {
        a[i] = arr[l + i];
    }

    for (i = 0; i < s2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    i = 0, j = 0, k = l;
    while (i < s1 && j < s2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++, k++;
        } else {
            arr[k] = b[j];
            j++, k++;
        }
    }
    while (i < s1) {
        arr[k] = a[i];
        i++, k++;
    }

    while (j < s2) {
        arr[k] = b[j];
        j++, k++;
    }

    return;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
    return;
}
int main() {
    int size = 8;
    int arr[size] = {56, 71, 28, 98, 12, 44, 64, 35};

    cout << "The unsorted array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int l = 0, r = size - 1;
    mergeSort(arr, l, r);

    cout << "\nAfter applying Merge Sort:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}