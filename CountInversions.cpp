// Title: Count Inversions
// Description: Count pairs (i < j) where arr[i] > arr[j] using merge sort.
// Input: arr = {2,4,1,3,5}
// Output: 3

#include <iostream>
using namespace std;

long long mergeCount(int arr[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    long long inv = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (m - i + 1);
        }
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int t = l; t <= r; t++) arr[t] = temp[t];
    return inv;
}

long long sortCount(int arr[], int temp[], int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    long long cnt = sortCount(arr, temp, l, m);
    cnt += sortCount(arr, temp, m+1, r);
    cnt += mergeCount(arr, temp, l, m, r);
    return cnt;
}

long long countInversions(int arr[], int n) {
    int temp[100]; // assume n <= 100
    return sortCount(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2,4,1,3,5};
    cout << "Inversions: " << countInversions(arr, 5) << "\n"; // expected 3
    return 0;
}
