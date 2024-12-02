#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function declarations
Node* CreateNode(int data);
Node* insertNode(Node* root, int data);
Node* removeNode(Node* root, int data);
Node* findNode(Node* root, int data);
int findMaximum(Node* root);
void inorderTraverse(Node* root);

#endif // FUNCTIONS_H
