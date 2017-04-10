#include <iostream>
#include <stdio.h>
#include <string>


struct node{
bool color; //0 == black; 1 == red
node* parent;
node* left;
node* right;
std::string data;
} *root;


  class string_set{
public:
    string_set(std::string s){
        root = new node;
        root -> parent = NULL;
        root -> left = NULL;
        root -> right = NULL;
        root -> data = s;
    }

    void deleteSet(node* n){
if (n == NULL)
    return;
    deleteSet (n -> left);
    deleteSet (n -> right);
    delete n;
}
     ~string_set(){
        deleteSet(root);
    }

    void rotateleft(node* p)
{
	node* q = p-> right;
	p->right= q->left;
	if (q -> left != NULL )
        q -> left -> parent = p;
    q -> parent = p -> parent;
    if (p -> parent == NULL)
        root = q;
    else if (p == p -> parent -> left)
        p -> parent -> left = q;
    else
        p -> parent -> right = q;
    q -> left = p;
    p -> parent = q;
}

    void rotateright(node* p)
{
    node* q = p-> left;
	p -> left = q -> right;
	if (q -> right != NULL )
        q -> right -> parent = p;
    q -> parent = p -> parent;
    if (p -> parent == NULL)
        root = q;
    else if (p == p -> parent -> right)
        p -> parent -> right = q;
    else
        p -> parent -> left = q;
    q -> right = p;
    p -> parent = q;
}

 void RBInsertFixup(node* x){
        while (x->parent->color == 1){
            if (x->parent->parent->left == x->parent){
                node *y = x->parent->parent->right;
                if (y->color == 1){
                    y->color = 0;
                    x->parent->color = 0;
                    x->parent->parent->color = 1;
                    x = x->parent->parent;
                }
                else
                    {
                    if (x->parent->right == x){
                        x = x->parent;
                        rotateleft(x);
                    }
                    x->parent->color = 0;
                    x->parent->parent->color = 1;
                    rotateright(x->parent->parent);
                }
            }

    else
                {
                node* y = x->parent->parent->left;
                if (y->color == 1){
                    y->color = 0;
                    x->parent->color = 0;
                    x->parent->parent->color = 1;
                    x = x->parent->parent;
                }
            else
                {
                    if (x->parent->left == x){
                        x = x->parent;
                        rotateright(x);
                    }
                    x->parent->color = 0;
                    x->parent->parent->color = 1;
                    rotateleft(x->parent->parent);
                }
            }
        }
        root->color = 0;
    }

    void insert (node* p){
    node* y = NULL;
    node* x = root;
    while (x != NULL)
           {
               y = x;
               if (p -> data.size() < x -> data.size())
                x = x -> left;
               else
                x = x -> right;
           }
    p -> parent = y;
    if (y == NULL)
        root = p;
    else if (p -> data.size() < y -> data.size())
        y -> left = p;
        else y -> right = p;
        p -> left = NULL;
        p -> right = NULL;
        p -> color = 1;
        RBInsertFixup(p);
        }


bool DFS (std::string s, node* n){
if (n == NULL)
    return false;
    if (n -> data == s)
        return true;
        if (DFS(s, n->left))
            return true;
        if (DFS(s, n->right))
            return true;
        return false;
}

}; void insert_fix(Node *x){
        while (x->parent->color == RED){
            if (x->parent->parent->left == x->parent){
                y = x->parent->parent->right;
                if (y->color == RED){
                    y->color = BLACK;
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                }else{
                    if (x->parent->right == x){
                        x = x->parent;
                        left_rotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    right_rotate(x->parent->parent);
                }
            }
            else{
                y = x->parent->parent->left;
                if (y->color == RED){
                    y->color = BLACK;
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                }else{
                    if (x->parent->left == x){
                        x = x->parent;
                        right_rotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    left_rotate(x->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

int main(){
    string_set myset ("Lol");
    node* r;
    r -> data = "Loll";
    node* d;
    d -> data = "Lo";
    myset.insert(r);
    myset.insert(d);

return 0;
}
