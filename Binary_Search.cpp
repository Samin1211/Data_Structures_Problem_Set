#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void binarySearch(int target)
{
    int low = 0, high = vec.size() - 1;
    bool flag = false;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] == target)
        {
            flag = true;
            break;
        }
        else if (vec[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag)
    {
        cout << "Book Found";
    }
    else
    {
        cout << "Book Not Found";
    }
}
int lowerBound(int target)
{
    int low = 0, high = vec.size() - 1, res = vec.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] >= target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int upperBound(int target)
{
    int low = 0, high = vec.size() - 1, res = vec.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] > target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
    int n, x, target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    cin >> target;
    binarySearch(target);
    cout << "\n";
    cout << "Lower Bound Index: " << lowerBound(target) << "\n";
    cout << "Upper Bound Index: " << upperBound(target) << "\n";
    return 0;
}