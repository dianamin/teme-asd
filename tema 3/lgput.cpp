/*
http://www.infoarena.ro/problema/lgput
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("lgput.in");
ofstream g ("lgput.out");

const int MOD = 1999999973;

int n, p;

unsigned long long putere(unsigned long long x, int p) {
    if (p == 0) return 1;
    unsigned long long aux = putere(x, p / 2);
    aux = (aux * aux) % MOD;
    if (p % 2 == 0) return aux;
    return (aux * x) % MOD;
}

int main() {
    f >> n >> p;
    g << putere(n, p) << '\n';
    return 0;
}
