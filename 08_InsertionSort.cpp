#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void insertionSort(int arr[], int s) {
    int i, j;
    for (i = 1; i < s; i++) {
        int temp = arr[i];
        j = i - 1;
        while (arr[j] > temp && j > -1) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return;
}
int main() {
    int size = 8;
    int arr[size] = {56, 71, 28, 98, 12, 44, 64, 35};

    cout << "The unsorted Array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, size); // Insertion Sort func call

    cout << "\nAfter applying insertion sort" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}