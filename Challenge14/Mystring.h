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
    Mystring operator+(const Mystring& rhs) const;
    Mystring& operator+=(const Mystring& rhs);
    Mystring operator*(int value) const;
    Mystring& operator*=(int value);

    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;
    bool operator<(const Mystring& rhs) const;
    bool operator>(const Mystring& rhs) const;

    void display() const;

    int get_length() const;
    const char* get_str() const;
};