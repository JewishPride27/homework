#include <iostream>

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

    void append (int new_size){
    double* temp = new double [new_size];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];
        delete[] data;
        data = temp;
        size = new_size;
    }

    const int& operator[](int i){
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

    void merge (vector b){
       int quantity_1 = quantity;
       int quantity_2 = b.get_quantity();
       int new_size = size + b.get_size();
    double* temp = new double [size];
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

    int pop_back(){
    double* temp = new double[size];
    for (int i = 0; i < quantity - 1; i++)
        temp[i] = data[i];
    double a = data[quantity - 1];
    delete[] data;
    data = temp;
    quantity--;
    return a;
    }
};

int main()
{

    return 0;
}
