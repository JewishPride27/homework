#include <iostream>
#include <vector>
using namespace std;

int main(){
int n;
cin >> n;
vector <int> a;

for (int i = 0; i < n; i++){
        int temp;
      cin >> temp;
        int d = temp;
        int counter_1 = 0;
        int counter_2 = 0; 
        for (int j = 2; j <= d; j++) {
                  if (d % j == 0){
                      while(d % j == 0){
                        d/=j;
                        counter_2++;
                      }
            counter_1++;
                  }
                  }

            if (counter_1 <= 2 && counter_2 != 1 && temp != 1){
                    a.push_back(temp);
            }
            }
            if (a.size() == 0){
                cout << 1;
            }
            int b;
            for (int i = 1; i <= a.size(); i++){
                a[i]*=a[i - 1];
                }
                cout << a.back();
return 0;
}







