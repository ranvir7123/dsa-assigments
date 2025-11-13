#include <iostream>
using namespace std;

class Queue {

    int *data;
    int capacity;
    int frontIdx, backIdx;

public:
    Queue(int size) {
        capacity = size;
        data = new int[capacity];
        frontIdx = -1;
        backIdx = -1;
    }

    ~Queue() {
        delete[] data;
    }

    bool isEmpty() {
        return (frontIdx == -1 && backIdx == -1);
    }

    bool isFull() {
        return (backIdx == capacity - 1 && frontIdx == 0) || (backIdx + 1 == frontIdx);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            frontIdx = 0;
        }
        backIdx = (backIdx + 1) % capacity;
        data[backIdx] = value;
        cout << value << " added to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << data[frontIdx] << " removed from queue" << endl;
        if (frontIdx == backIdx) {
            frontIdx = backIdx = -1;
        } else {
            frontIdx = (frontIdx + 1) % capacity;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Front element is: " << data[frontIdx] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = frontIdx;
            while (i != backIdx) {
                cout << data[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << data[backIdx] << endl;
        }
    }
};

int main() {
    int choice, value, size;
    cout << "Enter size of the queue: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number to add: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty!" << endl;
            else
                cout << "Queue is NOT Empty!" << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is Full!" << endl;
            else
                cout << "Queue is NOT Full!" << endl;
            break;
        case 7:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        
    } while (choice != 7);

    return 0;
}

