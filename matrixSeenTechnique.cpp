#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{

    int r, c;
    cin >> r >> c;
    int arr[r][c], max = 0;
    // input of matrix-----------
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }

    int seen[max + 1] = {0};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (seen[arr[i][j]])
            {
                arr[i][j] = -1;
            }
            else
            {
                seen[arr[i][j]] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}