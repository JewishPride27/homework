#include <iostream>
#include <vector>

bool isItPrime(int number)
{
    for(int i=2; i*i <= number; i++)
        if(number%i==0)
            return false;
    return true;
}

int binPow (int number, int p) //используем быстрое возведение в степень
{

    if (p == 0) //точка остановки рекурсии
        return 1;
        if (p % 2 == 0){ //четная степень сводится к двое меньшей
            int temp = binPow(number, p/2);
        return temp*temp;
        }
    else
    {
        return binPow(number, p - 1) * number; //переход к четной степени

    }

}




int main()
{

    int n;
    std::cin >> n;
    std::vector <int> array;
    for (int i = 0; i < n; i++){ //вводим числа и заполняем массив простыми
            int temp;
            std::cin >> temp;
            if (isItPrime(temp)){ //если число простое, возводим его в куб и добавляем в массив
                temp = binPow(temp, 3);
            array.push_back(temp);
            }
    }
for (int i = 1; i < array.size(); i++) //сложение элементов массива
        array[i] += array[i - 1];
std::cout << array[array.size() - 1];
return 0;

}
