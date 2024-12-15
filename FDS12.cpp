#include <iostream>
using namespace std;

// Node class to represent a single item in the priority queue
template <typename T>
class Node {
public:
    T data;
    int priority;
    Node* next;

    Node(T d, int p) : data(d), priority(p), next(nullptr) {}
};

// PriorityQueue class using an in-order list
template <typename T>
class PriorityQueue {
private:
    Node<T>* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a new item into the priority queue
    void insert(T data, int priority) {
        Node<T>* newNode = new Node<T>(data, priority);

        // If the queue is empty, insert the first element
        if (!head) {
            head = newNode;
            return;
        }

        // Insert in order based on priority
        if (priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Inserted: " << data << " with priority " << priority << endl;
    }

    // Remove and return the highest priority item
    T remove() {
        if (!head) {
            throw runtime_error("Priority queue is empty.");
        }

        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;

        cout << "Removed item with priority: " << temp->priority << endl;
        return data;
    }

    // Display the queue (for debugging)
    void display() {
        if (!head) {
            cout << "Priority queue is empty." << endl;
            return;
        }

        Node<T>* current = head;
        cout << "Priority queue contents (priority descending):" << endl;
        while (current) {
            cout << "[" << current->data << ", priority " << current->priority << "] ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<string> pq;

    // Insert items into the priority queue
    pq.insert("Pizza", 3);
    pq.insert("Burger", 2);
    pq.insert("Pasta", 5);
    pq.insert("Tacos", 4);
    pq.insert("Sandwich", 1);

    pq.display();

    // Remove the highest priority items
    cout << "\nServing items in order of priority:" << endl;
    cout << pq.remove() << endl;
    cout << pq.remove() << endl;
    pq.display();
    
    return 0;
}
