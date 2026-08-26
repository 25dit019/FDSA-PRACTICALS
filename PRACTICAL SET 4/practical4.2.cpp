#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> q;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push_back(x);
    }

  
    cin >> x;

    auto it = find(q.begin(), q.end(), x);

    if (it != q.end())
        q.erase(it);

    cout << "Forward: ";
    for (int p : q)
        cout << p << " ";
    cout << endl;

  
    cout << "Reverse: ";
    for (auto it = q.rbegin(); it != q.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
