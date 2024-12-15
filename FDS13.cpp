#include <iostream>
using namespace std;

// Class for Circular Queue
class CircularQueue {
private:
    int *queue;
    int front, rear, maxSize;
public:
    CircularQueue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = rear = -1; // Initialize as empty
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue function to place an order
    bool enqueue(int orderNumber) {
        if (isFull()) {
            cout << "The queue is full. Cannot accept more orders." << endl;
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        queue[rear] = orderNumber;
        cout << "Order " << orderNumber << " placed." << endl;
        return true;
    }

    // Dequeue function to serve an order
    bool dequeue() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return false;
        }

        cout << "Serving order number: " << queue[front] << endl;
        if (front == rear) { // Last element to serve
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
        return true;
    }

    // Display the current state of the queue
    void display() {
        if (isEmpty()) {
            cout << "No current orders." << endl;
            return;
        }

        cout << "Current orders in queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;

    cout << "Welcome to the Pizza Parlor Simulation!" << endl;
    cout << "Enter the maximum number of orders the system can hold: ";
    cin >> maxOrders;

    CircularQueue pizzaParlor(maxOrders);

    int choice, orderNumber;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Serve the next order" << endl;
        cout << "3. View current orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter order number to place: ";
            cin >> orderNumber;
            pizzaParlor.enqueue(orderNumber);
            break;
        case 2:
            pizzaParlor.dequeue();
            break;
        case 3:
            pizzaParlor.display();
            break;
        case 4:
            cout << "Exiting the simulation." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
