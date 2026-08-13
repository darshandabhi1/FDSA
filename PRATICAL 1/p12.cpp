#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    int books[n];

    cout << "Enter Book IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << "Book IDs borrowed more than once are: ";

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (books[i] == books[j]) {
                count++;
            }
        }

        bool alreadyPrinted = false;
        for (int k = 0; k < i; k++) {
            if (books[k] == books[i]) {
                alreadyPrinted = true;
                break;
            }
        }

        if (count > 1 && !alreadyPrinted) {
            cout << books[i] << " ";
        }
    }

    return 0;
}