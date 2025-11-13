#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;
queue<int> q;

void stackPushTwoQueues(int element) {
    q2.push(element);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void stackPopTwoQueues() {
    if(q1.empty()) {
        cout << "The stack is empty" << endl;
        return;
    }
    cout << q1.front() << " removed from stack" << endl;
    q1.pop();
}

int stackTopTwoQueues() {
    if(q1.empty()) {
        cout << "The stack is empty" << endl;
        return -1;
    }
    return q1.front();
}

void stackDisplayTwoQueues() {
    if(q1.empty()) {
        cout << "The stack is empty" << endl;
        return;
    }
    queue<int> tempQueue = q1;
    cout << "Stack contents: ";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

void stackPushOneQueue(int element) {
    int size = q.size();
    q.push(element);
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void stackPopOneQueue() {
    if(q.empty()) {
        cout << "The stack is empty" << endl;
        return;
    }
    cout << q.front() << " removed from stack" << endl;
    q.pop();
}

int stackTopOneQueue() {
    if(q.empty()) {
        cout << "The stack is empty" << endl;
        return -1;
    }
    return q.front();
}

void stackDisplayOneQueue() {
    if(q.empty()) {
        cout << "The stack is empty" << endl;
        return;
    }
    queue<int> tempQueue = q;
    cout << "Stack contents: ";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

int main() {
    int stackType, choice, value;
    cout << "Select stack implementation:\n1. Using Two Queues\n2. Using One Queue\nEnter choice: ";
    cin >> stackType;

    if(stackType == 1) {
        do {
            cout << "Stack (Two Queues) Options\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nSelect option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    stackPushTwoQueues(value);
                    break;
                case 2:
                    stackPopTwoQueues();
                    break;
                case 3:
                    cout << "Top value: " << stackTopTwoQueues() << endl;
                    break;
                case 4:
                    stackDisplayTwoQueues();
                    break;
                case 5:
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Invalid selection" << endl;
            }
        } while (choice != 5);
    } else if(stackType == 2) {
        do {
            cout << "Stack (One Queue) Options\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nSelect option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    stackPushOneQueue(value);
                    break;
                case 2:
                    stackPopOneQueue();
                    break;
                case 3:
                    cout << "Top value: " << stackTopOneQueue() << endl;
                    break;
                case 4:
                    stackDisplayOneQueue();
                    break;
                case 5:
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Invalid selection" << endl;
            }
        } while (choice != 5);
    } else {
        cout << "Invalid stack implementation choice" << endl;
    }
    return 0;
}
