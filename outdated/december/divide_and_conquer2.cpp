#include <iostream>
#include <vector>



void QuickSort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int t;
    int p = arr[(low+high)/2];
    while (i <= j){
            while (arr[i] < p)
            i++;
            while (arr[j] > p)
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
    unsigned k;
    std::cin >> n;
    std::cin >> k;
    if (k > n || k == 0)
        std::cout << "Bad Request";
    std::vector <int> arr(n);
    for (int i = 0; i < n; i++ )
        std::cin >> arr[i];
        QuickSort(arr.data(), 0, n - 1);
        std::cout << arr[k - 1];
        return 0;
}




