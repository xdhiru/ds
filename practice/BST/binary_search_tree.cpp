#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor to free allocated memory
    ~BinarySearchTree() {
        destroyTree(root);
    }

    // Function to destroy the tree recursively
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Insert a value into the Binary Search Tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a value into the Binary Search Tree
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Search for a value in the Binary Search Tree
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Recursive function to search for a value in the Binary Search Tree
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    // Delete a value from the Binary Search Tree
    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    // Recursive function to delete a value from the Binary Search Tree
    Node* deleteRecursive(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }

    // Find the node with the smallest value in the BST
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // In-order traversal of the Binary Search Tree
    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }

    // Recursive function for in-order traversal
    void inorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

    // Pre-order traversal of the Binary Search Tree
    void preorderTraversal() {
        preorderTraversalRecursive(root);
        cout << endl;
    }

    // Recursive function for pre-order traversal
    void preorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversalRecursive(node->left);
            preorderTraversalRecursive(node->right);
        }
    }

    // Post-order traversal of the Binary Search Tree
    void postorderTraversal() {
        postorderTraversalRecursive(root);
        cout << endl;
    }

    // Recursive function for post-order traversal
    void postorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            postorderTraversalRecursive(node->left);
            postorderTraversalRecursive(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.inorderTraversal();

    cout << "Pre-order Traversal: ";
    bst.preorderTraversal();

    cout << "Post-order Traversal: ";
    bst.postorderTraversal();

    int searchValue = 40;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
    }

    searchValue = 90;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
    }

    cout << "Deleting 30 from the tree" << endl;
    bst.deleteNode(30);
    cout << "In-order Traversal after deletion: ";
    bst.inorderTraversal();

    return 0;
}
