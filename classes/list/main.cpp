#include <iostream>


struct node{
    int data;
    node *next;
};

class list{
    node* head;
    public:
    list(int a){
        head = new node;
        head -> data = a;
        head -> next = NULL;
    }

    ~list(){
        while (head != NULL){
            node* temp = head;
            head = head -> next;
            delete temp;
        }
    }

    void push_front (int a){
            node* temp = new node;
            temp -> data = a;
            temp -> next = head;
            head = temp;
    }

    void push_rear (int a){
            node* temp = new node;
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next -> data = a;
            temp -> next -> next = NULL;
    }

    void push_data (int d){
            node* temp = head;
            while (temp -> data != d && temp != NULL){
                temp = temp -> next;
            }
            if (temp -> next == NULL || head == NULL){
                std::cout << "No elements found";
                return;
                }

            node* temptemp = new node;
            temptemp -> data = d;
            temp -> next -> data = temptemp -> data;
            temptemp -> next = temp -> next -> next;
            temp -> next = temptemp;
    }

    int get(int i){
        if (head != NULL){
            node* temp = head;
        int c = 0;
                while (c < i){
                    temp = temp -> next;
                    c++;
                }

                int a;
            a = temp -> data;
            return a;
        }
    }

    void set (int i, int a){
        if (head != NULL){
            node* temp = head;
        int c = 0;
          while (c < i){
            temp = temp -> next;
          c++;
          }
          temp -> data = a;

        }
    }

    int pop_front(){
        if (head != NULL){
            node* temp = head;
            head = temp -> next;
            int a = temp -> data;
            delete temp;
            return a;
        }
    }

    int pop_rear(){
        if (head != NULL){
            if (head -> next == NULL){
                int a = head -> data;
                delete head;
                return a;
            }
            node* temp=head;
            while (temp -> next -> next != NULL){
                temp = temp -> next;
            }
            int a = temp -> next -> data;
            delete temp -> next;
            temp -> next= NULL;
            return a;
        }
    }
};

int main(){
    list L(12);
    L.push_front(6);
    L.push_rear(9);
    std::cout << L.get(2) << std::endl;
    L.set(2, 8);
    std::cout << L.get(2) << std::endl;
    std::cout << L.pop_front();
    return 0;
}
