#include <iostream>
#include <queue> // Using C++'s built-in queue container
using namespace std;

// Function to add a job to the queue
void addJob(queue<int>& jobQueue, int jobId, int maxSize) {
    if (jobQueue.size() >= maxSize) {
        cout << "Job queue is full. Cannot add new job." << endl;
    } else {
        jobQueue.push(jobId);
        cout << "Job with ID " << jobId << " added to the queue." << endl;
    }
}

// Function to delete a job from the queue
void deleteJob(queue<int>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "Job queue is empty. No job to delete." << endl;
    } else {
        cout << "Processing job with ID " << jobQueue.front() << endl;
        jobQueue.pop();
    }
}

// Function to display the current jobs in the queue
void displayQueue(queue<int>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "Job queue is empty." << endl;
    } else {
        cout << "Current jobs in the queue: ";
        queue<int> tempQueue = jobQueue; // Copy queue to traverse
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
}

int main() {
    queue<int> jobQueue; // Standard queue
    int choice, jobId;
    const int maxQueueSize = 5; // Fixed maximum size of the queue

    do {
        // Menu-driven interface
        cout << "\nJob Queue Simulation Menu:" << endl;
        cout << "1. Add job to queue" << endl;
        cout << "2. Process (delete) a job from queue" << endl;
        cout << "3. Display current queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job ID to add to the queue: ";
                cin >> jobId;
                addJob(jobQueue, jobId, maxQueueSize);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayQueue(jobQueue);
                break;
            case 4:
                cout << "Exiting the simulation." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
