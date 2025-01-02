#include<bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;

    Node(int _id){
        id = _id;
    }
};

Node* root = nullptr;
map<int, Node*> nodes;

void makeRoot(int id) {
    if (!root) {
        root = new Node(id);
        nodes[id] = root;
    }
}

void insertNode(int u, int v) {
    if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end()) {
        return;
    }
    Node* newNode = new Node(u);
    nodes[u] = newNode;
    nodes[v]->children.push_back(newNode); // Chèn u làm con của v
}

void preOrder(Node* node) {
    if (!node) return;
    cout << node->id << " ";
    for (Node* child : node->children) {
        preOrder(child);
    }
}

void inOrder(Node* node) {
    if (!node) return;
    if (!node->children.empty()) {
        inOrder(node->children[0]);
    }
    cout << node->id << " ";
    for (size_t i = 1; i < node->children.size(); ++i) {
        inOrder(node->children[i]);
    }
}

void postOrder(Node* node) {
    if (!node) return;
    for (Node* child : node->children) {
        postOrder(child);
    }
    cout << node->id << " ";
}
int main(){
    string command;
    while(1){
        cin >> command;
        if (command == "*")
            break;
        if (command == "MakeRoot") {
            int u;
            cin >> u;
            makeRoot(u);
        } else if (command == "Insert") {
            int u, v;
            cin >> u >> v;
            insertNode(u, v);
        } else if (command == "PreOrder") {
            if (root) {
                preOrder(root);
                cout << endl;
            }
        } else if (command == "InOrder") {
            if (root) {
                inOrder(root);
                cout << endl;
            }
        } else if (command == "PostOrder") {
            if (root) {
                postOrder(root);
                cout << endl;
            }
        }
    }
}
