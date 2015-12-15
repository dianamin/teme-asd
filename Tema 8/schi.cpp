/*
http://www.infoarena.ro/problema/schi
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("schi.in");
ofstream g ("schi.out");

const int NMAX = 30000;
int n, poz;
int p[NMAX + 1], sol[NMAX + 1], arb[4 * NMAX + 1];

void ocupa(int nod, int stanga, int dreapta) {
    if (stanga == dreapta) arb[nod] = 1;
    else {
        int m = (stanga + dreapta) / 2;
        if (poz <= m) ocupa(2 * nod, stanga, m);
        else ocupa(2 * nod + 1, m + 1, dreapta);
        arb[nod] = arb[2 * nod] + arb[2 * nod + 1];
    }
}

void pune(int nod, int stanga, int dreapta, int nr) {
    if (stanga == dreapta) {
        arb[nod] = 0;
        sol[stanga] = poz;
    }
    else {
        int m = (stanga + dreapta) / 2;
        if (nr <= arb[nod * 2]) pune(nod * 2, stanga, m, nr);
        else pune(nod * 2 + 1, m + 1, dreapta, nr - arb[2 * nod]);
        arb[nod] = arb[2 * nod + 1] + arb[2 * nod];
    }
}

void citeste() {
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> p[i];
        poz = i;
        ocupa(1, 1, n);
    }
}

void rezolva() {
    for (int i = n; i >= 1; i--) {
        poz = i;
        pune(1, 1, n, p[i]);
    }
    for (int i = 1; i <= n; i++) g << sol[i] << '\n';
}

int main () {
    citeste();
    rezolva();
}
