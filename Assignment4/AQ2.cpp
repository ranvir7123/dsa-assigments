#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queueArray;
    int capacity;
    int frontIdx, backIdx;

public:
    CircularQueue(int size) {
        capacity = size;
        queueArray = new int[capacity];
        frontIdx = -1;
        backIdx = -1;
    }

    ~CircularQueue() {
        delete[] queueArray;
    }

    bool isEmpty() {
        return (frontIdx == -1 && backIdx == -1);
    }

    bool isFull() {
        return ((backIdx + 1) % capacity == frontIdx);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            frontIdx = backIdx = 0;
        } else {
            backIdx = (backIdx + 1) % capacity;
        }
        queueArray[backIdx] = value;
        cout << value << " added to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << queueArray[frontIdx] << " removed from queue" << endl;
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
            cout << "Front element is: " << queueArray[frontIdx] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = frontIdx;
            while (true) {
                cout << queueArray[i] << " ";
                if (i == backIdx) break;
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }
};

int main() {
    int choice, value, size;
    cout << "Enter size of the circular queue: ";
    cin >> size;

    CircularQueue q(size);

    do {
        cout << "\nCircular Queue Menu\n";
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
        }
    } while (choice != 7);

    return 0;
}
