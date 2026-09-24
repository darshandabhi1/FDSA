#include <iostream>
#include <string>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main() {
    string infix, postfix = "";
    char s[100];
    int top = -1;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            top++;
            s[top] = ch;
        }
        else if (ch == ')') {
            while (top != -1 && s[top] != '(') {
                postfix += s[top];
                top--;
            }

            if (top != -1 && s[top] == '(') {
                top--;
            }
        }
        else {
            while (top != -1 && s[top] != '(' &&
                   priority(s[top]) >= priority(ch)) {
                postfix += s[top];
                top--;
            }

            top++;
            s[top] = ch;
        }
    }

    while (top != -1) {
        postfix += s[top];
        top--;
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}