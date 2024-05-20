// Challenge14

#include <iostream>
#include "Mystring.h"

int main()
{	
    Mystring str2 = "abc ";

    str2 *= 4;
    std::cout << str2 << std:: endl;
    ++str2;
    std::cout << str2 << std:: endl;
    str2 = -str2;
    std::cout << str2 << std::endl;
    str2++;
    std::cout << str2 << std::endl;

    return 0;
}