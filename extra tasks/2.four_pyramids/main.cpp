#include <iostream>

//������� ������ ��������� �����: �������� ������ �������, ����� ���� ��������
//�� ��������, ����� ����������, ������� ������ �������� ����� �����
//(��������, �������� ������� 4 ����� 2 �����, ������� 5 - 3 �����),
//����� ���������� ������� ���������� ��������, ������� �������� ������ ���������� �����.
//����� ������� ���������� �������� ������ 4 ���� ���������� � main() � ������ ���������



void createLevel(int array[500][500], int x, int y, int x_length, int y_length, int filler) //������� ���� ���� ��������. x � y - ���������� �����, �� ������� ���� ���������� "�����"
{

    int j = x;
    int i;
    for (i = y; i < y_length; i++) //���������� ����� ������� ��������
        array[i][j] = filler;
        j = x_length - 1;
    for (i = y; i < y_length; i++) //���������� ������ �������
        array[i][j] = filler;
        i = y_length - 1;
    for (j = x; j < x_length; j++) //���������� ������ �������
        array[i][j] = filler;
        i = y;
        for (j = x; j < x_length; j++) //���������� ������� �������
        array[i][j] = filler;

}

void createPyramid (int array[500][500], int number_of_levels, int x, int y, int length)
{

    int x_length = length; //y_length � x_length �����, �����, ���� ���������� �� �����, "�����" ��� ����� ����������� ���������� �������. ��������, ��� y = x = 0 � ������� 4
    int y_length = length;//��� ����� ����� ����������� ���������, � ��� y = 0 � x = 4 ����� 4 ��� �� ����� ��������������� ������� �����,
    if (x > y) //� "�����" �� ����������, ������� ����� ����� ��������� � 2 ����
        x_length *= 2;
    else if (x < y)
        y_length *= 2;

    int filler = 1;
        for (int c = 1; c <= number_of_levels; c++){ //���������� "������"
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
    if (n % 2 == 0) //�������� ���������� ������
        lvls = n/2;
    else
        lvls = n/2 + 1;

        createPyramid(bricks, lvls, 0, 0, n);
        createPyramid(bricks, lvls, 0, n, n);
        createPyramid(bricks, lvls, n, 0, n);
        createPyramid(bricks, lvls, n, n, 2*n);

        for (int i = 0; i < 2*n; i++){ //�����
        for (int j = 0; j < 2*n; j++)
            std::cout << bricks[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;

}
