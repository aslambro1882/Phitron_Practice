#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 2, 4, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                a[j] = -1;
            }
            cout << i << " " << j << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}