#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    int operations;
    cin >> operations;

    while (operations--) {
        string op, name;
        cin >> op;

        if (op == "arrive") {
            cin >> name;

            Node* newNode = new Node;
            newNode->name = name;
            newNode->next = NULL;

            if (rear == NULL) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Front: " << front->name << endl;
        }

        else if (op == "attend") {

            if (front == NULL) {
                cout << "Error: Ward is empty" << endl;
            }
            else {
                Node* temp = front;
                front = front->next;

                if (front == NULL)
                    rear = NULL;

                delete temp;

                if (front != NULL)
                    cout << "Front: " << front->name << endl;
                else
                    cout << "Ward is empty" << endl;
            }
        }
    }

    return 0;
}