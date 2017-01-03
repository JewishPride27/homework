#include <iostream>
#include <math.h> //sqrt
#include <vector>
using namespace std;

void array_cleaning (int array[], int size){ //непосредственно функция

    for (int i = 0; i < size; i++){ //перебор массива
       int counter = 0;
    for (int j = 2; j <= sqrt(array[i]); j++) //проверка на простоту
            if (array[i] % j == 0)
            counter++;
    if (counter == 0 && array[i] != 2){ //если элемент простой, он заменяется идущим за ним при следующем прохождении цикла, также уменьшая свой размер
        size--;
        i--;

    }
    }
}


int main(){

    int n;
    std::cin >> n;
    int * a = new int ();
      for (int i = 0; i < n; i++)
        std::cin >> a[i];
array_cleaning(a, n);
for (int i = 0; i < n; i++)
      cout << a[i] << " ";
delete[] a;


    return 0;
}
