// Title: K-th Smallest in Two Sorted Arrays
// Description: Merge two sorted arrays until we reach k-th smallest.
// Input: nums1 = {1,3}, nums2 = {2}, k = 2
// Output: 2

#include <iostream>
using namespace std;

int kthSmallest(int a[], int na, int b[], int nb, int k) {
    int i = 0, j = 0, count = 0;
    int last = -1;
    while (i < na || j < nb) {
        int val;
        if (i < na && (j >= nb || a[i] <= b[j])) {
            val = a[i++];
        } else {
            val = b[j++];
        }
        count++;
        if (count == k) return val;
    }
    return -1; // invalid
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int k = 2;
    int ans = kthSmallest(nums1, 2, nums2, 1, k);
    cout << "k-th smallest is: " << ans << "\n"; // expected 2
    return 0;
}
