#include <iostream>
using namespace std;

int main(){
    for (int b = 0; b <= 9; b++)
        for (int j = 0; j <= 9; j++)
          for (int h = 0; h <= 9; h++)
            for (int f = 0; f <= 9; f++)
              for (int d = 0; d <= 9; d++)
                for (int l = 0; l <= 9; l++)
    if ((b + j + h + l + d + f) == 21)
        for (int c = 0; c <= 9; c++)
          for (int i = 0; i <= 9; i++)
            if((c + i + f + l) % 11 ==0)
                    for (int k = 0; k <= 9; k++)
                      if ((k + j + l) % 3 == 0)
                            for (int e = 0; e <= 9; e++)
                              for (int g = 0; g <= 9; g++)
                                 for (int a = 0; a <= 9; a++)
                          if ((a + b + c) % 2 == 0)
                                cout << a << b << c << d << e << f << g << h << i << j << k << l << endl;



    return 0;
}

