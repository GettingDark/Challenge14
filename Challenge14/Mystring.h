#pragma once

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

private:
    char* str;
public:
    Mystring();
    Mystring(const char* s);
    Mystring(const Mystring& source);
    Mystring(Mystring&& source);
    ~Mystring();

    Mystring& operator=(const Mystring& rhs);
    Mystring& operator=(Mystring&& rhs);
    Mystring operator-() const;

    bool operator==(const Mystring& rhs);
    bool operator!=(const Mystring& rhs);
    bool operator<(const Mystring& rhs);
    bool operator>(const Mystring& rhs);

    void display() const;

    int get_length() const;
    const char* get_str() const;
};