/*
    http://www.infoarena.ro/problema/hashuri
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("hashuri.in");
ofstream g ("hashuri.out");

class HashElement{
    public:
        int key;
        int value;
        HashElement *next;
        HashElement *prev;

        HashElement(int key) {
            this->key = key;
            this->value = 1;
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

        void insert_element(int key) {
            int line_index = get_hash(key);

            HashElement *crt = table[line_index];
            HashElement *prev = NULL;

            while(crt != NULL) {
                if (crt->key == key) return;
                prev = crt;
                crt = crt->next;
            }

            //crt e NULL
            crt = new HashElement(key);
            crt->prev = prev;
            if (prev != NULL) prev->next = crt;

            if (table[line_index] == NULL) table[line_index] = crt;
        }

        bool find_element(int key) {
            int line_index = get_hash(key);

            HashElement *crt = table[line_index];
            HashElement *prev = NULL;

            while(crt != NULL) {
                if (crt->key == key) return true;
                prev = crt;
                crt = crt->next;
            }

            return false;
        }

        void delete_element(int key) {
            int line_index = get_hash(key);

            HashElement *crt = table[line_index];
            HashElement *prev = NULL;
            HashElement *next = NULL;

            while(crt != NULL) {
                if (crt->key == key) {
                    next = crt->next;
                    if (next != NULL) next->prev = prev;
                    if (prev != NULL) prev->next = next;
                    else {
                        table[line_index] = next;
                    }
                    delete(crt);
                    return;
                }
                prev = crt;
                crt = crt->next;
            }
        };
};


int main() {
    int n, op, key;

    HashTable *hash_table = new HashTable();

    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> op >> key;
        if (op == 1) hash_table->insert_element(key);
        else if (op == 2) hash_table->delete_element(key);
        else g << hash_table->find_element(key) << '\n';
    }

    return 0;
}n
