#include <bits/stdc++.h>

using namespace std;

int binary_search(int *arr, int *pos, int x, int lb, int ub)
{
    if (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (x == arr[mid])
            return pos[mid];
        else if (x > mid)
            binary_search(arr, pos, x, mid + 1, ub);
        else
            binary_search(arr, pos, x, lb, mid - 1);
    }
    else
        return -1;
}

int main()
{

    return 0;
}