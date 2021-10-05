#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
// Time comp : O(n)
// Aux Comp : worst (linked list):O(n) best (balanced tree) : O(log2 n)
void printPostorder(Node* node) {
    if (node == nullptr)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
void printPreorder(Node* node) {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(Node* node) {
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
void iterativeInorder(struct Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        int data = curr->data;
        cout << data;
        curr = curr->right;
    }
}

void iterativePreorder(Node* root) {
    // Base Case
    if (root == NULL)
        return;

    // Create an empty stack and push root to it
    stack<Node*> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct Node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
void postOrderIterative(Node* root) {
    if (root == NULL)
        return;

    // Create two stacks
    stack<Node*> s1, s2;

    // push root to first stack
    s1.push(root);
    Node* node;

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}
int height(Node* root) {
    if (root == nullptr)
        return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if (lHeight > rHeight)
        return (lHeight + 1);
    else
        return rHeight + 1;
}
void printLevel(Node* root, int level) {
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->data << " ";
    if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
void printLevel (Node* root){
    int levels = height(root);
    for (int i = 1 ;i <= levels ; i++){
        printLevel(root , i);
    }
}

void printLevelWithQ (Node * root ){
    queue <Node*> q;
    q.push(root);
    while (!q.empty() ){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr-> left) q.push(curr->left);
        if (curr-> right) q.push(curr->right);
    }
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal of binary tree is \n";
    printPreorder(root);
    cout << endl;
    iterativePreorder(root);
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
    cout << endl;
    printLevel(root) ;
    cout << endl;
    printLevelWithQ(root);
    cout << endl;
    return 0;
}