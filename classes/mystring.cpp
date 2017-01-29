#include <iostream>

class mystring
{
    char* text;
    int size;

    public:
        int length;
        mystring(int size) : length(size){
            text = new char[length + 1];
            text[length] = '\0';
        };

        ~mystring (){
        delete[] text;
        };

            int gimme_length(){ //этого метода нет в списке того, что должно быть в классе,
                //но я посчитал, что его довольно удобно использовать
            return length;
            }


        void set_symbol (int i){
            std::cin >> text[i];
        }

        void absorb_symbol (int i, char a){ //работает как set_symbol, но принимает символы не из консоли ввода
        text[i] = a;
        }

        char get_symbol(int i){
        return text[i];
        }

        //не работает

        //mystring concat(mystring s){
         //   mystring concatenated (length + s.gimme_length());
         //   for (int i = 0; i < length; i++)
           //     concatenated.absorb_symbol(i, text[i]);
          //  for (int i = length; i < (s.gimme_length() + length); i++)
         //       concatenated.absorb_symbol(i, s.get_symbol(i));
//
            //    return concatenated;
         //       }

        void print(){
            for (int i = 0; i < length; i++)
                std::cout << text[i];
        }




};



int main(){
    int length;
    std::cin >> length;

    mystring test (length);

    for (int i = 0; i < length; i++)
            test.set_symbol(i);

    for (int i = 0; i < length; i++)
        std::cout << test.get_symbol(i);
        std::cout << std::endl;

        test.print();
        std::cout << std::endl;

        std::cout << test.gimme_length();
        std::cout << std::endl;

        mystring test2 (length);

        for (int i = 0; i < length; i++)
            test2.set_symbol(i);

        //    mystring test3 (2*length);
        //    test3 = test.concat(test2);
         //   test3.print();
            return 0;
}
