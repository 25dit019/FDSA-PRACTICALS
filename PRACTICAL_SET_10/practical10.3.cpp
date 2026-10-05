#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);

        int index = h1;
        int count = 0;

        while (table[index] != -1 && count < 10) {
            count++;
            index = (h1 + count * h2) % 10;
        }

        if (count < 10)
            table[index] = id;
        else
            cout << "Hash table is full" << endl;
    }

    cout << "Final Table: ";

    for (int i = 0; i < 10; i++)
        cout << table[i] << " ";

    return 0;
}
