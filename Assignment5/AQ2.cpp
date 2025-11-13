#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
};

Node* head = nullptr;

void insertAtEnd(int num) {
    Node* newNode = new Node();
    newNode->value = num;
    newNode->nextNode = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->nextNode != nullptr) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = newNode;
    }
}

int countOccurrences(int key) {
    int count = 0;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->value == key) {
            count++;
        }
        currentNode = currentNode->nextNode;
    }
    return count;
}

void deleteAllOccurrences(int key) {
    while (head != nullptr && head->value == key) {
        Node* temp = head;
        head = head->nextNode;
        delete temp;
    }

    Node* currentNode = head;
    Node* previousNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->value == key) {
            previousNode->nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = previousNode->nextNode;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
    }
}

void displayList() {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->value;
        if (currentNode->nextNode != nullptr) {
            cout << " -> ";
        }
        currentNode = currentNode->nextNode;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements of the linked list:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Enter the key to count and delete: ";
    cin >> key;

    int count = countOccurrences(key);
    cout << "Count of key " << key << ": " << count << endl;

    deleteAllOccurrences(key);

    cout << "Updated Linked List: ";
    displayList();

    return 0;
}
