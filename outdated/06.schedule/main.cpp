#include <iostream>

void schedule (int n) //��������������� �������
{

    int start[n];
    int finish[n];
    int lectures = 1; //����-�� ������ �������� ������ �����

    for (int i = 0; i < n; i++) //���������� �������. ���������������, ��� ������ ��� ������������
        std::cin >> start[i] >> finish[i];

        for (int i = n - 1, j = n - 2; i >= 0; i--){ //���� ������ ���������� ����� ��� � �� �����, ����� ������������� ����������, �� �� ����� �� ��������
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
