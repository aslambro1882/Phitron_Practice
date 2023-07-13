#include <bits/stdc++.h>
using namespace std;

class Example
{
private:
    int x;
    int y;
    int z;
    int pass;

public:
    Example(int p)
    {
        pass = p;
    }
    void setter(int a, int p)
    {
        if (pass == p)
            x = a;
        else
            cout << "Cant't set. as Pass didn't match" << endl;
    }
    int getter(int p)
    {
        if (pass == p)
            return x;
        else
        {
            cout << "Cant't get. as Pass didn't match" << endl;
            return -1;
        }
    }
};

int main()
{
    Example a(1234);
    a.setter(1000, 1234);
    a.getter(1234);
    cout << a.getter(1234) << endl;

    return 0;
}