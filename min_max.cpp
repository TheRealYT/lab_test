#include <iostream>

using namespace std;

void min_max(int **ptr, int len, int target)
{
    int *arr = *ptr;

    int max = arr[0];
    for (int i = 1; i < len; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int min = max;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] > target && arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

int main()
{
    int arr[5];

    for (int &n : arr)
    {
        cout << "Enter a number: ";
        cin >> n;
    }

    cout << "Enter target num: ";
    int target;
    cin >> target;

    int **ptr;
    *ptr = arr;
    min_max(ptr, 5, target);
}