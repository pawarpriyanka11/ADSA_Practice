// Title: Majority Element
// Description: Find the element appearing more than n/2 times using divide & conquer.
// Input: {3, 2, 3}
// Output: 3

#include <iostream>
using namespace std;

int countFreq(int arr[], int l, int r, int num) {
    int count = 0;
    for (int i = l; i <= r; i++)
        if (arr[i] == num) count++;
    return count;
}

int majority(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int mid = (l + r) / 2;
    int left = majority(arr, l, mid);
    int right = majority(arr, mid + 1, r);
    if (left == right) return left;
    int leftCount = countFreq(arr, l, r, left);
    int rightCount = countFreq(arr, l, r, right);
    return (leftCount > rightCount) ? left : right;
}

int main() {
    int arr[] = {3, 2, 3};
    int n = 3;
    cout << majority(arr, 0, n - 1);
}
