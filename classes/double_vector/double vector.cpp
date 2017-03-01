#include <iostream>
using namespace std;

class vector {
int quantity;
int size;
double* data;
public:

    vector (int s){
    size = s;
    data = new double[size];
    quantity = 0;
    }

        vector (){
    data = new double[1];
    }


    ~vector(){
    delete[] data;
    }

    void append (int new_size){
        if (new_size > size){
    double* temp = new double [new_size];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];
        delete[] data;
        data = temp;
        size = new_size;
        }
        else {
    double* temp = new double [new_size];
    for (int i = 0; i < new_size; i++)
        temp[i] = data[i];
        delete[] data;
        data = temp;
        size = new_size;
        }
    }


    const double& operator[](int i){
    return data[i];
    }


    void push_back(double a){
        if (quantity == size){
        int new_size = 2*size;
        double* temp = new double [new_size];
        for (int i = 0; i < size; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
        data[size] = a;
        size = new_size;
        }
        else {
            data[quantity] = a;
        }
        quantity++;
        }


        int get_quantity(){
        return quantity;
        }


        int get_size(){
        return size;
        }


    void extend (vector b){ //объединение векторов без удаления вектора, принимаемого как аргумент
       int quantity_1 = quantity;
       int quantity_2 = b.get_quantity();
       int new_size = size + b.get_size();
    double* temp = new double [new_size];
    for (int i = 0; i < quantity_1; i++){
        temp[i] = data[i];
        quantity++;
    }
    for(int i = quantity_1; i < quantity_1 + quantity_2; i++){
    temp[i] = b[i];
    quantity++;
    }
    delete[] data;
    data = temp;
    }

    double pop(){
    double* temp = new double[size];
    for (int i = 0; i < quantity - 1; i++)
        temp[i] = data[i];
    double a = data[quantity - 1];
    delete[] data;
    data = temp;
    quantity--;
    return a;
    }



    void erase(int i){
        for (int c = i; c < quantity - 1; c++)
            data[c] = data[c + 1];
            data[quantity - 1] = 0;
        quantity--;
        }

        void insert (int p, double n){ //позиция и элемент
            int new_size;
            if (quantity == size)
                new_size = 2*size;
            else
                new_size = size;
            double* temp = new double [new_size];
            for (int i = 0; i < p; i++)
                temp[i] = data[i];
            temp[p] = n;
            if (p != quantity - 1)
            for (int i = p+1; i < quantity; i++)
            temp[i] = data[i];
            size = new_size;
            quantity++;
            }

            void clear(){
            for (int i = 0; i < quantity; i++)
                data[i] = 0;
                quantity = 0;
            }


};

int main()
{

}
