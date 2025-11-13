#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string postfixExp;
    cout << "Enter postfix expression: ";
    cin >> postfixExp;
    stack<int> s;
    for (int i = 0; i < postfixExp.length(); i++) {
        char ch = postfixExp[i];
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }
    cout << "Result: " << s.top() << endl;
    return 0;
}
