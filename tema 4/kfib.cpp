/*
http://www.infoarena.ro/problema/kfib
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("kfib.in");
ofstream g ("kfib.out");

const int MOD = 666013;
const int M_SIZE = 2;

int M[M_SIZE][M_SIZE];
int M2[M_SIZE][M_SIZE];

void init() {
    M[0][0] = 0;
    M[0][1] = M[1][0] = M[1][1] = 1;

    M2[0][0] = M2[1][1] = 1;
}

void inmulteste(int M2[][M_SIZE], int M[][M_SIZE]) {
    int aux[M_SIZE][M_SIZE];

    for (int i = 0; i < M_SIZE; i++)
        for (int j = 0; j < M_SIZE; j++) {
            aux[i][j] = 0;

            for (int k = 0; k < M_SIZE; k++) {
                aux[i][j] = (aux[i][j] + ((1LL * M2[i][k] * M[k][j]) % MOD)) % MOD;
            }
        }

    for (int i = 0; i < M_SIZE; i++)
        for (int j = 0; j < M_SIZE; j++)
            M2[i][j] = aux[i][j];
}

int al_k_lea_termen(int k) {
    if (k == 0) return 0;
    if (k < 3) return 1;

    int n = k - 2;
    for (int p = 0; (1LL << p) <= n; p++) {
        if ((n & (1 << p)) != 0) {
            inmulteste(M2, M);
        }
        inmulteste(M, M);
    }

    int rez = (M2[1][0] + M2[1][1]) % MOD;
    return rez;
}

int main() {
    init();
    int k;
    f >> k;

    g << al_k_lea_termen(k) << '\n';

    return 0;
}

