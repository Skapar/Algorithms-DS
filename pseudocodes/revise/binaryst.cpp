#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

bool iterativesearch(struct Node* root, int key){
    while(root!=NULL){
        if(key > root ->data){
            root = root ->right;
        }
        else if(key < root -> data){
            root = root ->left;
        }
        else{
            return true;
        }
    }
}
struct Node* newNode(int key){
    struct Node* temp = new Node;
    temp ->data = key;
    temp -> left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* Node, int data)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL)
        return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data < Node->data)
        Node->left = insert(Node->left, data);
    else if (data > Node->data)
        Node->right = insert(Node->right, data);
 
    /* return the (unchanged) Node pointer */
    return Node;
}
