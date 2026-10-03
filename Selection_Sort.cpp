#include <bits/stdc++.h>
using namespace std;
struct Book
{
    string title;
    string author;
    int year;
};
vector<Book> books;

bool criteriaCheck(Book a, Book b)
{
    if (a.year != b.year)
    {
        return a.year > b.year;
    }
    if (a.author != b.author)
    {
        return a.author < b.author;
    }
    if (a.title != b.title)
    {
        return a.title < b.title;
    }
    return false;
}

void selectionSort()
{
    for (int i = 0; i < books.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < books.size(); j++)
        {
            if (criteriaCheck(books[j], books[minIndex]))
            {
                minIndex = j;
            }
        }
        swap(books[i], books[minIndex]);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        Book temp;
        string line;
        getline(cin, line);
        int firstComma = line.find(',');
        int secondComma = line.find(',', firstComma + 1);
        temp.title = line.substr(0, firstComma);
        temp.author = line.substr(firstComma + 2, secondComma - firstComma - 2);
        temp.year = stoi(line.substr(secondComma + 2));
        books.push_back(temp);
    }
    selectionSort();
    for (Book b : books)
    {
        cout << b.title << ", " << b.author << ", " << b.year << endl;
    }
    return 0;
}