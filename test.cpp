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

    int n, k;
    cin >> n >> k;
    int arr[n], pos[n], max = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[i] = i + 1;
        if (max < arr[i])
            max = arr[i];
    }
    int seen[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (seen[i] == 0)
                if (arr[i] + arr[j] == k)
                {
                    seen[i] = -1;
                    seen[j] = -1;
                    cout << arr[i] << " + " << arr[j] << " == " << k << endl;
                    sum++;
                }
        }
    }

    cout << sum << endl;
    return 0;
}