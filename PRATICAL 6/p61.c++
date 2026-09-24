#include <iostream>
using namespace std;
class TrayStack {
    int *stack;
    int top;
    int capacity;
public:
    TrayStack(int n) {
        capacity = n;
        stack = new int[capacity];
        top = -1;
    }
    void push(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full. Cannot place tray " << tray << endl;
            return;
        }
        top++;
        stack[top] = tray;
        cout << "Placed tray: " << tray << endl;
        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << stack[top] << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty. Cannot take tray." << endl;
            return;
        }
        cout << "Taken tray: " << stack[top] << endl;
        top--;
        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << stack[top] << endl;
    }
    ~TrayStack() {
        delete[] stack;
    }
};
int main() {
    int n;
    cout << "Enter maximum number of trays: ";
    cin >> n;
    TrayStack s(n);
    int choice, tray;
    do {
        cout << "\n1. Place Tray";
        cout << "\n2. Take Tray";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
        }
        else if (choice == 2) {
            s.pop();
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