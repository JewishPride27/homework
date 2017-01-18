#include <iostream>

void schedule (int n) //непосредственно функция
{

    int start[n];
    int finish[n];
    int lectures = 1; //одну-то лекцию посетить всегда можно

    for (int i = 0; i < n; i++) //заполнения массива. подразумевается, что массив уже отсортирован
        std::cin >> start[i] >> finish[i];

        for (int i = n - 1, j = n - 2; i >= 0; i--){ //если лекция начинается позже или в то время, когда заканчивается предыдущая, то мы можем ее посетить
        if (start[i] >= finish[j]){
        lectures++;
        }
        j--;
        }

        std::cout << lectures;



}

int main()
{

    int n;
    std::cin >> n;
    schedule(n);
    return 0;

}
