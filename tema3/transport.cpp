/*
http://www.infoarena.ro/problema/transport
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("transport.in");
ofstream g ("transport.out");

int n, k;
int sum;
int v[16002];

void citeste () {
    f >> n >> k;
    for (int i = 1; i <= n; i++) {
        f >> v[i];
        sum += v[i];
    }
}

bool ok (int x) {
    int crt = 0, nr = 1;
    for (int i = 1; i <= n; i++) {
        if (crt + v[i] > x) {
            nr++;
            crt = 0;
            i--;
            if (nr > k) return false;
        }
        else crt += v[i];
    }
    return true;
}

void rezolva () {
    int st = 1, dr = sum, mij;
    int sol = sum;
    while (st <= dr) {
        mij = (st + dr) / 2;
        if (ok(mij)) {
            dr = mij - 1;
            sol = min (sol, mij);
        }
        else st = mij + 1;
    }
    g << sol << '\n';
}

int main () {
    citeste ();
    rezolva ();
    return 0;
}
