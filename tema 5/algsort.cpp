/*
http://www.infoarena.ro/problema/algsort
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("algsort.in");
ofstream g ("algsort.out");

const int NMAX = 500000 + 1;

int n;
int n_heap;
int heap[NMAX], v[NMAX];

inline int fiu_drept(int x) {
    return 2 * x + 1;
}

inline int fiu_stang(int x) {
    return 2 * x;
}

inline int tata(int x) {
    return x / 2;
}

void urca(int i) {
    while (i > 1 && heap[tata(i)] > heap[i]) {
        swap(heap[tata(i)], heap[i]);
        i = tata(i);
    }
}

void insereaza(int x) {
    heap[++n_heap] = x;
    urca(n_heap);
}

void coboara(int i) {
    bool changing = true;

    while(fiu_stang(i) <= n_heap && changing) {
        changing = false;
        if ((fiu_drept(i) > n_heap || heap[fiu_drept(i)] > heap[fiu_stang(i)]) && heap[fiu_stang(i)] < heap[i]) {
            swap(heap[i], heap[fiu_stang(i)]);
            i = fiu_stang(i);
            changing = true;
        }
        else if (fiu_drept(i) <= n_heap && heap[fiu_drept(i)] < heap[i]){
            swap(heap[i], heap[fiu_drept(i)]);
            i = fiu_drept(i);
            changing = true;
        }
    }
}

int scoate_minim() {
    int x = heap[1];
    heap[1] = heap[n_heap];
    n_heap--;
    coboara(1);
    return x;
}

void citeste() {
    f >> n;

    int x;

    for (int i = 1; i <= n; i++) {
        f >> x;
        insereaza(x);
    }

}

void rezolva() {
    for (int i = 1; i <= n; i++)
        g << scoate_minim() << ' ';
    g << '\n';
}

int main() {
    citeste();
    rezolva();

    return 0;
}
