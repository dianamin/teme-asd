/*
http://www.infoarena.ro/problema/facebook
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ifstream f ("facebook.in");
ofstream g ("facebook.out");

const int NMAX = (1 << 17) + 1;
const int VALMAX = (1 << 30) + 1;

int n, k;
int sol = -1;

class HashElement{
    public:
        int key;
        int last;
        int cnt;
        int cost;
        HashElement *next;
        HashElement *prev;

        HashElement(int key, int i) {
            this->key = key;
            this->last = i;
            this->cost = i - 1;
            this->cnt = 1;
            this->next = this->prev = NULL;
        };
};


class HashTable {
    private:
        static const int MOD = 666013;
        HashElement *table[MOD];

    public:
        HashTable() {
            for (int i = 0; i < MOD; i++) table[i] = NULL;
        };

        int get_hash(int key) {
            if (key < 0) key = (-1) * key;
            return key % MOD;
        };

        void insert_element(int key, int i) {
            int line_index = get_hash(key);

            HashElement *crt = table[line_index];
            HashElement *prev = NULL;

            while(crt != NULL) {
                if (crt->key == key) return;
                prev = crt;
                crt = crt->next;
            }

            crt = new HashElement(key, i);
            crt->prev = prev;
            if (prev != NULL) prev->next = crt;

            if (table[line_index] == NULL) table[line_index] = crt;
        }

        bool find_element(int key, int i) {
            int line_index = get_hash(key);

            HashElement *crt = table[line_index];
            HashElement *prev = NULL;

            while(crt != NULL) {
                if (crt->key == key) {
                    crt->cost += i - crt->last - 1;
                    crt->last = i;
                    crt->cnt++;
                    if (crt->cnt == k) sol = crt->cost;
                    return true;
                }
                prev = crt;
                crt = crt->next;
            }

            return false;
        }
};



void rezolva() {
    HashTable *hash_table = new HashTable();
    int x;

    for (int i = 1; i <= n; i++) {
        f >> x;
        if (!hash_table->find_element(x, i)) hash_table->insert_element(x, i);
        if (sol != -1) return;
    }
}

int main() {
    f >> n >> k;
    rezolva();
    g << sol << '\n';
    return 0;
}
