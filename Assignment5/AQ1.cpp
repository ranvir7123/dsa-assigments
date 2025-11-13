#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
};

Node* head = nullptr;

void insertAtStart(int num) {
    Node* newNode = new Node();
    newNode->value = num;
    newNode->nextNode = head;
    head = newNode;
    cout << num << " inserted at the start.\n";
}

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
    cout << num << " inserted at the end.\n";
}

void insertBeforeOrAfter(int num, int target, bool insertAfter) {
    Node* newNode = new Node();
    newNode->value = num;

    if (head == nullptr) {
        cout << "List is empty. Cannot insert.\n";
        delete newNode;
        return;
    }

    Node* currentNode = head;
    Node* previousNode = nullptr;

    while (currentNode != nullptr && currentNode->value != target) {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    if (currentNode == nullptr) {
        cout << "Target node not found.\n";
        delete newNode;
        return;
    }

    if (insertAfter) {
        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
        cout << num << " inserted after " << target << ".\n";
    } else {
        if (previousNode == nullptr) {
            newNode->nextNode = head;
            head = newNode;
        } else {
            newNode->nextNode = currentNode;
            previousNode->nextNode = newNode;
        }
        cout << num << " inserted before " << target << ".\n";
    }
}

void removeFromStart() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->nextNode;
    cout << temp->value << " removed from the start.\n";
    delete temp;
}

void removeFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->nextNode == nullptr) {
        cout << head->value << " removed from the end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* currentNode = head;
    Node* previousNode = nullptr;
    while (currentNode->nextNode != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }
    previousNode->nextNode = nullptr;
    cout << currentNode->value << " removed from the end.\n";
    delete currentNode;
}

void removeSpecificNode(int num) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* currentNode = head;
    Node* previousNode = nullptr;

    while (currentNode != nullptr && currentNode->value != num) {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    if (currentNode == nullptr) {
        cout << "Node " << num << " not found.\n";
        return;
    }

    if (previousNode == nullptr) {
        head = currentNode->nextNode;
    } else {
        previousNode->nextNode = currentNode->nextNode;
    }

    cout << "Node " << num << " removed.\n";
    delete currentNode;
}

void findNode(int num) {
    Node* currentNode = head;
    int position = 1;
    while (currentNode != nullptr) {
        if (currentNode->value == num) {
            cout << "Node " << num << " found at position " << position << ".\n";
            return;
        }
        currentNode = currentNode->nextNode;
        position++;
    }
    cout << "Node " << num << " not found.\n";
}

void showList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* currentNode = head;
    cout << "Linked List: ";
    while (currentNode != nullptr) {
        cout << currentNode->value << " ";
        currentNode = currentNode->nextNode;
    }
    cout << endl;
}

int main() {
    int option, num, target;
    bool insertAfter;

    do {
        cout << "Singly Linked List Operations\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Remove from Start\n";
        cout << "5. Remove from End\n";
        cout << "6. Remove Specific Node\n";
        cout << "7. Find a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> num;
            insertAtStart(num);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> num;
            insertAtEnd(num);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> num;
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Insert after target? (1 for yes, 0 for before): ";
            cin >> insertAfter;
            insertBeforeOrAfter(num, target, insertAfter);
            break;
        case 4:
            removeFromStart();
            break;
        case 5:
            removeFromEnd();
            break;
        case 6:
            cout << "Enter value to remove: ";
            cin >> num;
            removeSpecificNode(num);
            break;
        case 7:
            cout << "Enter value to find: ";
            cin >> num;
            findNode(num);
            break;
        case 8:
            showList();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (option != 9);

    return 0;
}
