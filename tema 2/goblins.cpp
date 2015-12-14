/*
WA
https://open.kattis.com/problems/goblingardenguards
*/

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cmath>

using namespace std;


const int NMAX = 100000 + 1;

int n, m;
map <int, set <int> > punct;

void read() {
    cin >> n;

    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        punct[x].insert(y);
    }
}

inline int absolute(int x) {
    if (x < 0) return (-1) * x;
    return x;
}

void solve() {
    int x, y, r;

    int low_x, low_y, high_x, high_y, delta_x, delta_y;

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> r;

        low_x = max(x - r, 0);
        high_x = x + r;

        for (int a = low_x; a <= high_x; a++) {
            delta_x = absolute(a - x);
            delta_y = 1.0 * sqrt(r * r - delta_x * delta_x);

            low_y = max(0, y - delta_y);
            high_y = y + delta_y;

            set <int> :: iterator it_low, it_high;

            it_low = punct[a].lower_bound(low_y);
            it_high = punct[a].upper_bound(high_y);

            if (it_high != punct[a].end())
                if ((*it_high) == high_y)
                    it_high--;

            punct[a].erase(it_low, it_high);
        }
    }

    map <int, set <int> > :: iterator i;

    int sol = 0;
    for (i = punct.begin(); i != punct.end(); i++) {
        sol += (*i).second.size();
    }
    cout << sol << '\n';
}

int main() {
    read();
    solve();
}
