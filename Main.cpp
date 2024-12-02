/*Allen Rehkemper  
MS549 Module 5.1 Binary Search
Dr. Jill Coddington
11/24/25 
This project will showcase the binary search tree that we've covered in this course. The functions will include an Add, Remove, Maxamize, InOrder/Traverse Print
and a Find. There will be tests that include testing for repetitive numbers (duplicate nodes), removing a node with no children and with two children
I'll also evaluate the performance of the tree adding 100, 1000, and 10000 nodes.  I estimated this would take about 2 hours, it turned into 3 hours
for a little bit of research needed on the traverse function and making my delete function more robust than my original version. */
#include <iostream>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "functions.h"

// Function to evaluate performance based on node count
void evaluatePerformance(int numNodes) {
    Node* root = nullptr;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numNodes; ++i) {
        root = insertNode(root, rand() % 1000000); 
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Time taken to insert " << numNodes << " nodes: " << duration << " ms\n";
}

// Function to handle custom BST operations (manual or random population)
void customBSTOperations() {
    Node* root = nullptr;
    int numNodes, value, searchValue, choice;

    std::cout << "Enter the number of nodes to insert: ";
    std::cin >> numNodes;

    std::cout << "How would you like to populate the nodes?\n";
    std::cout << "1. Manually input node values\n";
    std::cout << "2. Populate nodes randomly\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        // Manually input node values
        std::cout << "Enter " << numNodes << " values to insert into the BST:\n";
        for (int i = 0; i < numNodes; ++i) {
            std::cin >> value;
            root = insertNode(root, value);
        }
    }
    else if (choice == 2) {
        // Populate nodes randomly
        srand(time(0));
        std::cout << "Inserting " << numNodes << " random values into the BST:\n";
        for (int i = 0; i < numNodes; ++i) {
            value = rand() % 1000000;
            root = insertNode(root, value);
        }
        std::cout << numNodes << " random nodes inserted into the BST.\n";
    }
    else {
        std::cout << "Invalid choice. Returning to main menu.\n";
        return;
    }

    // Perform an inorder traversal to show the structure of the BST
    std::cout << "Inorder Traversal of the BST:\n";
    inorderTraverse(root);

    // Optionally, allow the user to search for a specific value
    std::cout << "\nEnter a value to search for: ";
    std::cin >> searchValue;

    Node* found = findNode(root, searchValue);
    if (found) {
        std::cout << "Value " << searchValue << " found in the BST.\n";
    }
    else {
        std::cout << "Value " << searchValue << " not found in the BST.\n";
    }

    // Optionally, allow the user to remove a node
    std::cout << "\nEnter a value to remove: ";
    std::cin >> searchValue;
    root = removeNode(root, searchValue);
    std::cout << "Inorder Traversal after removal:\n";
    inorderTraverse(root);

    // Display the maximum value
    try {
        int maxValue = findMaximum(root);
        std::cout << "\nMaximum value in the BST: " << maxValue << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "\nError: " << e.what() << std::endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    int choice;
    do {
        std::cout << "\nBinary Search Tree Operations Menu:\n";
        std::cout << "1. Evaluate performance with 100 nodes\n";
        std::cout << "2. Evaluate performance with 1000 nodes\n";
        std::cout << "3. Evaluate performance with 10000 nodes\n";
        std::cout << "4. Evaluate performance with 100000 nodes\n";
        std::cout << "5. Evaluate performance with 1000000 nodes\n";
        std::cout << "6. Custom BST operations\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            evaluatePerformance(100);
            break;
        case 2:
            evaluatePerformance(1000);
            break;
        case 3:
            evaluatePerformance(10000);
            break;
        case 4:
            evaluatePerformance(100000);
            break;
        case 5:
            evaluatePerformance(1000000);
            break;
        case 6:
            customBSTOperations();
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

