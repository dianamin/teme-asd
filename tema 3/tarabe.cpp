/*
http://www.infoarena.ro/problema/tarabe
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>

using namespace std;

ifstream f ("tarabe.in");
ofstream g ("tarabe.out");

const int NMAX = 200000 + 1;

int n, k;
long long a[NMAX], b[NMAX];

void citeste() {
    f >> n >> k;
    for (int i = 1; i <= n; i++)
        f >> b[i] >> a[i];
}

bool shopping(long long cost_fix) {
    long long produse = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] > cost_fix) continue;
        produse += (cost_fix - a[i]) / b[i] + 1;
    }

    return (produse >= k);
}

long long cost_final(long long cost_fix) {
    long long p, produse = 0, suma = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] > cost_fix) continue;
        p = (cost_fix - a[i]) / b[i] + 1;
        produse += p;
        suma += p * a[i] + p * (p - 1) / 2 * b[i];
    }
    suma -= cost_fix * (produse - k);
    return suma;
}


void cauta() {
    long long st, dr, m, sol;
    dr = 1;

    while (!shopping(dr))
        dr *= 2;

    st = dr / 2;

    sol = -1;

    while (st <= dr) {
        m = (st + dr) / 2;
        if (shopping(m)) {
            sol = m;
            dr = m - 1;
        }
        else st = m + 1;
    }

    g << cost_final(sol) << '\n';
}


int main() {
    citeste();
    cauta();
    return 0;
}
