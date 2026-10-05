#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cin >> code;

        int index = code % 10;
        table[index].push_back(code);
    }

    for (int i = 0; i < 10; i++) {
        cout << i << ": ";

        for (int j = 0; j < table[i].size(); j++)
            cout << table[i][j] << " ";

        cout << endl;
    }

    return 0;
}
