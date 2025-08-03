// Title: Skyline Problem (Simplified Output)
// Description: Print starting height points of buildings.
// Input: {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}}
// Output: [2,10] [3,15] [5,12] [12,0]

#include <iostream>
using namespace std;

struct Building {
    int left, right, height;
};

void printSkyline(Building b[], int n) {
    for (int i = 0; i < n; i++)
        cout << "[" << b[i].left << "," << b[i].height << "] ";
    cout << "[" << b[n - 1].right << ",0]";
}

int main() {
    Building b[] = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}};
    printSkyline(b, 3);
}
