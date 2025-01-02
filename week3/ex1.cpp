#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

// Cấu trúc nút trên cây
struct Node {
    int id;
    vector<Node*> children; // Danh sách con
    Node(int id) : id(id) {}
};

// Tạo cây
class Tree {
public:
    Node* root;
    map<int, Node*> nodes; // Lưu tất cả các nút trong cây theo id

    Tree() : root(nullptr) {}

    void makeRoot(int id) {
        if (!root) {
            root = new Node(id);
            nodes[id] = root;
        }
    }

    void insert(int u, int v) {
        if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end()) {
            return; // Nút u đã tồn tại hoặc nút v không tồn tại
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

    void processCommand(const string& command) {
        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "MakeRoot") {
            int u;
            ss >> u;
            makeRoot(u);
        } else if (action == "Insert") {
            int u, v;
            ss >> u >> v;
            insert(u, v);
        } else if (action == "PreOrder") {
            if (root) {
                preOrder(root);
                cout << endl;
            }
        } else if (action == "InOrder") {
            if (root) {
                inOrder(root);
                cout << endl;
            }
        } else if (action == "PostOrder") {
            if (root) {
                postOrder(root);
                cout << endl;
            }
        }
    }
};

int main() {
    Tree tree;
    string line;

    // Đọc dữ liệu đầu vào
    while (getline(cin, line)) {
        if (line == "*") break; // Kết thúc dữ liệu
        tree.processCommand(line);
    }

    return 0;
}
