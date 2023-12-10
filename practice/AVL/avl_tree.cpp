#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for AVL Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height; // Height of the node

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // New node is initially at height 1
    }
};

class AVLTree {
private:
    Node* root;

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Destructor to free allocated memory
    ~AVLTree() {
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

    // Get height of a node
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // Get balance factor of a node
    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Perform right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // Return new root
        return x;
    }

    // Perform left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // Return new root
        return y;
    }

    // Insert a value into the AVL Tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a value into the AVL Tree
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        // Perform standard BST insertion
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        } else {
            // Duplicate values are not allowed in AVL Trees
            return node;
        }

        // Update height of current node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor to check if the node became unbalanced
        int balance = getBalanceFactor(node);

        // Perform rotations if needed to balance the tree
        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }
        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }
        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Perform in-order traversal of the AVL Tree
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

    // Delete a value from the AVL Tree
    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    // Recursive function to delete a value from the AVL Tree
    Node* deleteRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        // Perform standard BST delete
        if (value < root->data) {
            root->left = deleteRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRecursive(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteRecursive(root->right, temp->data);
        }

        // If the tree had only one node then return
        if (root == nullptr) {
            return root;
        }

        // Update height of current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Get the balance factor to check if the node became unbalanced
        int balance = getBalanceFactor(root);

        // Perform rotations if needed to balance the tree

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }
        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }
        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Find the node with the smallest value in the AVL Tree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "In-order Traversal: ";
    avl.inorderTraversal();

    int deleteValue = 30;
    cout << "Deleting " << deleteValue << " from the tree" << endl;
    avl.deleteNode(deleteValue);
    cout << "In-order Traversal after deletion: ";
    avl.inorderTraversal();

    return 0;
}
