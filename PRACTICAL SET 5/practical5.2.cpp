#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular {
    Node* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void join(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;
        }

        display();
    }

    void leave(string name) {
        if (head == NULL) {
            cout << "Circle is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->name == name) {
                break;
            }

            temp = temp->next;

        } while (temp != head);

        if (temp->name != name) {
            cout << "Student not found" << endl;
            return;
        }

        if (temp->next == temp) {
            head = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head) {
                head = temp->next;
            }
        }

        delete temp;

        display();
    }

    void display() {
        if (head == NULL) {
            cout << "Circle is empty" << endl;
            return;
        }

        Node* temp = head;

        cout << "Circle: ";

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    DoublyCircular c;

    c.join("A");
    c.join("B");
    c.join("C");
    c.join("D");

    c.leave("B");
    c.leave("A");

    c.display();

    return 0;
}