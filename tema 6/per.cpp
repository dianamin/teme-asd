/*
http://www.infoarena.ro/problema/per
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f ("per.in");
ofstream g ("per.out");

const int B = 127;
const int NMAX = 6000 + 1;

int n, k;
char s[NMAX];
unsigned long long cod[NMAX];
int len[NMAX];

void citeste() {
    f >> n >> k;
    f >> s;
}

void rezolva() {
    int lg_max = n / k, rez = 0;

    unsigned long long h, h_crt, b = 1;

    h = 0;

    for (int lg = 1; lg <= lg_max; lg++) {
        h = h * B + s[lg - 1];

        cod[lg - 1] = h;
        len[lg - 1] = 1;

        h_crt = h;
        for (int i = lg; i < n; i++) {
            h_crt = (h_crt - s[i - lg] * b) * B + s[i];
            cod[i] = h_crt;
            len[i] = 1;
            if (cod[i] == cod[i - lg]) len[i] += len[i - lg];
            if (len[i] >= k) rez++;
        }
        b *= B;
    }

    g << rez << '\n';
}

int main() {
    citeste();
    rezolva();
    return 0;
}
