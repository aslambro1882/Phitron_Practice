#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    // input array size----------t
    cin >> n;
    int arr[n], final[n], max = 0;
    // input array and find max------------
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    int count[max + 1] = {0};
    // frequency calculation--------------
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // printArray(count, max + 1);
    // cout << endl;
    // cumolative frequency calculation---------
    for (int i = 1; i < max + 1; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    // printArray(count, max + 1);
    // cout << endl;

    // making final array----------
    for (int i = n - 1; i >= 0; i--)
    {
        int k;
        count[arr[i]]--;
        k = count[arr[i]];
        final[k] = arr[i];
        // or
        //  final[--count[arr[i]]] = arr[i];
    }
    printArray(final, n);
    return 0;
}