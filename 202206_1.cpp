#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n; //题目数量
    int m; //数字
    cin >> n >> m;
    vector<int> correctList(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int b;
        cin >> b;
        correctList.at(i) = b;
    }

    vector<int> Clist(n);
    Clist.at(0) = 1;
    for (int i = 1; i < n; ++i)
    {
        Clist.at(i) = Clist.at(i - 1) * correctList.at(i);
    }

    vector<int> Blist(n + 1);
    Blist.at(0) = 0;
    int sumB = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
        {
            Blist.at(i) = (m - sumB) / Clist.at(i - 1);
            cout << Blist.at(i) << " ";
        }
        else
        {
            Blist.at(i) = (m % Clist.at(i) - Blist.at(i - 1)) / Clist.at(i - 1);
            sumB += Clist.at(i - 1) * Blist.at(i);
            cout << Blist.at(i) << " ";
        }
    }

    return EXIT_SUCCESS;
}
