#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }
    void print()
    {
        cout << "real=" << real << " + "
             << "imaginary=" << imag << endl;
    }

    ////operator overloading syntex*********
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        // cout << "c1=>: " << real << " " << imag << endl;
        // cout << "c2=>: " << c.real << " " << c.imag << endl;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.real = real / c.real;
        temp.imag = imag / c.imag;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = real * c.real;
        temp.imag = imag * c.imag;
        return temp;
    }
    Complex operator++()
    {
        Complex temp;
        temp.real = real + 1;
        temp.imag = imag + 1;
        return temp;
    }
};

int main()
{
    Complex c1(9, 15);
    Complex c2(4, 5);
    Complex c3;
    c3 = c1 * c2;

    c3.print();

    return 0;
}