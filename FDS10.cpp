#include <iostream>
#include <stack>
#include <cctype> // To check if a character is valid

using namespace std;

// Function to check if a given character is a matching pair
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if an expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // If it's an opening delimiter, push onto the stack
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // If it's a closing delimiter, check the stack
            if (s.empty()) {
                cout << "Unbalanced: Closing bracket without matching opening." << endl;
                return false;
            }

            // Pop the stack and check for matching
            if (!isMatchingPair(s.top(), ch)) {
                cout << "Unbalanced: Mismatched pair found." << endl;
                return false;
            }

            s.pop();
        }
    }

    if (!s.empty()) {
        cout << "Unbalanced: There are unclosed opening brackets." << endl;
        return false;
    }

    return true;
}

int main() {
    string expression;

    cout << "Enter an expression to check if it is well-parenthesized: ";
    cin >> expression;

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is NOT well-parenthesized." << endl;
    }

    return 0;
}
