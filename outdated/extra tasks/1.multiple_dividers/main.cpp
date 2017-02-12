#include <iostream>

int main(){

    int n;
    std::cin >> n;
    int counter_1 = -1; //счетчик для заполнения массива
    int * array = new int ();
          for (int i = 0; i < n; i++){ //ввод кандидатов на попадание в массив
                int counter_2 = 0; //счетчик для нахождения нужных чисел
                int temp;
                std::cin >> temp;
            for (int j = 2; j <= temp/2; j++) //перебор чисел для нахождения делителя. так как мы ищем и составные, и простые делители, перебор идет до temp/2, а не до квадратного корня
           if (temp % j == 0)
            counter_2++;
            if (counter_2 == 4){ //условие для добавления в массив
            counter_1++;
            *(array + counter_1) = temp;

            }

    }
    if (counter_1 == -1) //в случае, если нет ни одного подходящео элемента
        std::cout << "No elements found";
        else
            for (int i = 0; i <= counter_1; i++)
        std::cout << array[i] << " ";
    delete[] array; //освобождаем память


return 0;
}
