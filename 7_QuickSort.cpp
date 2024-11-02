#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int partitionIndex(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l + 1, j = r;

    while (i < j)
    {
        if (arr[i] < pivot)
            i++;
        if (arr[j] > pivot)
            j--;
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
        }
    }

    if (arr[i] < pivot)
    {
        swap(arr[l], arr[i]);
    }

    return i;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partitionIndex(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi, r);
    }
    return;
}
int main()
{
    int arr[10] = {60, 54, 25, 78, 48, 35, 63, 3, 5, 10};

    // Printing the given array
    cout << "The given Array:\n";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, 9);

    // Printing the sorted array
    cout << "\nArray after quick sort:\n";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}