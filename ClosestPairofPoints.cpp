// Title: Power Function (x^n)
// Description: Compute x^n using recursive halving.
// Input: x = 2.0, n = 10
// Output: 1024.0

#include <iostream>
using namespace std;

double power(double x, long long n) {
    if (n == 0) return 1.0;
    double half = power(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return half * half * x;
}

int main() {
    double x = 2.0;
    int n = 10;
    cout << "Power: " << power(x, n) << "\n"; // expected 1024
    return 0;
}
