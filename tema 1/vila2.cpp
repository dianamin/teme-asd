/*
http://www.infoarena.ro/problema/vila2
*/


#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f("vila2.in");
ofstream g("vila2.out");

const int NMAX = 100000 + 1;
int n, k;
int v[NMAX];
deque <int> dmax, dmin;

void rezolva() {
    int x, sol = 0;
    for (int i = 1; i <= n; i++) {
        f >> x;
        v[i] = x;
        while (!dmax.empty() && v[dmax.back()] < x) dmax.pop_back();
        while (!dmin.empty() && v[dmin.back()] > x) dmin.pop_back();
        dmax.push_back(i);
        dmin.push_back(i);
        if (dmax.front() == i - k) dmax.pop_front();
        if (dmin.front() == i - k) dmin.pop_front();
        if (i >= k) sol = max(v[dmax.front()] - v[dmin.front()], sol);
    }
    g << sol << '\n';
}

int main() {
    f >> n >> k;
    k++;
    rezolva();
}
