#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node(string _val) : val(_val), next(nullptr) {}
};

struct List {
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {}


    Node* Shift(Node* head, int c) {

        Node* n = head;
        while (n->next != nullptr) {
            n = n->next;
        }

        for (int i = 0; i < c; i++) {
            n->next = head;
            head = head->next;
            n = n->next;
            n->next = nullptr;
        }
        return head;
    }

    void print() {
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    List l;
    int n, c;
    Node* head ;
    Node* cur ;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (i == 0) {
            head = new Node(x);
            cur = head;
        } else {
            cur->next = new Node(x);
            cur = cur->next;
        }
    }
    head = l.Shift(head, c);
    l.first = head; 
    l.print();
    return 0;
}
