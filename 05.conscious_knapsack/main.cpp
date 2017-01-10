#include <iostream>
#include <vector>

void quickSort (std::vector <int> &arr, std::vector <float> &arr2, std::vector <int> &arr3, int low, int high) //быстрая сортировка, принимаюшая в себя границы массива, массив и
//дополнительные массивы, индексы элементов которых должны соответствовать индексам первого массива
{

    int i = low; //инициализируем счетчики для перебора элментов массива
    int j = high;
    int temp;
    int pivot = arr[(low+high)/2]; //поворотный элемент, выбирающийся посередине массива
    while (i <= j){ //цикл остановится, когда указатели будут указывать на один и тот же элемент
            while (arr[i] > pivot) //если элемент больше повротного, то все хорошо и нам нужно искать следующий, который был бы меньше
            i++;
            while (arr[j] < pivot)//аналогично, но тут мы идем от элементов, меньших поворотного
            j--;
            if (i <= j){ //если находим элементы, один из которых меньше поворотного, другой - больше (чего мы не хотим), мы меняем их местами
                    temp = arr3[i];
                    arr3[i] = arr3[j];
                    arr3[j] = temp;

                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            }
    if (low < j) //повторяем процедуру с остальными элементами массива
        quickSort(arr, arr2, arr3, low, j);
        if (i < high)
        quickSort (arr, arr2, arr3, i, high);

    }

int consciousKnapsack (int volume, int quantity) //функция
{

    std::vector <int> value_per_unit (quantity);
    std::vector <float> weight (quantity);
    std::vector <float> knapsack (quantity);
    std::vector <int> pointer (quantity);

    for (int i = 0; i < quantity; i++){ //заполняем вес и стоимость вещей, вычисляем их удельную стоимость, заполняем массив с указателями и конечный массив
                int value;
        std::cin >> weight[i] >> value;
        value_per_unit[i] = value/weight[i];
        pointer[i] = i;
        knapsack[i] = 0;

        }

    quickSort(value_per_unit, weight, pointer, 0, quantity - 1); //используем quickSort, чтобы отсортировать удельные стоимости
//по убыванию. остальные массивы нужны, чтобы индекс удельной стоимости вещи соответствовал индексу ее веса и индексу ее положения в изначальном массиве

    int curr_value = 0;
    int curr_weight = 0;
    int index = 0;

    while ((curr_weight + weight[index]) <= volume && index < quantity){ //если следующая вещь перейдет максимальную границу веса, цикл остановится.
            //второе условие нужно для выхода из цикла при наборе вещей, суммарный вес которых меньше максимального
            curr_weight += weight[index];
            curr_value += (value_per_unit[index] * weight[index]);
            knapsack[pointer[index]] = 1.0;
            index++;
            }

            if (curr_weight != volume && index != quantity){ //если остались вещи и место в рюкзаке, мы делим вещь и берем часть
                knapsack[pointer[index]] = (volume - curr_weight)/weight[index];
                float multiplier = knapsack[pointer[index]];
                curr_value += (multiplier * (value_per_unit[index] * weight[index - 1])); //сумму мы тоже уменьшаем


            }

            for (int i = 0; i < quantity; i++) //вывод количества вещей, которые мы взяли
                std::cout << knapsack[i] << " " ;
                std::cout << std::endl;
                return curr_value;
}

int main()
{
    int v, q;
    std::cin >> v >> q;
    std::cout << consciousKnapsack(v, q);
    return 0;

}
