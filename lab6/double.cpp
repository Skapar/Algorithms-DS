#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int x): data(x), next(NULL), prev(NULL) {}
};

struct doublett {
    node* head = NULL;
    node* tail = NULL;

    void endpush(int n) {
        node* a = new node(n);
        if (head == NULL) {
            head = a;
            tail = a;
        }
        else {
            tail->next = a;
            a->prev = tail;
            tail = a;
        }
    }

    void beginpush(int n) {
        node* a = new node(n);
        if (head == NULL) {
            head = a;
            tail = a;
        }
        else {
            head->prev = a;
            a->next = head;
            head = a;
        }
    }

    void printlist() {
        node* cur = head;

        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
};

int main() {
    doublett dad;
    dad.endpush(2);
    dad.endpush(3);
    dad.endpush(4);

    dad.printlist();  
    return 0;
}
