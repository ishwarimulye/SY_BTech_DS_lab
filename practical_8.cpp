/*Printer Spooler (Circular Queue):
In a multi-user environment, printers often use a circular queue to manage print jobs. Each print job is added to the queue, 
and the printer processes them in the order they arrive. Once a print job is completed,
 it moves out of the queue, and the next job is processed, efficiently managing the flow of print tasks. 
 Implement the Printer Spooler system using a circular queue without using built-in queues.*/
#include <iostream>
#define SIZE 5
using namespace std;

class PrinterSpooler {
    int front, rear;
    int printQueue[SIZE];

public:
    PrinterSpooler() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add a new print job
    void addJob(int jobID) {
        if (isFull()) {
            cout << "Printer queue is full. Cannot add new job." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % SIZE;
            }
            printQueue[rear] = jobID;
            cout << "Print job " << jobID << " added to the queue." << endl;
        }
    }

    // Process the current print job
    void processJob() {
        if (isEmpty()) {
            cout << "No jobs in queue to process." << endl;
        } else {
            cout << "Processing print job " << printQueue[front] << "..." << endl;
            if (front == rear) {
                // Queue becomes empty
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
        }
    }

    // Display current queue status
    void displayQueue() {
        if (isEmpty()) {
            cout << "No print jobs in the queue." << endl;
        } else {
            cout << "Current print queue: ";
            int i = front;
            while (true) {
                cout << printQueue[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    PrinterSpooler spooler;
    int choice, jobID;
    char ch;

    cout << "Name: Ishwari Mulye   PRN: B24CE1107" << endl;
    cout << "------ Printer Spooler System (Circular Queue) ------" << endl;

    do {
        cout << "\n1. Add Print Job\n2. Process Print Job\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Print Job ID: ";
            cin >> jobID;
            spooler.addJob(jobID);
            break;

        case 2:
            spooler.processJob();
            break;

        case 3:
            spooler.displayQueue();
            break;

        case 4:
            cout << "Exiting Printer Spooler System..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        if (choice != 4) {
            cout << "Do you want to continue (Y/N): ";
            cin >> ch;
        } else {
            ch = 'N';
        }

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
