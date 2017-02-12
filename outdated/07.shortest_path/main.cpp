#include <iostream>
#include <algorithm>

void shortest_path (int width, int height) //�������
{

    int distance [height + 1][width + 1]; //������ ������� ������������ ����� ���� ("�����������")

    int parks;
    std::cin >> parks;
   bool park [height + 1][width + 1];

  for (int i = 0; i <= height; i++) //���������� ��������� � �������� ��������
        for (int j = 0; j <= width; j++){
        distance[i][j] = 0;
        park[i][j] = 0;
        }


   for (int c = 1; c <= parks; c++){ //���������� �������� �������
        int i, j;
        std::cin >> i >> j;
        j = height - j;
    park [j][i] = 1;
    }

    distance[height][0] = 0;

    for (int i = height - 1; i >= 0; i--) //���������� �� ���������
        distance[i][0] = distance[i + 1][0] + 100;


        for (int j = 1; j <= width; j++) //���������� �� �����������
          distance [height][j] = distance [height][j - 1] + 100;

          for (int i = height - 1; i >= 0; i--) //�� ��������� � ��� 2 ������� ������� � �������� �����, �� ���� �� ����� ������� � ���
          //����� �����, �� ��� ����������� �������� �� ����
            for (int j = 1; j <= width; j++){
            if (park[i][j]){ //���� � ��������� ����� ����� ������� �� �����
                distance[i][j] = std::min(std::min(distance[i + 1][j], distance[i][j - 1]), distance[i + 1][j - 1]) + 141; //141 ~= sqrt(100^2 + 100^2)
            }
            else
                distance[i][j] = std::min(distance[i + 1][j], distance[i][j - 1]) + 100;
            }

                      std::cout << distance[0][width];

}




        int main()
        {
            int n, m;
            std::cin >> n >> m;
            shortest_path(n, m);
            return 0;

        }






