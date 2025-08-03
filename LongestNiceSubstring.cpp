// Title: Longest Nice Substring
// Description: Find longest substring where every letter appears in both cases.
// Input: "YazaAay"
// Output: "aAa" (or equivalent)

#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isNice(const string &s) {
    set<char> st;
    for (char c : s) st.insert(c);
    for (char c : s) {
        if (isupper(c) && !st.count(tolower(c))) return false;
        if (islower(c) && !st.count(toupper(c))) return false;
    }
    return true;
}

string longestNice(string s) {
    if (s.size() < 2) return "";
    if (isNice(s)) return s;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        bool hasLower = false, hasUpper = false;
        for (char ch : s) {
            if (ch == tolower(c)) hasLower = true;
            if (ch == toupper(c)) hasUpper = true;
        }
        if ((islower(c) && !hasUpper) || (isupper(c) && !hasLower)) {
            string left = longestNice(s.substr(0, i));
            string right = longestNice(s.substr(i+1));
            return (left.size() >= right.size()) ? left : right;
        }
    }
    return "";
}

int main() {
    string s = "YazaAay";
    cout << "Longest nice substring: \"" << longestNice(s) << "\"\n"; // expect "aAa"
    return 0;
}
