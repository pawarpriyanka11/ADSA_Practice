// Title: K-th Largest Element in Array
// Description: Find the k-th largest element using QuickSelect.
// Input: {3, 2, 1, 5, 6, 4}, k = 2
// Output: 5

#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] > pivot) {
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i]; arr[i] = arr[r]; arr[r] = temp;
    return i;
}

int quickSelect(int arr[], int l, int r, int k) {
    if (l == r) return arr[l];
    int pi = partition(arr, l, r);
    if (pi == k) return arr[pi];
    else if (pi > k) return quickSelect(arr, l, pi - 1, k);
    else return quickSelect(arr, pi + 1, r, k);
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << quickSelect(arr, 0, 5, k - 1);
}
