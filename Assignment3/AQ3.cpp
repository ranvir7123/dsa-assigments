#include <iostream>
#include <stack>
using namespace std;

int main() {
    string expr;
    cout << "Input your expression: ";
    cin >> expr;

    stack<char> charStack;
    bool balanced = true;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            charStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (charStack.empty()) {
                balanced = false;
                break;
            }
            char topChar = charStack.top();
            charStack.pop();
            if ((ch == ')' && topChar != '(') || 
                (ch == '}' && topChar != '{') || 
                (ch == ']' && topChar != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (!charStack.empty())
        balanced = false;

    if (balanced)
        cout << "Expression is balanced\n";
    else
        cout << "Expression is not balanced\n";

    return 0;
}
