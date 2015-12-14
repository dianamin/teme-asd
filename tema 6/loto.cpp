/*
http://www.infoarena.ro/problema/loto
*/n

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

ifstream f ("loto.in");
ofstream g ("loto.out");

const int NMAX = 100 + 1;

struct Suma {
    int a, b, c, s;
};

int n, s, nr_sume;
int v[NMAX];
Suma suma[NMAX * NMAX * NMAX];

void citeste() {
    f >> n >> s;
    for (int i = 1; i <= n; i++)
        f >> v[i];
}

void init() {
    int aux;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = j; k <= n; k++) {
                aux = v[i] + v[j] + v[k];
                if (aux > s) continue;

                ++nr_sume;

                suma[nr_sume].s = aux;
                suma[nr_sume].a = i;
                suma[nr_sume].b = j;
                suma[nr_sume].c = k;
            }
}

inline bool comp(Suma x, Suma y) {
    return x.s < y.s;
}

void scrie(Suma x, Suma y) {
    g << v[x.a] << ' ' << v[x.b] << ' ' << v[x.c] << ' ';
    g << v[y.a] << ' ' << v[y.b] << ' ' << v[y.c] << '\n';
}

void rezolva() {
    int s1, s2;
    int i, j, k;

    i = 1; j = nr_sume;

    while(i <= j) {
        s1 = suma[i].s;
        s2 = s - suma[i].s;

        while (j >= i && suma[j].s > s2) j--;

        if (i > j) {
            g << -1;
            break;
        }

        if (suma[j].s != s2) {
            i++;
            continue;
        }

        scrie(suma[i], suma[j]);
        break;
    }

    if (i > j) g << -1;
}

int main() {
    citeste();
    init();
    sort(suma + 1, suma + nr_sume + 1, comp);
    rezolva();
    return 0;
}
