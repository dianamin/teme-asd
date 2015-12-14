/*
http://www.infoarena.ro/problema/iepuri
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("iepuri.in");
ofstream g ("iepuri.out");

const int MOD = 666013;
const int L = 3;

int x, y, z, a, b, c, n;
int m[L][L];
int rez[L][L];

void citeste() {
    f >> x >> y >> z >> a >> b >> c >> n;
}

void init() {
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++) {
            if (i == j)
                rez[i][j] = 1;
            else
                rez[i][j] = 0;

            m[i][j] = 0;
        }

    m[0][1] = 1;
    m[1][2] = 1;
    m[2][0] = c;
    m[2][1] = b;
    m[2][2] = a;
}

void inmulteste(int m1[][L], int m2[][L], int aux[][L]) {
    int aux2[L][L];
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++) {
            long long a = 0;
            for (int k = 0; k < L; k++) {
                a = (a + 1LL * m1[i][k] * m2[k][j] % MOD) % MOD;
            }
            aux2[i][j] = a;
        }

    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            aux[i][j] = aux2[i][j];
}

void rezolva() {

    for (long long p = 0; (1LL << p) <= n; p++) {
        if ((n & (1LL << p)) != 0) {
            inmulteste(rez, m, rez);
        }
        inmulteste(m, m, m);
    }

    int iepuri = (1LL * rez[0][0] * x % MOD + 1LL * rez[0][1] * y % MOD + 1LL * rez[0][2] * z % MOD) % MOD;

    g << iepuri << '\n';
}

int main() {
    int t;
    f >> t;
    while (t--) {
        citeste();
        init();
        rezolva();
    }
    return 0;
}
