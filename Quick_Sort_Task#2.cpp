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

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    int pivot;
    cin >> pivot;

    int pivotIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == pivot)
        {
            pivotIndex = i;
            break;
        }
    }
    if (pivotIndex == -1)
    {
        cout << "Pivot not found" << endl;
        return 0;
    }
    swap(vec[pivotIndex], vec[n - 1]);
    int pi = partition(0, vec.size() - 1);
    cout << "Partitioned Array: ";
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Pivot Final Index: " << pi << endl;
    return 0;
}