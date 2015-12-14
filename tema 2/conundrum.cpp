/*
https://open.kattis.com/problems/conundrum
*/

#include <iostream>
#include <cstring>

using namespace std;

const int NMAX = 300 + 1;

int l;
char s[NMAX];

void read() {
    cin >> s;
    l = strlen(s);
}

void solve() {
    int result = 0;

    for (int i = 0; i < l; i+= 3) {
        if (s[i + 0] != 'P') result++;
        if (s[i + 1] != 'E') result++;
        if (s[i + 2] != 'R') result++;
    }

    cout << result << '\n';
}

int main() {
    read();
    solve();
    return 0;
}
