// Challenge14

#include <iostream>
#include "Mystring.h"

int main()
{	
    std::cout << std::boolalpha;
    Mystring str1 = "Hello, ";
    Mystring str2 = "World!";

    str1 += str1 + str2;
    std::cout << str1 << std:: endl;
    /*str1.display();*/

    return 0;
}