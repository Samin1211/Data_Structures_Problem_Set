#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int partition(int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        cout << "Final Index of Pivot: " << pi << endl;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    int low = 0;
    int high = vec.size() - 1;
    quickSort(low, high);
    cout << "Sorted Array: ";
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}