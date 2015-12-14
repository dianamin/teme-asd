/*
http://www.infoarena.ro/problema/cautbin
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("cautbin.in");
ofstream g ("cautbin.out");

const int NMAX = 100000;

int n, pas_max;
int v[NMAX + 1];

void citeste() {
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> v[i];
}

void init() {
    for (pas_max = 1; pas_max < n; pas_max *= 2);
    pas_max /= 2;
}

int cauta_0(int x) {
    int i, pas;

    for (i = 0, pas = pas_max; pas; pas /= 2)
        if (i + pas <= n && v[i + pas] <= x)
            i += pas;

    if (v[i] != x) return -1;
    return i;
}

int cauta_1(int x) {
    int i, pas;

    for (i = 0, pas = pas_max; pas; pas /= 2)
        if (i + pas <= n && v[i + pas] <= x)
            i += pas;

    return i;
}

int cauta_2(int x) {
    int i, pas;

    for (i = n + 1, pas = pas_max; pas; pas /= 2)
        if (i > pas && v[i - pas] >= x)
            i -= pas;

    return i;
}

int cauta(int tip, int x) {
    if (tip == 0) return cauta_0(x);
    if (tip == 1) return cauta_1(x);
    return cauta_2(x);
}

void rezolva() {
    int q, tip, x;

    f >> q;
    while(q--) {
        f >> tip >> x;
        g << cauta(tip, x) << '\n';
    }
}

int main() {
    citeste();
    init();
    rezolva();

    return 0;
}
