#include <iostream>


void quickSort (int *arr, int low, int high) { //используем быструю сортировку массива
    int i = low; //инициализируем счетчики для перебора элментов массива
    int j = high;
    int temp;
    int pivot = arr[(low+high)/2]; //поворотный элемент, выбирающийся посередине массива
    while (i <= j){ //цикл остановится, когда указатели будут указывать на один и тот же элемент
            while (arr[i] < pivot) //если элемент меньше повротного, то все хорошо и нам нужно искать следующий, который был бы больше
            i++;
            while (arr[j] > pivot)//аналогично, но тут мы идем от элементов, бОльших поворотного
            j--;
            if (i <= j){ //если находим элементы, один из которых больше поворотного, другой - меньше (чего мы не хотим), мы меняем их местами
                 temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            }
    if (low < j) //повторяем, пока не проведем процедуру со всеми элементами
        quickSort(arr, low, j);
        if (i < high)
        quickSort (arr, i, high);
    }



    int ariphmeticAverage (int *arr, int length) //ищем среднее арифметическое
    {
        for (int i = 1; i < length; i++) //складываем идущие друг за другом элементы и возвращаем последний, поделенный на количество элементов
            arr[i]+=arr[i - 1];
        return arr[length - 1]/length;

    }



int main()
{

    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) //заполнение массива
        std::cin >> array[i];
        quickSort (array, 0, n - 1); //сортируем массив, чтобы найти медиану
        int median;
        if (n % 2 == 0) //медиана для четного и нечетного размера массива
            median = array[n/2] + array[n/2 + 1];
        else
            median = array[n/2 + 1];
            int remainder = median - ariphmeticAverage(array, n); //разность
            std::cout << remainder;
            return 0;

}
