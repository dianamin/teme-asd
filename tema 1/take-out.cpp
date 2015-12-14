/*
http://main.edu.pl/en/archive/oi/20/usu
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define c first
#define b second

//ifstream f ("date.in");

const int NMAX = 1000000 + 1;

int n, k, top;

char st[NMAX];
int ind[NMAX];
int cs[NMAX];
vector < vector <int> > sol;


void solve() {
    char c;
    int b_s = 0, c_s = 0, top2;
    top = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        st[++top] = c;
        ind[top] = i;
        if (c == 'c') cs[top] = cs[top - 1] + 1;
        else cs[top] = cs[top - 1];

        if (top <= k) {
            continue;
        }


        if (cs[top] - cs[top - k - 1] == 1) {
            vector <int> current_sol;
            for (int j = top - k; j <= top; j++)
                current_sol.push_back(ind[j]);
            sol.push_back(current_sol);
            top -= (k + 1);
        }
    }
}

void write() {
    int sol_cnt = sol.size();
    for (int i = 0; i < sol_cnt; i++, cout << '\n')
        for (int j = 0; j <= k; j++)
            cout << sol[i][j] << ' ';
}

int main() {
    cin >> n >> k;
    solve();
    sort(sol.begin(), sol.end());
    write();
}
