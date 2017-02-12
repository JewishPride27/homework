#include <iostream>



void incredibleSort (unsigned long int N, int k)
{

  int array[N];
  for (unsigned long int i = 0; i < N; i++) //заполнение массива
    std::cin >> array[i];

    int temp[k];
 for (int i = 0; i < k; ++i) //заполнение нулями временного массива
    temp[i] = 0;

  for (unsigned long int i = 0; i < N; ++i) //каждый введенный элемент становится индексом временного массива,
    temp[array[i]]++; //а "ячейка", которая по этому индексу находится, инкреминируется

    int index = N - 1;
  for (int variable_value = 0; variable_value < k; variable_value++) //перебор значений элементов, которые могут быть в массиве
    for (int c = temp[variable_value]; c > 0; c--){ //если такого значения не всречается, этот цикл не выполняется, если
            //встречается - этот цикл выполняется до тех пор, пока элемент не перестанет встречаться.
      array[index] = variable_value; //так как мы сделали введенные элементы индексами "ячеек", эти индексы мы и перелаем в основной массив
      index--;
    }

      for (unsigned long int i = 0; i < N; i++) //вывод
      std::cout << array[i] << " ";

}


int main()
{

    unsigned long int n;
    std::cin >> n;
    int k;
    std::cin >> k;
    incredibleSort (n, k);
    return 0;

}
