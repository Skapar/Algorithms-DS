#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct doublelin{
    Node* head = nullptr;

    void append(int val){
        Node* newNode = new Node;
        newNode -> data = val;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        if(!head){
            head = newNode;
        }
        else{
            Node* current = head;
            while (current -> next){
                current = current -> next;
            }
            current -> next = newNode;
            newNode -> prev = current;
        }
    }
    void appendbeg(int val) {
        Node* newNode = new Node;
        newNode -> data = val;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        if(head){
            head -> prev = newNode; 
        }
        head = newNode;
    }
    
};