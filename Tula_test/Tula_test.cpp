
#include <iostream>
#include "BatleFromation.h"




int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    std::cout << "Введите кол-во бронемашин (от 1 до 6): ";

    std::cin >> n;
    if (n > 0 && n < 7)
    {
        CreateBatlleMap ArmoredCars(n);

       

        return 0;
    }
    else
    {
        std::cout << " Вы ввели не верное кол-во бронемашин!\n";
        std::cout << " Попробуйте начать сначала.\n";
        return 0;
    }

}