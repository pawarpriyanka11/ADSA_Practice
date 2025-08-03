// Title: Find Minimum in Rotated Sorted Array
// Description: Find the smallest element in a rotated sorted array in O(log n).
// Input: arr = {3,4,5,1,2}
// Output: 1

#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] > arr[r]) l = m + 1;
        else r = m;
    }
    return arr[l];
}

int main() {
    int arr[] = {3,4,5,1,2};
    cout << "Minimum is: " << findMin(arr, 5) << "\n"; // expected 1
    return 0;
}
