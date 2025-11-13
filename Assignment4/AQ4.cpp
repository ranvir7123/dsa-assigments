#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    queue<char> q;
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        count[c - 'a']++;
        q.push(c);

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }

    return 0;
}
