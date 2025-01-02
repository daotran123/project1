#include<bits/stdc++.h>

using namespace std;

int visited[10001] = {0};

struct Node{
    int data;
    vector<Node> childNode;
};

Node root;
vector<pair<int, Node>> vt;

void makeRoot(int u){
    if (!visited[u]){
        visited[u] = 1;
        root.data = u;
        vt.push({u, root});
    }
}

void insertNode(int u, int v){
    if (!visited[u] && visited[v]){
        visited[u] = 1;
        Node tmp;
        tmp.data = u;


    }
}

int main(){

}
