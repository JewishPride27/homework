#include <iostream>



void incredibleSort (unsigned long int N, int k)
{

  int array[N];
  for (unsigned long int i = 0; i < N; i++) //���������� �������
    std::cin >> array[i];

    int temp[k];
 for (int i = 0; i < k; ++i) //���������� ������ ���������� �������
    temp[i] = 0;

  for (unsigned long int i = 0; i < N; ++i) //������ ��������� ������� ���������� �������� ���������� �������,
    temp[array[i]]++; //� "������", ������� �� ����� ������� ���������, ���������������

    int index = N - 1;
  for (int variable_value = 0; variable_value < k; variable_value++) //������� �������� ���������, ������� ����� ���� � �������
    for (int c = temp[variable_value]; c > 0; c--){ //���� ������ �������� �� ����������, ���� ���� �� �����������, ����
            //����������� - ���� ���� ����������� �� ��� ���, ���� ������� �� ���������� �����������.
      array[index] = variable_value; //��� ��� �� ������� ��������� �������� ��������� "�����", ��� ������� �� � �������� � �������� ������
      index--;
    }

      for (unsigned long int i = 0; i < N; i++) //�����
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
