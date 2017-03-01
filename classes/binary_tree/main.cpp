#include <iostream>
#include <queue>

struct node{
node* left = NULL;
node* right = NULL;
int data;
};

class binTree{
node* root;

public:
binTree(int a){
    root = new node;
    root -> data = a;
    };

void deleteTree(node* n){
if (n == NULL)
    return;
    deleteTree(n -> left);
    deleteTree(n -> right);
    delete n;
}

~binTree(){
deleteTree(root);
}

bool DFS (int data, node* n){
if (n == NULL)
    return false;
    if (n -> data == data)
        return true;
        if (DFS(data, n->left))
            return true;
        if (DFS(data, n->right))
            return true;
        return false;
}

bool BFS (int data){
    std::queue <node*> A;
    A.push(root);
    while (!A.empty()){
        node* temp = A.back();
        A.pop();
        if (temp -> data == data)
            return true;
        if (temp -> left != NULL)
            A.push(temp -> left);
            if (temp -> right != NULL)
                A.push(temp -> right);
            }
            return false;
}

node* get_root(){
return root;
}

void insert(int data, node* n){
    if (root == NULL){
        root = new node;
    root -> data = data;
    root -> right = NULL;
    root -> left = NULL;
    }
     else
    if (data < n -> data){
        if (n -> left != NULL)
            insert (data, n -> left);
            else
            n -> left = new node;
            n -> left -> data = data;
            n -> right = NULL;
            n -> left = NULL;
    }
    else {
    if (n -> right != NULL)
    insert (data, n -> right);
    else
        n -> right = new node;
        n -> right -> data = data;
        n -> right = NULL;
        n -> left = NULL;
    }
}




};

int main(){

return 0;
}

