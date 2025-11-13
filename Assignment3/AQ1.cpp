#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;
int stackArr[MAX_CAPACITY];
int topIndex = -1;

void push(int element) {
    if (topIndex >= MAX_CAPACITY - 1) {
        cout << "[!] Stack Overflow! Cannot insert " << element << endl;
    } else {
        stackArr[++topIndex] = element;
        cout << "[+] Inserted: " << element << endl;
    }
}

int pop() {
    if (topIndex < 0) {
        cout << "[!] Stack Underflow! Nothing to pop.\n";
        return -1;
    } else {
        int poppedValue = stackArr[topIndex--];
        cout << "[-] Removed: " << poppedValue << endl;
        return poppedValue;
    }
}
bool isEmpty() {
    return topIndex < 0;
}

bool isFull() {
    return topIndex >= MAX_CAPACITY - 1;
}

int peek() {
    if (isEmpty()) {
        cout << "[!] Stack is empty, no top element.\n";
        return -1;
    } else {
        cout << "[*] Current top: " << stackArr[topIndex] << endl;
        return stackArr[topIndex];
    }
}

void printStack() {
    if (isEmpty()) {
        cout << "[*] Stack is currently empty.\n";
    } else {
        cout << ">>> Stack (Top to Bottom): ";
        for (int i = topIndex; i >= 0; --i) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, item;

    while (true) {
        cout << "\n STACK MENU: \n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display Stack\n";
        cout << "6. Peek at Top\n";
        cout << "7. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> item;
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                cout << (isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;

            case 4:
                cout << (isFull() ? "Stack is full.\n" : "Stack has space.\n");
                break;

            case 5:
                printStack();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Exiting the program. \n";
                return 0;

            default:
                cout << "[!] Invalid selection. Try again.\n";
        }
    }

    return 0;
}
