/*Load Balancing:
For example, imagine you have a set of servers that handle requests for a web application. 
The key to load balancing is using the hash value of a client's IP address or a request ID to determine which server should handle the request.
The hash function is typically designed so that the data is evenly distributed across the servers, ensuring that no single server is overloaded.
Write a program of a load balancing system*/


#include <iostream>
using namespace std;

int main() {
    int N, R; // N = servers, R = requests
    char ch;
    cout<<"Name: Ishwari Mulye PRN: B24CE1107\n\n";
     cout << "         LOAD BALANCING SYSYEM\n";

    do {
        cout << "\nEnter number of servers: ";
        cin >> N;

       
        int* serv_id = new int[N];

        cout << "Enter number of requests: ";
        cin >> R;

        int* req_id = new int[R];

        cout << "Enter " << R << " request IDs:\n";
        for (int i = 0; i < R; i++) {
            cin >> req_id[i];
        }

        
        for (int i = 0; i < R; i++) {
            serv_id[i] = req_id[i] % N;  
        }

        // Output table
        cout << "\nLoad Balancing Summary\n";
        cout << "\nThe requests are assigned to following servers:\n";
        cout << "\n=================================\n";
        cout << "Request ID\t|\tServer\n";
        cout << "=================================\n";

        for (int i = 0; i < R; i++) {
            cout << " " << req_id[i] << "\t\t|\tServer-" << serv_id[i] << "\n";
        }

        cout << "=================================\n";

        
        cout << "\nDo you want to check again? (y/n): ";
        cin >> ch;

        // Free dynamically allocated memory
        delete[] serv_id;
        delete[] req_id;

    } while (ch == 'y' || ch == 'Y');

    cout << "\nThank you...!\n";
    return 0;
}
