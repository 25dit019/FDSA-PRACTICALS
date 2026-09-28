#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;

    Node(string s) {
        song = s;
        prev = next = NULL;
    }
};

class Playlist {
    Node *head, *tail;

public:
    Playlist() {
        head = tail = NULL;
    }

    void addBegin(string s) {
        Node *n = new Node(s);

        if (head == NULL)
            head = tail = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addEnd(string s) {
        Node *n = new Node(s);

        if (head == NULL)
            head = tail = n;
        else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    void insertAfter(string key, string s) {
        Node *temp = head;

        while (temp != NULL && temp->song != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found\n";
            return;
        }

        Node *n = new Node(s);

        n->next = temp->next;
        n->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = n;
        else
            tail = n;

        temp->next = n;
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void display() {
        Node *temp = head;

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void count() {
        int c = 0;
        Node *temp = head;

        while (temp != NULL) {
            c++;
            temp = temp->next;
        }

        cout << "Total Songs: " << c << endl;
    }
};

int main() {
    Playlist p;
    int choice;
    string song, key;

    do {
        cout << "\n1. Add Beginning";
        cout << "\n2. Add End";
        cout << "\n3. Insert After";
        cout << "\n4. Remove First";
        cout << "\n5. Count Songs";
        cout << "\n6. Display Playlist";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song: ";
                cin >> song;
                p.addBegin(song);
                p.display();
                break;

            case 2:
                cout << "Enter song: ";
                cin >> song;
                p.addEnd(song);
                p.display();
                break;

            case 3:
                cout << "Enter existing song: ";
                cin >> key;
                cout << "Enter new song: ";
                cin >> song;
                p.insertAfter(key, song);
                p.display();
                break;

            case 4:
                p.removeFirst();
                p.display();
                break;

            case 5:
                p.count();
                break;

            case 6:
                p.display();
                break;

            case 7:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 7);

    return 0;
}