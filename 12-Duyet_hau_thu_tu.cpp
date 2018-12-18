#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* l;
    Node* r;
};

int n, a[100];

Node* createNode(int x){
    Node* p = new Node;
    p->key = x;
    p->l = NULL;
    p->r = NULL;
    return p;
}

Node* addNode(Node* &root, int i){
    if (i < n){
        root = createNode(a[i]);
        root->l = addNode(root->l, 2 * i + 1);
        root->r = addNode(root->r, 2 * i + 2);
    }
    return root;
}

void PostOrder(Node* &root){
    if (root->l != NULL) PostOrder(root->l);
    if (root->r != NULL) PostOrder(root->r);
    cout << root->key << ' ';
}

int Height(Node* &root){
    if (root == NULL) return 0;
    else return max(Height(root->l), Height(root->r)) + 1;
}

int main(){
    Node* root = NULL;
    int x;
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    root = addNode(root, 0);
    PostOrder(root);
    cout << "\nChieu cao cay = " << Height(root);
}



