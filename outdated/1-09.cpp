#include <iostream>
#include <vector>

using namespace std;

void delete_duplicates(int n, vector<int> a)
{

for (int i = 0; i < a.size(); i++)
{
    for (int j = i; j < a.size(); j++)
    {
        if (j != i && a[j] == a[i])
        {
            a.erase( a.begin() + j);
            }
    }
}
for (auto now: a)
{
    cout << now << " ";
}


}


int main()
{
    int n;
    cout << "Array size: ";
    cin >> n;
    vector <int> a;
    cout << "Array: ";
    for (int i = 0; i < n; i++)
{
    int temp;
    cin >> temp;
    a.push_back(temp);
}

delete_duplicates(n, a);

return 0;
}


