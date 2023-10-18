#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string &equation) {
    stack<char> brackets;

    for (size_t i = 0; i < equation.length(); i++) {
        char ch = equation[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) {
                return false;  // Unbalanced: no corresponding opening bracket
            }
            char top = brackets.top();
            brackets.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Mismatched brackets
            }
        }
    }

    return brackets.empty();  // Equation is balanced if the stack is empty
}

int main() {
    string equation;
    cout << "Enter an equation: ";
    cin >> equation;

    if (isBalanced(equation)) {
        cout << "The equation is balanced." << endl;
    } else {
        cout << "The equation is unbalanced." << endl;
    }

    return 0;
}

