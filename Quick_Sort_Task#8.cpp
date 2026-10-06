#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<int> temp;

int comparisons = 0;

void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        comparisons++;
        if (vec[i] <= vec[j])
        {
            temp[k] = vec[i];
            i++;
        }
        else
        {
            temp[k] = vec[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = vec[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = vec[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        vec[x] = temp[x];
    }
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
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
    temp.resize(vec.size());
    mergeSort(0, vec.size() - 1);
    cout << "Sorted Array: ";
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Total Comparision: " << comparisons << endl;
    return 0;
}