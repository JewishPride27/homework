#include <iostream>

void outerPoints (int n, int m)
{

    long int points[m];
    int on_hwmny_sgmnts[m];

    for (int i = 0; i < m; i++) //по умолчанию точки не лежат на всех отрезках
        on_hwmny_sgmnts[i] = n;

    for (int i = 0; i < m; i++) //вводим координаты точек
        std::cin >> points[i];

        for (int i = 0; i < n; i++){ //ввод координат отрезков
                long int segment_start, segment_end;
        std::cin >> segment_start >> segment_end;
        for (int j = 0; j < m; j++) //перебираем точки и проверяем, лежит ли каждая на данном отрезке
        if (points[j] >= segment_start && points[j] <= segment_end)
            on_hwmny_sgmnts[i]--;
            }

        for (int i = 0; i < m; i++) //вывод
            std::cout << on_hwmny_sgmnts[i] << " ";

}

int main()
{
    int n, m;
    std::cin >> n >> m;
    outerPoints(n, m);
    return 0;

}
