/*
http://www.infoarena.ro/problema/deque
*/

#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f ("deque.in");
ofstream g ("deque.out");

const int MAX_N = 5000000;

int n, k;
int value[MAX_N + 1];
deque <int> DQ;

void solve() {
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        f >> value[i];

        while(!DQ.empty() && value[DQ.back()] > value[i])
            DQ.pop_back();
        DQ.push_back(i);

        if (DQ.front() == i - k) DQ.pop_front();
        if (i >= k) sum += value[DQ.front()];
    }

    g << sum << '\n';
}

int main() {
    f >> n >> k;
    solve();
    return 0;
}
