/*
    http://www.infoarena.ro/problema/heapuri
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("heapuri.in");
ofstream g ("heapuri.out");

const int NMAX = 200000 + 1;
const int INF = 1 << 30;

int n, inaltime;
int v[NMAX], heap[2 * NMAX], pozitie[NMAX];

inline int parinte(int nod) {
    return nod / 2;
}

inline int fiu_stang(int nod) {
    return 2 * nod;
}

inline int fiu_drept(int nod) {
    return 2 * nod + 1;
}

inline void schimba(int x, int y) {
    pozitie[heap[x]] = y;
    pozitie[heap[y]] = x;
    swap(heap[x], heap[y]);
}

void urca(int poz) {
    while (1 < poz && v[heap[parinte(poz)]] > v[heap[poz]]) {
        schimba(poz, parinte(poz));
        poz = parinte(poz);
    }
}

void coboara(int poz) {
    while(fiu_stang(poz) <= inaltime) {
        if (fiu_drept(poz) >= inaltime || v[heap[fiu_stang(poz)]] < v[heap[fiu_drept(poz)]]) {
            schimba(poz, fiu_stang(poz));
            poz = fiu_stang(poz);
        }
        else {
            schimba(poz, fiu_drept(poz));
            poz = fiu_drept(poz);
        }
    }
}

void sterge(int x) {
    int poz = pozitie[x];
    heap[poz] = heap[inaltime];
    inaltime--;
    if (v[heap[parinte(poz)]] > v[heap[poz]]) urca(poz);
    else coboara(poz);
}

void insereaza() {
        heap[++inaltime] = n;
        pozitie[n] = inaltime;
        urca(pozitie[n]);
}

void scrie_heap() {
    for (int i = 1; i <= inaltime; i++) cout << heap[i] << ' ';
    cout << endl;
}


void rezolva() {
    int t, a, q;
    f >> q;
    while(q--) {
        f >> t;
        if (t == 1) {
            f >> v[++n];
            insereaza();
        }
        else if (t == 2) {
            f >> a;
            sterge(a);
        }
        else g << v[heap[1]] << '\n';
    }

}
int main() {
    rezolva();
    return 0;
}
