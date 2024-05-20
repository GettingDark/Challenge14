#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include "Mystring.h"

Mystring::Mystring()
    : str{ nullptr } 
{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char* s)
    : str{ nullptr } 
{
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring& source)
    : str{ nullptr } 
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

Mystring::Mystring(Mystring&& source)
    :str(source.str) 
{
    source.str = nullptr;
}

Mystring::~Mystring() 
{
    delete[] str;
}

Mystring& Mystring::operator=(const Mystring& rhs) 
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring& Mystring::operator=(Mystring&& rhs) 
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring& Mystring::operator-()
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (std::isupper(str[i]))
        {
            str[i] = std::tolower(str[i]);
        }
    }
    return *this;
}

Mystring Mystring::operator+(const Mystring& rhs) const
{
    //int length = strlen(str) + strlen(rhs.str);   
    char* temp = new char [strlen(str) + strlen(rhs.str) + 1];
    strcpy(temp, str);
    strcat(temp, rhs.str);
    Mystring result = temp;
    delete[] temp;

    return result;
}

Mystring& Mystring::operator+=(const Mystring& rhs)
{
    return *this = *this + rhs;
}

Mystring Mystring::operator*(int value) const
{
    char* temp = new char[strlen(str) * value + 1];
    strcpy(temp, str);
    for (int i = 1; i < value; i++)
    {
        strcat(temp,str);
    }
    Mystring result(temp);
    delete[] temp;

    return result;
}

Mystring& Mystring::operator*=(int value)
{
    return *this = *this * value;
}

Mystring& Mystring::operator++()
{
    for (int i = 0; i < strlen(str); i++)
    {
        if(std::islower(str[i]))
            str[i] = std::toupper(str[i]);
    }
    return *this;
}

Mystring& Mystring::operator++(int)
{
    return *this += *this;
}

bool Mystring::operator==(const Mystring& rhs) const
{
    return (strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring& rhs) const
{
    return !(strcmp(str, rhs.str) == 0);
}

bool Mystring::operator<(const Mystring& rhs) const
{
    return (strcmp(str, rhs.str) < 0);
}

bool Mystring::operator>(const Mystring& rhs) const
{
    return (strcmp(str, rhs.str) > 0);
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}


int Mystring::get_length() const { return strlen(str); }
const char* Mystring::get_str() const { return str; }

std::ostream& operator<<(std::ostream& os, const Mystring& rhs) 
{
    os << rhs.str;
    return os;
}

std::istream& operator>>(std::istream& in, Mystring& rhs) 
{
    char* buff = new char[1000];
    in >> buff;
    rhs = Mystring{ buff };
    delete[] buff;
    return in;
}