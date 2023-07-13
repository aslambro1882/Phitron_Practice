#include <bits/stdc++.h>

using namespace std;

class Example
{

public:
    int add(int a, int b)
    {
        cout << "Called from int: " << a + b << endl;
    }
    double add(double a, double b)
    {
        cout << "Called from double plus: " << a + b << endl;
    }
    int add(int a, double b)
    {
        cout << "Called from int+double: " << a + int(b) << endl;
    }
};

int main()
{

    Example a;
    a.add(234.3434, 45.3434);

    return 0;
}