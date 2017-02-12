#include <iostream>
#include <vector>

bool isItPrime(int number)
{
    for(int i=2; i*i <= number; i++)
        if(number%i==0)
            return false;
    return true;
}

int binPow (int number, int p) //���������� ������� ���������� � �������
{

    if (p == 0) //����� ��������� ��������
        return 1;
        if (p % 2 == 0){ //������ ������� �������� � ���� �������
            int temp = binPow(number, p/2);
        return temp*temp;
        }
    else
    {
        return binPow(number, p - 1) * number; //������� � ������ �������

    }

}




int main()
{

    int n;
    std::cin >> n;
    std::vector <int> array;
    for (int i = 0; i < n; i++){ //������ ����� � ��������� ������ ��������
            int temp;
            std::cin >> temp;
            if (isItPrime(temp)){ //���� ����� �������, �������� ��� � ��� � ��������� � ������
                temp = binPow(temp, 3);
            array.push_back(temp);
            }
    }
for (int i = 1; i < array.size(); i++) //�������� ��������� �������
        array[i] += array[i - 1];
std::cout << array[array.size() - 1];
return 0;

}
