#include <iostream>
#include <queue>
using namespace std;

struct Node {
char data;
Node* left;
Node* right;

Node(char value) {
data = value;
left = NULL;
right = NULL;
}
};

void inorder(Node* root) {
if (root == NULL)
return;

inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

void preorder(Node* root) {
if (root == NULL)
return;

cout << root->data << " ";
preorder(root->left);
preorder(root->right);
}

void postorder(Node* root) {
if (root == NULL)
return;

postorder(root->left);
postorder(root->right);
cout << root->data << " ";
}

void levelOrder(Node* root) {
if (root == NULL)
return;

queue<Node*> q;
q.push(root);

while (!q.empty()) {
Node* current = q.front();
q.pop();

cout << current->data << " ";

if (current->left != NULL)
q.push(current->left);

if (current->right != NULL)
q.push(current->right);
}
}

int main() {
Node* root = new Node('A');
root->left = new Node('B');
root->right = new Node('C');
root->left->left = new Node('D');
root->left->right = new Node('E');
root->right->left = new Node('F');
root->right->right = new Node('G');

cout << "Inorder: ";
inorder(root);

cout << endl << "Preorder: ";
preorder(root);

cout << endl << "Postorder: ";
postorder(root);

cout << endl << "Level Order: ";
levelOrder(root);

return 0;
}
