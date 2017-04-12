#include <iostream>
#include <stdio.h> //printf
#include <vector>
struct node{
    std::string data;
    node *parent;
    bool color; //0 == black; 1 == red
    node *left;
    node *right;
};

class string_set{
    node* root;
   public:
      string_set()
      {
          root=NULL;
      }

      void deleteTree(node* n){
if (n == NULL)
    return;
    deleteTree(n -> left);
    deleteTree(n -> right);
    delete n;
}


    ~string_set(){
    deleteTree(root);
    }

void insert(std::string d) //добавление
   {
     node *p;
     node *q;
     node *t = new node;
     t -> data= d;
     t-> left=NULL;
     t-> right=NULL;
     t-> color = 1;
     p = root;
     q = NULL;
     if(root==NULL)
     {
           root = t;
           t -> parent = NULL;
     }
     else
     {
         while (p!=NULL)
         {
              q = p;
              if( p-> data < t-> data)
                  p = p->right;
              else
                  p = p->left;
         }
         t -> parent=q;
         if(q -> data <t -> data)
              q->right=t;
         else
              q->left=t;
     }
     insertFixUp(t);
}



void insertFixUp (node *t) //для сохранения красно-черных свойств дерева
{
     node *p;
     if(t == root)
     {
         t -> color= 0;
         return;
     }
     while(t->parent!=NULL && t->parent->color== 1)
     {
           node *g = t->parent->parent;
           if(g->left==t->parent)
           {
                        if( g-> right!=NULL)
                        {
                              p = g->right;
                              if(p ->color == 1)
                              {
                                   t->parent->color=0;
                                   p->color=0;
                                   g->color=1;
                                   t = g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t = t-> parent;
                                 leftrotate(t);
                            }
                            t ->parent->color = 0;
                            g ->color = 1;
                            rightrotate(g);
                        }
           }
           else
           {
                        if(g->left != NULL)
                        {
                             p = g->left;
                             if(p ->color == 1)
                             {
                                  t-> parent -> color = 0;
                                  p->color = 0;
                                  g->color = 1;
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t ->parent->left == t)
                            {
                                   t = t->parent;
                                   rightrotate(t);
                            }
                            t->parent->color = 0;
                            g->color = 1;
                            leftrotate(g);
                        }
           }
           root->color = 0 ;
     }
}



bool isItThere (std::string d){ //проверка принадлежности
    node *p = root;
         while(p != NULL)
     {
           if(p -> data == d)
               return true;
           else
           {
                 if( p-> data < d)
                    p = p->right;
                 else
                    p = p->left;
           }
     }
     return false;
}



node* find (std::string d){ //нахождение ноды по данным
     node *p = root;
         while(p != NULL and p -> data != d){
                if( p-> data < d)
                    p = p->right;
                 else
                    p = p->left;
           }

     return p;
}



int cardinality(){ //мощность множества
return size(root);
}




int size(node* p) const
{
    if (p == NULL){
        return 0;
    }
    else
        return size(p->left) + size(p->right) + 1;
}





bool isEmpty(){ //проверка на пустоту
if (root == NULL)
    return true;
    return false;
}



void remove(std::string d) //удаление по значению
{
     if(root==NULL)
     {
           std::cout << "The set is empty" << std::endl;
           return;
     }
     node *p = root;
     node* q = NULL;
     node* t = NULL;
     if (!isItThere(d))
     {
         std::cout << "No such string";
         return;
     }
     else
     {
         p = find(d);
         if(p -> left == NULL or p -> right == NULL)
              t=p;
         else
              t=successor(p);
         if(t->left!=NULL)
              q=t->left;
         else
         {
              if(t->right!=NULL)
                   q=t->right;
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent = t->parent;
         if(t -> parent == NULL)
              root=q;
         else
         {
             if(t == t->parent->left)
                t->parent->left=q;
             else
                t->parent->right=q;
         }
         if(t!=p)
         {
             p->color=t->color;
             p->data=t->data;
         }
                  if(isBlack(t))
             removeFixUp(q);
     }
}



node* successor(node *p)
{
      node *t = NULL;
     if(p->left!=NULL)
     {
         t = p->left;
         while(t->right!=NULL)
              t = t->right;
     }
     else
     {
         t = p->right;
         while(t->left!=NULL)
              t = t->left;
     }
     return t;
}

bool isRed(node* p){  //если в removeFixUp в условие (if) попадет нода, равная NULL, выскочит
if(p == NULL or p -> color == 0)//ошибка, поэтому такие ноды нужно отсеивать обособленными функциями
    return false;
    else if (p -> color == 1)
        return true;
}

bool isBlack(node *p){
if (p == NULL or p -> color == 1)
    return false;
    else if (p -> color == 0)
        return true;
}



void removeFixUp(node *p) //для восстановления красно-черных свойств
{
    node *s;
    while(p!=root and isBlack(p))
    {
          if(p==p->parent->left)
          {
                  s=p->parent->right;
                  if(isRed(s))
                  {
                         s->color=0;
                         p->parent->color=1;
                         leftrotate(p->parent);
                         s=p->parent->right;
                  }
                  else if(isBlack(s->right) and isBlack(s->left))
                  {
                         s->color=1;
                         p=p->parent;
                  }
                  else if(isBlack(s -> right))
                      {
                             s->left->color==0;
                             s->color=1;
                             rightrotate(s);
                             s=p->parent->right;
                      }
                      s->color=p->parent->color;
                      p->parent->color= 0;
                      s->right->color= 0;
                      leftrotate(p->parent);
                      p=root;

          }
          else
          {
              s = p -> parent -> left;
                  if(isRed(s))
                  {
                        s->color=0;
                        p->parent->color=1;
                        rightrotate(p->parent);
                        s=p->parent->left;
                  }
                  if(isBlack(s -> left) and isBlack(s -> right))
                  {
                        s->color=1;
                        p=p->parent;
                  }
                  else if(isBlack(s-> left))
                        {
                              s->right->color=0;
                              s->color=1;
                              leftrotate(s);
                              s=p->parent->left;
                        }
                        s->color=p->parent->color;
                        p->parent->color=0;
                        s->left->color=0;
                        rightrotate(p->parent);
                        p=root;
                 }
          }
       p->color=0;
       root->color=0;
    }







void leftrotate(node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           node *q = p->right;
           if(q->left!=NULL)
           {
                  p->right=q->left;
                  q->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                q->parent=p->parent;
           if(p->parent == NULL)
                root = q;
           else
           {
               if(p==p->parent->left)
                       p->parent->left = q;
               else
                       p->parent->right = q;
           }
           q->left = p;
           p->parent = q;
     }
}



void rightrotate(node *p)
{
     if(p->left == NULL)
          return;
     else
     {
         node *q = p->left;
         if(q->right!=NULL)
         {
                  p->left = q->right;
                  q->right->parent = p;
         }
         else
                 p->left = NULL;
         if(p->parent!=NULL)
                 q->parent = p->parent;
         if(p->parent==NULL)
               root = q;
         else
         {
             if(p==p->parent->left)
                   p->parent->left = q;
             else
                   p->parent->right = q;
         }
         q ->right = p;
         p->parent = q;
     }
}



void display(){ //печать
disp(root, 1);
std::cout << std::endl << "--------" << std::endl;
}

void disp(node* ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        disp(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        std::cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            std::cout<<"        ";
            if (ptr -> color == 0)
        std::cout<< ptr -> data << " " << "(Black)";
        else
            std::cout << ptr -> data << " " << "(Red)";
        disp(ptr->left, level + 1);
    }
}

void operator=(const string_set& copyset) //оператор =
{
  {
  if (&copyset == this)
    return;
  deleteTree(root);
  copy(root, copyset.root);
  }
  }


void copy(node*& p, const node* copyset){ //у меня не получилось соединить copy constructor
  if (copyset == NULL) //и оператор =, поэтому я реализовал копирование как отдельную функцию
    p = NULL;
  else
  {
    p = new node;
    p-> data = copyset -> data;
    copy(p->left, copyset->left);
    copy(p->right, copyset->right);
  }
}

node* getRoot(){
return root;
}


void Union(const node* p){
    if (p == NULL)
        return;
    else
    {
        if (!isItThere(p -> data))
            insert(p -> data);
        Union(p -> right);
        Union(p -> left);
    }
}

string_set Intersect(const node* p){
    std::vector<std::string>tempData;
    string_set T;
    intersect (p, tempData);
    for (int i = 0; i < tempData.size(); i++)
        T.insert(tempData[i]);
        return T;
}


void intersect(const node* p, std::vector<std::string>& tD){
        if (p == NULL)
        return;
    else
    {
        if (isItThere(p -> data))
            tD.push_back(p -> data);

        Intersect(p -> right);
        Intersect(p -> left);
    }

}



};







int main()
{
    string_set testset1;

    testset1.insert("cats");
    testset1.insert("dogs");
    testset1.insert("ponies");
    testset1.insert("frogs");
    testset1.display();

    testset1.insert("eagles");
    testset1.insert("fish");
    testset1.insert ("worms");
    testset1.display();



     string_set testset2;
     testset2.insert("mice");
     testset2.insert("parrots");
     testset2.insert("deers");

     string_set testset3;
     std::cout << testset3.isEmpty() << std::endl;
     testset3=testset2;
     testset3.display();
     std::cout << testset3.cardinality() << " " << testset3.isEmpty();

     string_set testset4;
     testset4.insert("giraffes");
     testset4.insert("monkeys");

     testset4.Union(testset3.getRoot());
     testset4.display();

     testset4.remove("deers");
     testset4.remove("parrots");
     testset4.display();

     testset3.display();

     testset4=testset4.Intersect(testset3.getRoot());
     testset4.display();

return 0;
}
