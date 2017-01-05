#include <iostream>
#include <math.h> //sqrt



void clean_array (int *&array, int &size) //делаем ссылки на аргументы, чтобы они были изменены, а не просто копировались
{

    int *temp_array = new int [size]; //мы будем перемещать все составные элементы в этот массив
    for (int i = 0; i < size; i++) //инициализируем временный массив нулями, т.к. это позволяет избежать различных проблем при передаче элементов из исходного массива в этот
        temp_array[i] = 0;

    for (int i = 0; i < size; i++){ //перебор массива array
       int counter = 0; //счетчик для нахождения простых чисел
    for (int j = 2; j <= sqrt(array[i]); j++) //проверка на простоту
            if (array[i] % j == 0)
            counter++;
            if (counter != 0 || array[i] == 2) //если число составное или простое четное
            temp_array[i] = array[i];
            }

            delete []array;
            array = new int ();
            int k = 0; //нумерование конечного массива и по совместительству его размер
            for (int i = 0; i < size; i++)
                if (temp_array[i] != 0){
                    array[k] = temp_array[i];
                k++;
                }
                size = k;

}




int main()
{

    int n;
    std::cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    clean_array(a, n);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    return 0;

}
