// Title: Different Ways to Add Parentheses
// Description: Evaluate all results from all valid ways to add parentheses.
// Input: "2-1-1"
// Output: 0 2

#include <iostream>
#include <cstring>
using namespace std;

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

void compute(char expr[], int results[], int &size) {
    size = 0;
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            int left[20], right[20], lsize, rsize;
            char leftExpr[20], rightExpr[20];

            strncpy(leftExpr, expr, i); leftExpr[i] = '\0';
            strcpy(rightExpr, expr + i + 1);

            compute(leftExpr, left, lsize);
            compute(rightExpr, right, rsize);

            for (int j = 0; j < lsize; j++)
                for (int k = 0; k < rsize; k++)
                    results[size++] = calc(left[j], right[k], expr[i]);

            return;
        }
    }
    results[size++] = atoi(expr);
}

int main() {
    char expr[] = "2-1-1";
    int results[20], size;
    compute(expr, results, size);
    for (int i = 0; i < size; i++) cout << results[i] << " ";
}