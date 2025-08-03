// Title: Search in Rotated Sorted Array
// Description: Given a rotated sorted array, find index of target using binary search.
// Input: arr = {4,5,6,7,0,1,2}, target = 4
// Output: 0

#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == target) return m;
        if (arr[l] <= arr[m]) { // left sorted
            if (arr[l] <= target && target < arr[m]) r = m - 1;
            else l = m + 1;
        } else { // right sorted
            if (arr[m] < target && target <= arr[r]) l = m + 1;
            else r = m - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int target = 4;
    int idx = searchRotated(arr, 7, target);
    cout << "Index of " << target << " is: " << idx << "\n"; // expected 0
    return 0;
}
