#include "functions.h"
#include <iostream>
#include <stdexcept> //This library is for the runtime_errors

// This function creates the nodes
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert the new nodes into the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        return CreateNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int findMaximum(Node* root) {
    if (root == nullptr) {
        throw std::runtime_error("The tree is empty."); 
    }
    while (root->right != nullptr) {
        // points to the furthest node to the right
        root = root->right;
    }
    return root->data;
}


// Find the minimum value in a subtree
Node* findMinimum(Node* root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Remove a node from the BST
Node* removeNode(Node* root, int data) {
    if (root == nullptr) {
        return root; // Return if the tree is empty
    }

    // If the data to be deleted is smaller than the root's data, it lies in the left subtree
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    }
    // If the data to be deleted is larger than the root's data, it lies in the right subtree
    else if (data > root->data) {
        root->right = removeNode(root->right, data);
    }
    // If data is the same as root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp; // Return the non-null child, or nullptr if no child
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = root->right;
        while (temp != nullptr && temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}
Node* findNode(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    // Search in the left subtree
    if (data < root->data) {
        return findNode(root->left, data); 
    }
    // Search in the right subtree
    return findNode(root->right, data); 
}

void inorderTraverse(Node* root) {
    if (root == nullptr) {
        return; 
    }
    // Traverse left subtree
    inorderTraverse(root->left); 
    std::cout << root->data << " "; 
    // Traverse right subtree
    inorderTraverse(root->right); 
}

