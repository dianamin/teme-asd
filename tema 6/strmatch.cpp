/*
http://www.infoarena.ro/problema/strmatch
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream f ("strmatch.in");
ofstream g ("strmatch.out");

const int B = 127, LMAX = 2000000 + 1;

char text[LMAX], pattern[LMAX];
vector <int> sol;

void citeste() {
    f >> pattern >> text;
}

unsigned long long calculeaza_hash(char *s, int l) {
    unsigned long long h = 0;
    unsigned long long x = 1;
    for (int i = 0; i < l; i++)
        h = h * B + s[i];
    return h;
}

void rolling_hash() {
    unsigned long long h_pattern, h_crt;
    int n = strlen(pattern), m = strlen(text);

    h_pattern = calculeaza_hash(pattern, n);
    h_crt = calculeaza_hash(text, n);
    if (h_pattern == h_crt) sol.push_back(0);

    unsigned long long x = 1;
    for (int i = 1; i < n; i++) x = x * 127;

    for (int i = n; i < m; i++) {
        h_crt = h_crt - x * text[i - n];
        h_crt = h_crt * B + text[i];
        if (h_crt == h_pattern) sol.push_back(i - n + 1);
    }
}

void scrie() {
    int l = sol.size();
    g << l << '\n';
    l = min(l, 1000);
    for (int i = 0; i < l; i++) g << sol[i] << ' ';
}

int main() {
    citeste();
    rolling_hash();
    scrie();
    return 0;
}
