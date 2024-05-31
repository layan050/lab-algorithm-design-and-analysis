#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
    	data = value;
    	left = NULL;
    	right = NULL;
	}
};

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = new TreeNode(18);
    root->left = new TreeNode(30);
    root->right = new TreeNode(33);
    root->left->left = new TreeNode(29);
    root->left->right = new TreeNode(32);

    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;
    cout << "In-order: ";
    inOrder(root);
    cout << endl;
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

