#include <iostream>
using namespace std;

int strange_multiply(int a, int b){
    if (a < b){
        int c;
    c = a;
    a = b;
    b = c;
    }

    for (int i = 1; i < b; i++ ){
        a += a;
    }
    return a;
}


int main(){
    int c, d;
    cin >> c >> d;
    cout << strange_multiply(c, d);
    return 0;
}
