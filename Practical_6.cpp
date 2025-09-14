/* Simple Task Scheduler:
 Write a program that implements a simple task scheduler using a singly linked list. Each node in the linked list represents a task with its priority and execution time. Tasks are scheduled based on their priority, with higher priority tasks being executed first.*/
#include <iostream>
#include <string>
using namespace std;

// Node class for the task scheduler
class Node {
public:
    string task_name;  // Name of the task
    int priority;      // Task priority (higher = more important)
    int exe_time;      // Execution time in seconds
    Node* next;        // Pointer to the next node

    // Constructor to initialize the node
    Node(string task, int p, int e) {
        task_name = task;
        priority = p;
        exe_time = e;
        next = NULL;
    }

    // Display function for a single node
    void display() {
        cout << "Task name: " << task_name << endl;
        cout << "Priority: " << priority << endl;
        cout << "Execution time: " << exe_time << "s" << endl;
        cout << task_name << " task with priority " << priority 
             << " is scheduled for execution." << endl << endl;
    }
};

int main() {
    string ta;
    int p, e;
    Node *header = NULL, *temp = NULL;
    int n;
    
    cout<<"Name: Ishwari Mulye PRN: B24CE1107";

    cout << "\n\nHow many tasks do you want to insert: ";
    cin >> n;

    // Input loop for tasks
    for(int i = 0; i < n; i++) {
        cout << "\nEnter task name: ";
        cin >> ta;
        cout << "Enter Priority: ";
        cin >> p;
        cout << "Enter Execution Time(in seconds): ";
        cin >> e;

        // If list is empty, first node becomes header
        if(header == NULL) {
            header = new Node(ta, p, e);
        } 
        else {
            temp = new Node(ta, p, e);

            // Priority-based insertion
            if(temp->priority > header->priority) {
                // New node has higher priority than head
                temp->next = header;
                header = temp;
            } 
            else {
                Node* prev = header;
                Node* curr = header->next;

                // Traverse to find correct insertion point
                while(curr != NULL && curr->priority >= temp->priority) {
                    prev = curr;
                    curr = curr->next;
                }

                // Insert node between prev and curr
                prev->next = temp;
                temp->next = curr;
            }
        }
    }

    // Print detailed execution schedule
    cout << "\n----- Task Execution Schedule -----\n";
    temp = header;
    while(temp != NULL) {
        temp->display();
        temp = temp->next;
    }

    // Print linked list in arrow format
    cout << "\n----- Linked List Representation -----\n";
    temp = header;
    while(temp != NULL) {
        cout << temp->task_name << "(" << temp->priority << ") --> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}






























