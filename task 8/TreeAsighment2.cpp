#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
    	data = value;
    	left =NULL;
    	right = NULL;
	}
};

// Function to insert a node into the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform pre-order traversal
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Function to perform in-order traversal
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Function to perform post-order traversal
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    // Initialize an empty binary search tree
    TreeNode* root = NULL;

    // Insert the numbers into the binary search tree
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 20);
    root = insert(root, 24);
    root = insert(root, 32);

    // Print the sorted numbers in pre-order
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;

    // Print the sorted numbers in in-order
    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    // Print the sorted numbers in post-order
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
    return 0;
}

