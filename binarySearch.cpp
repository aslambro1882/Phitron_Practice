#include <bits/stdc++.h>

using namespace std;

void make_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}
int binary_search(int *arr, int x, int lb, int ub)
{

    if (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        // x == arr[MID]
        if (x == arr[mid])
            return mid;
        else if (x > arr[mid])
            binary_search(arr, x, mid + 1, ub);
        else
            binary_search(arr, x, lb, mid - 1);
    }
    else
        return -1;
}

int main()
{

    int size, checkValue, result;
    cin >> size;
    int arr[size];

    make_array(arr, size);

    cout << "Enter the value you want to search: ";
    cin >> checkValue;

    result = binary_search(arr, checkValue, 0, size - 1);
    if (result == -1)
        cout << "Not found this value" << endl;
    else
        cout << result << endl;

    return 0;
}