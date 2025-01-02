#include<bits/stdc++.h>

using namespace std;

bool check[100001] = {0};

struct Node{
    int data;
    Node *left, *right;

    Node(int k){
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int k){
    if (root == nullptr){
        return new Node(k);
    }
    if (root->data > k){
        root->left = insert(root->left, k);
    }else{
        root-> right = insert(root->right, k);
    }

    return root;
}

void BST(Node* root){
    cout << root->data << " ";
    if (root->left != nullptr) BST(root->left);
    if (root->right != nullptr) BST(root->right);
}

int main(){
    Node* root = nullptr;

    string command;

    while(1){
        cin >> command;
        if (command == "#")
            break;
        if (command == "insert"){
            int x;
            cin >> x;
            if (!check[x]){
                root = insert(root, x);
                check[x] = true;
            }
        }
    }

    BST(root);
}
