#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void QuickSort(float arr[], int low, int high) {
    int i = low;
    int j = high;
    int t;
    float p = arr[(low+high)/2];
    while (i <= j){
            while (arr[i] > p)
            i++;
            while (arr[j] < p)
            j--;
            if (i <= j){
                 t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i++;
                j--;
            }
            }
    if (low < j)
        QuickSort(arr, low, j);
        if (i < high)
        QuickSort (arr, i, high);
    }





int main(){
    int n;
    cin >> n;
    vector <float> arr(n);
    for (int i = 0; i < n; i++ )
        cin >> arr[i];
        QuickSort(arr.data(), 0, n - 1);

        for (float now: arr)
            cout << fixed << setprecision( 1 ) << now << " ";


return 0;
}










