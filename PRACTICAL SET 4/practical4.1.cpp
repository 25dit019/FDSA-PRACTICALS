#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type, patient, pos;

        cin >> type;

        if (type == 1) {              
            cin >> patient;
            q.push_front(patient);
        }
        else if (type == 2) {        
            cin >> patient;
            q.push_back(patient);
        }
        else if (type == 3) {         
            cin >> patient >> pos;

            if (pos >= q.size()) {
                q.push_back(patient);
            }
            else {
                q.insert(q.begin() + pos, patient);
            }
        }

        for (int x : q)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
