#include <iostream> // Include the iostream library for input and output operations

// Define the structure for a node in the binary tree
struct Node {
    int data; // Data stored in the node
    Node *left; // Pointer to the left child node
    Node *right; // Pointer to the right child node

    // Constructor to initialize a node with given data
    Node(int value) {
        data = value; // Set the node's data
        left = right = nullptr; // Initialize child pointers to NULL (nullptr in modern C++)
    }
};

// Function for Preorder Traversal of the binary tree
void preOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    std::cout << node->data << " "; // Print the data of the current node
    preOrderTraversal(node->left); // Recursively traverse the left subtree
    preOrderTraversal(node->right); // Recursively traverse the right subtree
}

// Function for Inorder Traversal of the binary tree
void inOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    inOrderTraversal(node->left); // Recursively traverse the left subtree
    std::cout << node->data << " "; // Print the data of the current node
    inOrderTraversal(node->right); // Recursively traverse the right subtree
}

// Function for Postorder Traversal of the binary tree
void postOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    postOrderTraversal(node->left); // Recursively traverse the left subtree
    postOrderTraversal(node->right); // Recursively traverse the right subtree
    std::cout << node->data << " "; // Print the data of the current node
}

// Function to insert a node in the binary tree
Node* insertNode(Node* node, int data) {
    if (node == nullptr) { // If the tree is empty, create a new node
        return new Node(data);
    }

    // Create a queue for level-order traversal
    std::queue<Node*> q;
    q.push(node);

    // Level-order traversal to find an appropriate place to insert the new node
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check if the left child is NULL
        if (temp->left == nullptr) {
            temp->left = new Node(data);
            return node;
        } else {
            q.push(temp->left);
        }

        // Check if the right child is NULL
        if (temp->right == nullptr) {
            temp->right = new Node(data);
            return node;
        } else {
            q.push(temp->right);
        }
    }

    return node;
}

int main() {
    Node* root = nullptr; // Initialize the root to NULL
    int n, data;

    // Input the number of nodes
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    // Input node values and construct the binary tree
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter data for node " << i + 1 << ": ";
        std::cin >> data;
        root = insertNode(root, data); // Insert the node into the tree
    }

    // Perform and display the traversals
    std::cout << "Preorder Traversal: ";
    preOrderTraversal(root); // Output: Nodes in preorder
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    inOrderTraversal(root); // Output: Nodes in inorder
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postOrderTraversal(root); // Output: Nodes in postorder
    std::cout << std::endl;

    // Cleanup memory (optional but recommended)
    // Note: A more sophisticated cleanup function should be implemented for real applications
    delete root;

    return 0; // Return 0 to indicate successful program execution
}
/*
Explanation
Node Structure (Node):

Represents a single node in the binary tree, with data, left, and right pointers.
The constructor initializes a node with a given data and sets both child pointers to nullptr.
Traversal Functions:

Preorder Traversal (preOrderTraversal):
Visits the root node, then the left subtree, and finally the right subtree.
Inorder Traversal (inOrderTraversal):
Visits the left subtree, then the root node, and finally the right subtree.
Postorder Traversal (postOrderTraversal):
Visits the left subtree, then the right subtree, and finally the root node.
Insertion Function (insertNode):

Inserts nodes into the binary tree using level-order traversal to find the first available position.
Uses a queue to perform a breadth-first search to find the correct position to insert the new node.
Main Function:

Initializes an empty binary tree (root is nullptr).
Asks the user to input the number of nodes and the data for each node.
Constructs the binary tree by inserting nodes based on user input.
Performs and displays Preorder, Inorder, and Postorder traversals of the binary tree.
Memory Cleanup:

Although the delete root statement is included, it does not handle the cleanup of all nodes. A more comprehensive cleanup function 
should be implemented in a real application to delete all nodes in the tree.
Summary
This code allows users to input the number of nodes and their values to construct a binary tree. It then performs and displays 
three types of tree traversals: Preorder, Inorder, and Postorder. 
The code demonstrates basic tree operations and provides a foundation for understanding binary tree manipulation.
*/
