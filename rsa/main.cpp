#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //rand()
#include <time.h> //srand




bool isPrime(int a)
{

	for (int i = 2; i <= a/2; i++)
	{
		if (a % i == 0) return false;
	}
	return true;

}

 int extEuclid (unsigned long int a, unsigned long int b, unsigned long int & x, unsigned long int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	unsigned long int x1, y1;
	 int d = extEuclid (b%a, a, x1, y1);
	x = y1 + (b / a) * x1;
	y = x1;
	return d;
}

unsigned long int binpow (unsigned long int a, unsigned long int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		unsigned long int b = binpow (a, n/2);
		return b * b;
	}
}

void keygen(unsigned long int &n, unsigned long int &q, unsigned long int &e, unsigned long int &d){

do {
    n = rand() % 100000 + 50000;
} while (!isPrime(n));
std::cout << "p = " << n << std::endl;

do {
    q = rand() % 150000 + 100000;
} while (!isPrime(q));

unsigned long int fi = (n - 1)*(q - 1);
n*=q;
unsigned long int temp;
do {
    e = rand() % fi + 1;
} while (extEuclid(e, fi, d, temp) != 1);
}


std::vector <unsigned long int> encrypt(unsigned long int e, unsigned long int n){

std::string str;
std::cout << "Enter the message to be encrypted:" << " ";
std::getline(std::cin,str);

std::vector <unsigned long int> values(str.size());
for (int i = 0; i < str.size(); i++){
    values[i] = str[i] - '0' - 49;
    std::cout << values[i] << " ";
}
std::cout << std::endl;

for(int i = 0; i < str.size(); i++)
    std::cout << str[i];
    std::cout << std::endl;

for(int i = 0; i < str.size(); i++){
    values[i] = binpow(values[i], e);
    values[i] %= n;
    std::cout << values[i] << " ";
}
std::cout << std::endl;
   return values;
}

void decrypt(unsigned long int d, unsigned long int n, std::vector <unsigned long int> message){ //не работает, почему - непонятно
    std::string str;
    std::cout << "Enter the message to be decrypted:";
    std::cout << std::endl;
    for (int i = 0; i < message.size(); i++)
        std::cout << message[i] << " ";
        std::cout << std::endl;

    for (int i = 0; i < message.size(); i++){
        message[i] = binpow(message[i], d);
        message[i] %= n;
        std::cout << message[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < message.size(); i++){
             char b = message[i] + '0' + 49;
        std::cout << b;

    }

}









int main(){
    srand(time(NULL));
    unsigned long int n, q, e, d;
    keygen (n, q, e, d);
    std::cout << "n = " << n << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "Public key:" << " " << e << std::endl;
    std::cout << "Private key:" << " " << d << std::endl;
    std::cout << std::endl;


    decrypt (d, n, encrypt(e, n));





return 0;
}
