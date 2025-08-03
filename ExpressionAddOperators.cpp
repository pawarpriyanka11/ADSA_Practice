// Title: Expression Add Operators
// Description: Add '+', '-', '*' between digits to match target value.
// Input: num = "123", target = 6
// Output: 1+2+3, 1*2*3

#include <iostream>
#include <cstring>
using namespace std;

void helper(char num[], int target, int pos, long eval, long mult, char path[], int plen) {
    if (num[pos] == '\0') {
        if (eval == target) {
            path[plen] = '\0';
            cout << path << endl;
        }
        return;
    }

    char temp[20];
    long cur = 0;
    for (int i = pos, len = 0; num[i]; i++) {
        cur = cur * 10 + (num[i] - '0');
        temp[len++] = num[i];
        temp[len] = '\0';

        if (pos == 0) {
            strcpy(path, temp);
            helper(num, target, i + 1, cur, cur, path, len);
        } else {
            path[plen] = '+'; strcpy(path + plen + 1, temp);
            helper(num, target, i + 1, eval + cur, cur, path, plen + len + 1);

            path[plen] = '-'; strcpy(path + plen + 1, temp);
            helper(num, target, i + 1, eval - cur, -cur, path, plen + len + 1);

            path[plen] = '*'; strcpy(path + plen + 1, temp);
            helper(num, target, i + 1, eval - mult + mult * cur, mult * cur, path, plen + len + 1);
        }

        if (num[pos] == '0') break;
    }
}

int main() {
    char num[] = "123";
    int target = 6;
    char path[100];
    helper(num, target, 0, 0, 0, path, 0);
}