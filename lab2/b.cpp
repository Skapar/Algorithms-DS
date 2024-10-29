#include <iostream>
#include <string>

using namespace std;
struct Node{
    string word;
    Node* next;

    Node(string word){
        this->word = word;
        this->next = NULL;
    }
};

Node* cyclic(Node* head, int k){
    Node* cur = head;
    while(cur->next!=NULL){
        cur = cur->next;
    }
    for(int i = 0; i<k; i++){
        cur->next = head;
        head = head->next;
        cur=cur->next;
        cur->next=NULL;
    }
    return head;
}
void print(Node* head){
    Node* cur = head;
    while(cur != NULL){
        cout << cur->word << " ";
        cur=cur -> next;
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    Node* head;
    Node* cur;
    for(int i = 0; i<n; i++){
        string word;
        cin >> word;
        if(i==0){
            head = new Node(word);
            cur = head;
        }
        else{
            cur->next = new Node(word);
            cur = cur->next;
        }
    }
    head = cyclic(head, k);
    print(head);
}