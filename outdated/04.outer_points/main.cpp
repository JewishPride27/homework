#include <iostream>

void outerPoints (int n, int m)
{

    long int points[m];
    int on_hwmny_sgmnts[m];

    for (int i = 0; i < m; i++) //�� ��������� ����� �� ����� �� ���� ��������
        on_hwmny_sgmnts[i] = n;

    for (int i = 0; i < m; i++) //������ ���������� �����
        std::cin >> points[i];

        for (int i = 0; i < n; i++){ //���� ��������� ��������
                long int segment_start, segment_end;
        std::cin >> segment_start >> segment_end;
        for (int j = 0; j < m; j++) //���������� ����� � ���������, ����� �� ������ �� ������ �������
        if (points[j] >= segment_start && points[j] <= segment_end)
            on_hwmny_sgmnts[i]--;
            }

        for (int i = 0; i < m; i++) //�����
            std::cout << on_hwmny_sgmnts[i] << " ";

}

int main()
{
    int n, m;
    std::cin >> n >> m;
    outerPoints(n, m);
    return 0;

}
