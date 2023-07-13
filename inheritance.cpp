#include <bits/stdc++.h>
using namespace std;

class Parent
{
public:
    int x;

private:
    int y;

protected:
    int z;

public:
    Parent(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

class Child : public Parent
{
public:
    int xx;
    int yy;
    Child(int aa, int bb, int a, int b, int c) : Parent(a, b, c)
    {
        xx = aa;
        yy = bb;
        }
    int tellmeZ()
    {
        return this->z;
    }
};

int main()
{
    Parent pt(10, 20, 30);
    Child ch(100, 50, 10, 20, 30);
    cout << ch.tellmeZ() << endl;

    return 0;
}