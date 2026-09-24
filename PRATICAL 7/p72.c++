#include <iostream>
using namespace std;

class Node {
public:
    int patient;
    Node* next;

    Node(int p) {
        patient = p;
        next = NULL;
    }
};

class PatientQueue {
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient arrived: " << patient << endl;
        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: No patients waiting." << endl;
            cout << "Front patient: None" << endl;
            return;
        }

        Node* temp = front;

        cout << "Patient attended: " << front->patient << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

        if (front == NULL)
            cout << "Front patient: None" << endl;
        else
            cout << "Front patient: " << front->patient << endl;
    }
};

int main() {
    PatientQueue q;

    int choice;
    int patient;

    do {
        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient number: ";
            cin >> patient;
            q.arrive(patient);
        }
        else if (choice == 2) {
            q.attend();
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