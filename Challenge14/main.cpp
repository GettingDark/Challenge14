// Challenge14

#include <iostream>
#include "Mystring.h"

int main()
{	
    std::cout << std::boolalpha;
    Mystring str1 = "Antonio";
    Mystring str2 = "Antonio";

    std::cout << (str1 > str2) << std:: endl;
    str1.display();

    return 0;
}