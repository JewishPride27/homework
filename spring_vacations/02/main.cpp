#include <iostream>
#include <string>
using namespace std;

struct node{
    node* next;
    node* prev;
    std::string data;
    int key;
};

class dict{ //словарь сделан на основе стека с приоритетами, но с двумя указателями
    node* head;
    public:
    dict(std::string s, int k){
        head = new node;
        head -> data = s;
        head -> key = k;
        head -> next = NULL;
        head -> prev = NULL;
    }

    ~dict(){
        while (head!=NULL){
            node* temp = head;
            head = head -> next;
            delete temp;
        }
    }

    void print(){ //печать. удобно
    node* q = head;
    while (q != NULL){
           std::cout << q -> data << " " << q -> key << std::endl;
           q = q -> next;
           }
    }

    void push (std::string s, int k){ //добавление происходит по приоритету
            node* temp = new node;
            temp -> key = k;
            temp -> data = s;

            if (temp -> key > head-> key){
                    temp -> prev = NULL;
                    temp -> next = head;
                    head -> prev = temp;
                    head = temp;
                    }
                    else if (temp -> key == head -> key){
                            if (head -> next == NULL){
                            head -> next = temp;
                            temp -> next = NULL;
                            temp -> prev = head;
                            return;
                        }
                    else{
                        temp -> next = head -> next;
                        head -> next = temp;
                        temp -> prev = head;
                        temp -> next -> prev = temp;
                    }
                    }
                    else
                    {
                        if (head -> next == NULL)
                        {
                            head -> next = temp;
                            temp -> next = NULL;
                            temp -> prev = head;
                            return;
                        }
                        else{
                                node* q = head;
                          while (q -> key > temp -> key)
                            q = q -> next;
                          q -> prev -> next = temp;
                          temp -> prev = q -> prev;
                          q -> prev = temp;
                          temp -> next = q;
                        }
                    }
                }


    string pop(){ //элементы удаляются по приоритету, но возвращается только строка (это же словарь)
        if (head == NULL)
             return "Dictionnary is empty";
            node* temp = head;
            head = head -> next;
            std::string s = temp -> data;
            delete temp;
            return s;

        }

    bool isEmpty(){
    if (head == NULL)
        return true;
    else
        return false;
    }

        void remove (std::string s){ //удаление по строке
            if (!find(s))
            {
                std::cout << "No such string" << endl;
                return;
            }
             node* q = head;
      while (q != NULL){
        q = q -> next;
        if (q -> data == s)
        {
            q -> prev -> next = q -> next;
            q -> next -> prev = q -> prev;
            delete q;
            break;
        }

      }
      return;
        }

        int& operator[](std::string s){ //оператор
        if (find(s))
          {
              node *q = head;
              while (q -> data != s)
                q = q-> next;
                return q -> key;
          }
          else{
              node* temp = new node;
              temp -> data = s;
              temp -> prev = NULL;
                    temp -> next = head;
                    head -> prev = temp;
                    head = temp;
                    return temp -> key;
                    }
        }

        bool find (std::string s){ //пооверка наличия строки в словаре
      node* q = head;
      while (q != NULL){
         if (q -> data == s)
           return true;
           q = q -> next;
           }
           return false;
           }




           void putInOrder(){ //я не придумал, как реализовать добавление через квадратные скобки с сохранением приоритетов,
               node* q = head; //поэтому сделал упорядочивающую функцию
               while (q -> key > q -> next -> key){
                    if (q -> next -> next == NULL){
                    break;
                    }
               q = q -> next;
                   }
                   if (q -> next -> next != NULL){
                        int tmpk = q -> next -> key;
                        std::string tmps = q -> next -> data;
                        this -> remove(q -> next -> data);
                         this -> push (tmps, tmpk);
                   }
                   return;

           }






};

int main()
{
    dict A("sharks", 2);
    A.push("mouses", 0);
    A.push("cats", 15);
    A.print();
    std::cout << "-------------" << endl; //для читабельности
    A["nightingales"] = 13;
    A["zebras"] = 283;
    A["cats"] = 57;
    A.putInOrder();
    A.print();
    std::cout << A.isEmpty() << endl;
    std::cout << "-------------" << endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.pop() << std::endl;
    std::cout << A.isEmpty() << endl;



return 0;
}
