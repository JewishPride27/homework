#include <iostream>

//порядок работы программы таков: вводится размер массива, затем идет проверка
//на четность, чтобы определить, сколько этажей пирамида будет иметь
//(например, пирамида размера 4 имеет 2 этажа, размера 5 - 3 этажа),
//затем вызывается функция построения пирамиды, которая вызывает функию построения этажа.
//затем функция построения пирамиды просто 4 раза вызывается в main() и массив выводится



void createLevel(int array[500][500], int x, int y, int x_length, int y_length, int filler) //создаем один этаж пирамиды. x и y - координаты точки, от которой идет построение "стены"
{

    int j = x;
    int i;
    for (i = y; i < y_length; i++) //заполнение левой стороны квадрата
        array[i][j] = filler;
        j = x_length - 1;
    for (i = y; i < y_length; i++) //заполнение правой стороны
        array[i][j] = filler;
        i = y_length - 1;
    for (j = x; j < x_length; j++) //заполнение нижней стороны
        array[i][j] = filler;
        i = y;
        for (j = x; j < x_length; j++) //заполнение верхней стороны
        array[i][j] = filler;

}

void createPyramid (int array[500][500], int number_of_levels, int x, int y, int length)
{

    int x_length = length; //y_length и x_length нужны, чтобы, если координаты не равны, "стена" все равно заполнялась правильным образом. например, при y = x = 0 и размере 4
    int y_length = length;//обе стены будут заполняться правильно, а при y = 0 и x = 4 длина 4 уже не будет соответствовать условию цикла,
    if (x > y) //и "стена" не заполнится, поэтому длину нужно увеличить в 2 раза
        x_length *= 2;
    else if (x < y)
        y_length *= 2;

    int filler = 1;
        for (int c = 1; c <= number_of_levels; c++){ //заполнение "этажей"
    createLevel (array, x, y, x_length, y_length, filler);
    x_length--;
    y_length--;
    x++;
    y++;
    filler++;
    }

}






int main()
{

    int n;
    std::cin >> n;
    int bricks[500][500];

    int lvls;
    if (n % 2 == 0) //выясняем количество этажей
        lvls = n/2;
    else
        lvls = n/2 + 1;

        createPyramid(bricks, lvls, 0, 0, n);
        createPyramid(bricks, lvls, 0, n, n);
        createPyramid(bricks, lvls, n, 0, n);
        createPyramid(bricks, lvls, n, n, 2*n);

        for (int i = 0; i < 2*n; i++){ //вывод
        for (int j = 0; j < 2*n; j++)
            std::cout << bricks[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;

}
