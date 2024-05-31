#include <iostream>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

Node *root = NULL;

void addNode(Node *&root, char data) {
    if (root == NULL) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    char alphabet;
    cout << "\n\n\tInitial Tree Structure:\n\n";
    cout << "\t       R\n\t      / \\\n\t     A   E\n\t    /\n\t   S\n\t  / \\\n\t I   T\n\n";
    
    addNode(root, alphabet = 'R');
    addNode(root->left, alphabet = 'A');
    addNode(root->right, alphabet = 'E');
    addNode(root->left->left, alphabet = 'S');
    addNode(root->left->left->left, alphabet = 'I');
    addNode(root->left->left->right, alphabet = 'T');
    
    cout << "PreOrder Display  : ";
    preOrder(root);
    cout << "\nInOrder Display   : ";
    inOrder(root);
    cout << "\nPostOrder Display : ";
    postOrder(root);

    return 0;
}



