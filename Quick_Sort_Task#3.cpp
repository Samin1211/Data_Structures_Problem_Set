#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int swapCounter = 0;

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
            swapCounter++;
        }
    }
    swap(vec[i + 1], vec[high]);
    swapCounter++;
    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
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
    quickSort(0, vec.size() - 1);
    cout << "Sorted Array: ";
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Total Swaps: " << swapCounter << endl;
    return 0;
}