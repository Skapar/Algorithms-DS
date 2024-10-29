#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int h) : val(h), next(nullptr){}
};

struct list{
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr){}

    void push_back(int a){
        Node* p = new Node(a);
        if(first == nullptr){
            first = p;
            last = p;
        }
        else{
            last -> next = p;
            last = p;
        }
    }
    void print(){
        Node* p = first;
        while(p){
            cout << p -> val << " ";
            p = p->next;
        }
        cout << endl;

    }
    void remove() {
    Node* current = first;
    Node* prev = nullptr;
    int cnt = 1;
    while (current != nullptr) {
        if(cnt % 2 ==0){
            if (prev == nullptr) {
                first = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == last) {
                last = prev;
            }
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        else{
            prev = current;
            current = current->next;
        }
        cnt++;
    }
}

};

int main(){
    list l;
    int n;
    cin >> n;

    Node* cur;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        if(i==0){
            l.push_back(a);
            cur = l.first;
        }
        else{
            cur ->next = new Node(a);
            cur = cur->next;
        }
    }
    l.remove();
    l.print();

}