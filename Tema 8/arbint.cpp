/*
http://www.infoarena.ro/problema/arbint
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("arbint.in");
ofstream g ("arbint.out");

const int MAX_COUNT = 100000 + 1;

int values_cnt, queries_cnt;
int segment_tree[4 * MAX_COUNT];

void update(int node, int left, int right, int position, int value) {
    if (left == right) {
        segment_tree[node] = value;
        return;
    }

    int mid = (left + right) / 2;
    int left_son = 2 * node;
    int right_son = 2 * node + 1;

    if (position <= mid)
        update(left_son, left, mid, position, value);
    else
        update(right_son, mid + 1, right, position, value);

    segment_tree[node] = max(segment_tree[left_son], segment_tree[right_son]);
}

int query(int node, int left, int right, int a, int b) {
    if (left > right)
        return -1;

    if (a <= left && right <= b) {
        return segment_tree[node];
    }

    int mid = (left + right) / 2;
    int left_son = 2 * node;
    int right_son = 2 * node + 1;

    int current_maximum = -1;

    if (a <= mid)
        current_maximum = query(left_son, left, mid, a, b);
    if (b > mid)
        current_maximum = max(current_maximum, query(right_son, mid + 1, right, a, b));

    return current_maximum;
}


void read() {
    int value;

    f >> values_cnt >> queries_cnt;

    for (int i = 1; i <= values_cnt; i++) {
        f >> value;
        update(1, 1, values_cnt, i, value);
    }
}

void solve() {
    int type, a, b;
    for (int i = 1; i <= queries_cnt; i++) {
        f >> type >> a >> b;
        if (type == 0)
            g << query(1, 1, values_cnt, a, b) << '\n';
        else
            update(1, 1, values_cnt, a, b);
    }
}

int main() {
    read();
    solve();
    return 0;
}
