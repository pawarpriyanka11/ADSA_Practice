// Title: 
// Description: Find subarray with the largest sum.
// Input: {-2, 1, -3, 4, -1, 2, 1, -5, 4}
// Output: 6

#include <iostream>
#include <climits>
using namespace std;

int maxCrossing(int arr[], int l, int m, int r) {
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubarray(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    int left = maxSubarray(arr, l, m);
    int right = maxSubarray(arr, m + 1, r);
    int cross = maxCrossing(arr, l, m, r);
    return max(left, max(right, cross));
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;
    cout << maxSubarray(arr, 0, n - 1);
}
