#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x): data(x), next(NULL) {}
};

struct LinkedList {
    Node* head = nullptr;

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() {
        Node* curr = head;

        while (curr != nullptr) {
            cout << curr->data << " "; // Print the data of the current node
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList lin; // Create a linked list object

    // Insert elements into the linked list
    lin.insert(1);
    lin.insert(2);
    lin.insert(3);

    // Print the elements of the linked list
    lin.print();

    return 0;
}
