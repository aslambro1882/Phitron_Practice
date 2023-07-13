#include <bits/stdc++.h>
using namespace std;

class Parent
{
private:
    int taka;
    int password;

public:
    Parent(int tk, int pass)
    {
        taka = tk;
        password = pass;
    }
    friend class AbburBondhu;
};
class AbburBondhu
{
public:
    int tellSecret(Parent *ptr)
    {
        return ptr->taka;
    }
};

int main()
{
    Parent pt(1500, 2345);
    AbburBondhu bondhu;
    cout << bondhu.tellSecret(&pt);

    return 0;
}