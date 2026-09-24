#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full. Cannot add token "
                 << token << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;

        cout << "Joined token: " << token << endl;
        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty. Cannot serve." << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;

        front = (front + 1) % capacity;
        size--;

        if (size == 0)
            cout << "Front token: None" << endl;
        else
            cout << "Front token: " << arr[front] << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n;

    cout << "Enter maximum capacity: ";
    cin >> n;

    Queue q(n);

    int choice, token;

    do {
        cout << "\n1. Join";
        cout << "\n2. Serve";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter token number: ";
            cin >> token;
            q.join(token);
        }
        else if (choice == 2) {
            q.serve();
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