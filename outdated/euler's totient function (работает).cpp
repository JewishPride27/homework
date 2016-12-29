#include <iostream>


using namespace std;

int main () {
    int n, m;
    cin >> n;
    m = n;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
                n/= i;
                  m-=m/i;
        }
    }
    if (n > 1)
    {
    m-=m/n;
    cout << m;
    }
    return 0;
}
