#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> temp;

void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = temp[x];
    }
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> vec1(n1);
    vector<int> vec2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> vec2[i];
    }
    a.resize(n1 + n2);
    temp.resize(n1 + n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = vec1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        a[n1 + i] = vec2[i];
    }
    merge(0, n1 - 1, n1 + n2 - 1);
    cout << "Merged Array: ";
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    int total = n1 + n2;
    if (total % 2 != 0)
    {
        cout << "Median: " << a[total / 2] << endl;
    }
    else
    {
        cout << "Median: " << (a[(total - 1) / 2] + a[(total / 2)]) / 2.0 << endl;
    }
    return 0;
}