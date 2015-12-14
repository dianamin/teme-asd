/*
http://www.infoarena.ro/problema/sdo
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream f ("sdo.in");
ofstream g ("sdo.out");

const int NMAX = 3000000 + 1;

int values_count, k;
int value[NMAX];

void read() {
    f >> values_count >> k;
    for (int i = 1; i <= values_count; i++)
        f >> value[i];
}

int kth_element(int left, int right, int k) {
    if (left == right) return value[left];


    int random_position = rand() % (right - left) + left + 1;
    int pivot = value[random_position];

    int lower_value_index = left, higher_value_index = right;
    int lower_values_count;


    while (lower_value_index <= higher_value_index) {

        while (value[lower_value_index] < pivot)
            lower_value_index++;

        while (value[higher_value_index] > pivot)
            higher_value_index--;

        if (lower_value_index <= higher_value_index) {
            swap(value[lower_value_index], value[higher_value_index]);

            lower_value_index++;
            higher_value_index--;
        }
    }

    lower_values_count = higher_value_index - left + 1;

    if (lower_values_count >= k)
        return kth_element(left, higher_value_index, k);

    return kth_element(higher_value_index + 1, right, k - lower_values_count);
}

int main() {
    read();
    g << kth_element(1, values_count, k) << '\n';
    return 0;
}
