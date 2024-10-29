#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct lls{
    Node* head = NULL;

    void insert(int val){
        Node* newNode = new Node;
        newNode -> data = val;
        newNode -> next = nullptr;

        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* current = head;
            while(current -> next != nullptr){
                current = current -> next;
            }
            current -> next = newNode;
        }
    }
    void print(){
        Node* curr = head;

        while(curr != nullptr){
            cout << curr -> next;
        }
    }
};

int main(){
    lls lin;
    // lin.insert(1); 
}