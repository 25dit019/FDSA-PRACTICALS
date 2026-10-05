#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int reg;
        cin >> reg;

        int index = reg % 10;
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % 10;

            if (index == start)
                break;
        }

        if (table[index] == -1)
            table[index] = reg;
        else
            cout << "Parking lot is full" << endl;
    }

    cout << "Final Table: ";

    for (int i = 0; i < 10; i++)
        cout << table[i] << " ";

    return 0;
}

