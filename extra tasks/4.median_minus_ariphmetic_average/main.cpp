#include <iostream>


void quickSort (int *arr, int low, int high) { //���������� ������� ���������� �������
    int i = low; //�������������� �������� ��� �������� �������� �������
    int j = high;
    int temp;
    int pivot = arr[(low+high)/2]; //���������� �������, ������������ ���������� �������
    while (i <= j){ //���� �����������, ����� ��������� ����� ��������� �� ���� � ��� �� �������
            while (arr[i] < pivot) //���� ������� ������ ����������, �� ��� ������ � ��� ����� ������ ���������, ������� ��� �� ������
            i++;
            while (arr[j] > pivot)//����������, �� ��� �� ���� �� ���������, ������� �����������
            j--;
            if (i <= j){ //���� ������� ��������, ���� �� ������� ������ �����������, ������ - ������ (���� �� �� �����), �� ������ �� �������
                 temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            }
    if (low < j) //���������, ���� �� �������� ��������� �� ����� ����������
        quickSort(arr, low, j);
        if (i < high)
        quickSort (arr, i, high);
    }



    int ariphmeticAverage (int *arr, int length) //���� ������� ��������������
    {
        for (int i = 1; i < length; i++) //���������� ������ ���� �� ������ �������� � ���������� ���������, ���������� �� ���������� ���������
            arr[i]+=arr[i - 1];
        return arr[length - 1]/length;

    }



int main()
{

    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) //���������� �������
        std::cin >> array[i];
        quickSort (array, 0, n - 1); //��������� ������, ����� ����� �������
        int median;
        if (n % 2 == 0) //������� ��� ������� � ��������� ������� �������
            median = array[n/2] + array[n/2 + 1];
        else
            median = array[n/2 + 1];
            int remainder = median - ariphmeticAverage(array, n); //��������
            std::cout << remainder;
            return 0;

}
