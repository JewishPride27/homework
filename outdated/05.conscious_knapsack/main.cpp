#include <iostream>
#include <vector>

void quickSort (std::vector <int> &arr, std::vector <float> &arr2, std::vector <int> &arr3, int low, int high) //������� ����������, ����������� � ���� ������� �������, ������ �
//�������������� �������, ������� ��������� ������� ������ ��������������� �������� ������� �������
{

    int i = low; //�������������� �������� ��� �������� �������� �������
    int j = high;
    int temp;
    int pivot = arr[(low+high)/2]; //���������� �������, ������������ ���������� �������
    while (i <= j){ //���� �����������, ����� ��������� ����� ��������� �� ���� � ��� �� �������
            while (arr[i] > pivot) //���� ������� ������ ����������, �� ��� ������ � ��� ����� ������ ���������, ������� ��� �� ������
            i++;
            while (arr[j] < pivot)//����������, �� ��� �� ���� �� ���������, ������� �����������
            j--;
            if (i <= j){ //���� ������� ��������, ���� �� ������� ������ �����������, ������ - ������ (���� �� �� �����), �� ������ �� �������
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
    if (low < j) //��������� ��������� � ���������� ���������� �������
        quickSort(arr, arr2, arr3, low, j);
        if (i < high)
        quickSort (arr, arr2, arr3, i, high);

    }

int consciousKnapsack (int volume, int quantity) //�������
{

    std::vector <int> value_per_unit (quantity);
    std::vector <float> weight (quantity);
    std::vector <float> knapsack (quantity);
    std::vector <int> pointer (quantity);

    for (int i = 0; i < quantity; i++){ //��������� ��� � ��������� �����, ��������� �� �������� ���������, ��������� ������ � ����������� � �������� ������
                int value;
        std::cin >> weight[i] >> value;
        value_per_unit[i] = value/weight[i];
        pointer[i] = i;
        knapsack[i] = 0;

        }

    quickSort(value_per_unit, weight, pointer, 0, quantity - 1); //���������� quickSort, ����� ������������� �������� ���������
//�� ��������. ��������� ������� �����, ����� ������ �������� ��������� ���� �������������� ������� �� ���� � ������� �� ��������� � ����������� �������

    int curr_value = 0;
    int curr_weight = 0;
    int index = 0;

    while ((curr_weight + weight[index]) <= volume && index < quantity){ //���� ��������� ���� �������� ������������ ������� ����, ���� �����������.
            //������ ������� ����� ��� ������ �� ����� ��� ������ �����, ��������� ��� ������� ������ �������������
            curr_weight += weight[index];
            curr_value += (value_per_unit[index] * weight[index]);
            knapsack[pointer[index]] = 1.0;
            index++;
            }

            if (curr_weight != volume && index != quantity){ //���� �������� ���� � ����� � �������, �� ����� ���� � ����� �����
                knapsack[pointer[index]] = (volume - curr_weight)/weight[index];
                float multiplier = knapsack[pointer[index]];
                curr_value += (multiplier * (value_per_unit[index] * weight[index - 1])); //����� �� ���� ���������


            }

            for (int i = 0; i < quantity; i++) //����� ���������� �����, ������� �� �����
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
