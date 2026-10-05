#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q[100];
    int front = 0, rear = -1;
    int count = 0;

    int operations;
    cin >> operations;

    while (operations--) {
        string op;
        int value;

        cin >> op;

        if (op == "join") {
            cin >> value;

            if (count == n) {
                cout << "Error: Queue is full" << endl;
            }
            else {
                rear = (rear + 1) % n;
                q[rear] = value;
                count++;

                cout << "Front: " << q[front] << endl;
            }
        }

        else if (op == "serve") {

            if (count == 0) {
                cout << "Error: Queue is empty" << endl;
            }
            else {
                front = (front + 1) % n;
                count--;

                if (count > 0)
                    cout << "Front: " << q[front] << endl;
                else
                    cout << "Queue is empty" << endl;
            }
        }
    }

    return 0;
}