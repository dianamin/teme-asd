/*
http://www.infoarena.ro/problema/slidingwindow
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("slidingwindow.in");
ofstream g ("slidingwindow.out");

struct nod {
    pair <int, int> valoare;
    int inaltime;
    nod *stanga;
    nod *dreapta;

    nod (pair <int, int> x) {
        this->valoare = x;
        stanga = dreapta = NULL;
        inaltime = 1;
    }
};

const int NMAX = 1000000 + 1;

int n, d;
int sol;
int v[NMAX];

int inaltime(nod *p) {
    if (p == NULL) return 0;
    return p->inaltime;
}

int factor(nod * p) {
    return inaltime(p->dreapta) - inaltime(p->stanga);
}

void calculeaza_inaltime(nod *p) {
    if (p == NULL) return;
    p->inaltime = 1 + max(inaltime(p->stanga), inaltime(p->dreapta));
}


nod* roteste_dreapta(nod* p) {
    nod* q = p->stanga;
    p->stanga = q->dreapta;
    q->dreapta = p;
    calculeaza_inaltime(p);
    calculeaza_inaltime(q);
    return q;
}

nod* roteste_stanga(nod* q) {
    nod *p = q->dreapta;
    q->dreapta = p->stanga;
    p->stanga = q;
    calculeaza_inaltime(q);
    calculeaza_inaltime(p);
    return p;
}

nod *balanseaza(nod *p) {
    calculeaza_inaltime(p);

    if (factor(p) == 2) {
        if (factor(p->dreapta) < 0) p->dreapta = roteste_dreapta(p->dreapta);
        return roteste_stanga(p);
    }
    if (factor(p) == -2) {
        if (factor(p->stanga) > 0) p->stanga = roteste_stanga(p->stanga);
        return roteste_dreapta(p);
    }
    return p;
}


nod* insereaza(nod* p, pair <int, int> x) {
    if (p == NULL) return new nod (x);
    sol = min(sol, abs(x.first - p->valoare.first));

    if (x < p->valoare)
        p->stanga  = insereaza(p->stanga, x);
    else
        p->dreapta = insereaza(p->dreapta, x);

    return balanseaza(p);
}


nod* cauta_minim(nod *p) {
    if (p->stanga == NULL) return p;
    return cauta_minim(p->stanga);
}


nod *sterge_minim(nod *&p) {
    if (p->stanga == 0) return p->dreapta;
    p->stanga = sterge_minim(p->stanga);
    return balanseaza(p);
}


nod *sterge(nod * &p, pair <int, int> x) {
    if (p == NULL) return 0;
    if (x < p->valoare)
        p->stanga = sterge(p->stanga, x);
    else if (x > p->valoare)
        p->dreapta = sterge(p->dreapta, x);
    else {
        nod *q = p->stanga;
        nod *r = p->dreapta;
        delete p;
        if (r == NULL) return q;
        nod* minim = cauta_minim(r);
        minim->dreapta = sterge_minim(r);
        minim->stanga = q;
        return balanseaza(minim);
    }

    return balanseaza(p);
}

nod *avl;

void rezolva() {
    pair <int, int> p;

    sol = (1 << 30);

    f >> n >> d;
    for (int i = 1; i <= d; i++) {
        f >> v[i];
        cout << v[i] << ' ';
        p.first = v[i];
        p.second = i;
        avl = insereaza(avl, p);
    }

    for (int i = d + 1; i <= n; i++) {
        p.first = v[i - d];
        p.second = i - d;
        avl = sterge(avl, p);

        f >> v[i];
        p.first = v[i];
        p.second = i;
        avl = insereaza(avl, p);
    }

    g << sol << '\n';
}

int main() {
    rezolva();

    return 0;
}
