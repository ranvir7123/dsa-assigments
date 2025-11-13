#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    string infixInput;
    cout << "Input infix expression: ";
    cin >> infixInput;

    stack<char> operators;
    string postfixResult;

    for (size_t i = 0; i < infixInput.length(); i++) {
        char ch = infixInput[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfixResult += ch;
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfixResult += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
        else {
            int prec_ch = getPrecedence(ch);
            while (!operators.empty() && getPrecedence(operators.top()) >= prec_ch) {
                postfixResult += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfixResult += operators.top();
        operators.pop();
    }

    cout << "Converted postfix: " << postfixResult << "\n";
    return 0;
}
