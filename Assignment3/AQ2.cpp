#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    char input[200];
    stack<char> stk;
    
    cout << "Type a string to reverse: ";
    cin >> input;

    int idx = 0;
    while (input[idx] != '\0') {
        stk.push(input[idx]);
        idx++;
    }

    string reversedText;
    while (!stk.empty()) {
        reversedText += stk.top();
        stk.pop();
    }

    cout << "Original text: " << input << endl;
    cout << "Reversed form: " << reversedText << endl;

    return 0;
}
