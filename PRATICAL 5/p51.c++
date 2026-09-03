#include <iostream>
#include <string>
using namespace std;
struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};
class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = NULL;
    }
    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAfter(string givenSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != givenSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found. Insertion not possible.\n";
            return;
        }
        Node* newNode = new Node(newSong);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }
    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }
    void display() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL) {
                cout << " <-> ";
            }

            temp = temp->next;
        }

        cout << endl;
        cout << "Total songs: " << countSongs() << endl;
    }
};
int main() {
    Playlist p;
    int choice;
    string song, givenSong, newSong;
    do {
        cout << "\n===== MUSIC PLAYER =====\n";
        cout << "1. Add song at beginning\n";
        cout << "2. Add song at end\n";
        cout << "3. Insert song after a song\n";
        cout << "4. Remove first song\n";
        cout << "5. Count songs\n";
        cout << "6. Display playlist\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin >> song;
            p.addBeginning(song);
            cout << "\nAfter operation:\n";
            p.display();
            break;
        case 2:
            cout << "Enter song name: ";
            cin >> song;
            p.addEnd(song);
            cout << "\nAfter operation:\n";
            p.display();
            break;
        case 3:
            cout << "Enter the song after which you want to insert: ";
            cin >> givenSong;
            cout << "Enter new song name: ";
            cin >> newSong;
            p.insertAfter(givenSong, newSong);
            cout << "\nAfter operation:\n";
            p.display();
            break;
        case 4:
            p.removeFirst();
            cout << "\nAfter operation:\n";
            p.display();
            break;
        case 5:
            cout << "Number of songs: " << p.countSongs() << endl;
            break;
        case 6:
            p.display();
            break;
        case 7:
            cout << "Exiting music player...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);
    return 0;
}