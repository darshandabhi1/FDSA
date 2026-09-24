#include <iostream>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class Browser {
    Node* top;

public:
    Browser(string page) {
        top = new Node(page);
    }

    void visit(string page) {
        Node* newNode = new Node(page);
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }

    void back() {
        if (top->next == NULL) {
            cout << "Error: No previous page available." << endl;
            cout << "Current page: " << top->page << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        cout << "Back button pressed." << endl;
        cout << "Current page: " << top->page << endl;

        delete temp;
    }
};

int main() {
    string firstPage;

    cout << "Enter first page: ";
    cin >> firstPage;

    Browser browser(firstPage);

    int choice;
    string page;

    do {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            browser.visit(page);
        }
        else if (choice == 2) {
            browser.back();
        }
        else if (choice == 3) {
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 3);

    return 0;
}