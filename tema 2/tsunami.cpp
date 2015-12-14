/*
http://www.infoarena.ro/problema/tsunami
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f ("tsunami.in");
ofstream g ("tsunami.out");

const int INF = 1001;
const int NMAX = 1000, MMAX = 1000;

int n, m, h;
int start = 1, sfarsit;

int harta[NMAX + 3][MMAX + 3];
bool viz[NMAX + 3][NMAX + 3];
int di[] = {-1, 0, 1,  0};
int dj[] = { 0, 1, 0, -1};

pair <int, int> Q[NMAX * NMAX + 2];

inline void push(int i, int j) {
    sfarsit++;
    Q[sfarsit] = make_pair(i, j);
}

inline void pop() {
    start++;
}

void citeste() {
    f >> n >> m >> h;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f >> harta[i][j];
        }
}

bool e_tsunami(int i, int j) {
    for (int k = 0; k < 4; k++)
        if (harta[i + di[k]][j + dj[k]] != 0)
            return true;
    return false;
}

void baga(int i, int j) {
    if (harta[i][j] != 0) return;
    if (viz[i][j] == true) return;

    push(i, j);
    viz[i][j] = true;
}

void init() {
    for (int i = 1; i <= n; i++) {
        baga(i, 1);
        baga(i, m);
    }
    for (int j = 1; j <= m; j++) {
        baga(1, j);
        baga(n, j);
    }
}

void bordeaza() {
    for (int i = 0; i <= n + 1; i++) {
        harta[i][0] = INF;
        harta[i][m + 1] = INF;
    }
    for (int j = 0; j <= m + 1; j++) {
        harta[0][j] = INF;
        harta[n + 1][j] = INF;
    }
}

void rezolva() {
    int sol = 0;
    pair <int, int> p;
    int i, j, next_i, next_j;

    while (start <= sfarsit) {
        p = Q[start];
        pop();

        i = p.first;
        j = p.second;

        for (int k = 0; k < 4; k++) {
            next_i = i + di[k];
            next_j = j + dj[k];

            if (viz[next_i][next_j] == false && harta[next_i][next_j] < h) {
                viz[next_i][next_j] = true;
                push(next_i, next_j);
                if (harta[next_i][next_j] > 0) sol++;
            }
        }
    }

    g << sol;
}

int main() {
    citeste();
    bordeaza();
    init();
    rezolva();
    return 0;
}
