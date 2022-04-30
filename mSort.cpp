#include <iostream>
#include <ctime>

using namespace std;

void arrayPrint(int n, int arrp[])
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arrp[i] << " ";
    }
}

int mSort(int n, int arr[])
{
    if (n == 1)
    {
        return 0;
    }

    int t1 = n / 2; 
    int t2 = n - t1;

    int t1array[t1];
    int t2array[t2];

    for (int i = 0; i < t1; i++)
    {
        t1array[i] = arr[i];
    }

    for (int i = t1; i < n; i++)
    {
        t2array[i - t1] = arr[i];
    }

    mSort(t1, t1array) + mSort(t2, t2array);
   
    for(int i = 0, iT1 = 0, iT2 = 0; i < n; i++)
    {
        if((t1array[iT1] <= t2array[iT2] && iT1 != t1) || iT2 == t2)
        {
            arr[i] = t1array[iT1];
            iT1++;
        }
        else if((t2array[iT2] <= t1array[iT1] && iT2 != t2) || iT1 == t1)
        {
            arr[i] = t2array[iT2];
            iT2++;
        }
    }

    return 0;
}

int main(void)
{
    int n;
    cout << "Please enter length of Array: ";
    cin >> n;

    int *array = new int[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 100;
    }

    arrayPrint(n, array);

    mSort(n, array);

    arrayPrint(n, array);
}