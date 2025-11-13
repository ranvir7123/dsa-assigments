#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has an odd number of elements, cannot interleave!" << endl;
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

   
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        q.push(num);
    }

    cout << "Original Queue: ";
    displayQueue(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    displayQueue(q);

    return 0;
}
