#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    long n;
    long N;

    cin >> n >> N;
    vector<long> AList(n + 1);

    AList[0] = 0;

    for (long i = 1; i <= n; ++i)
    {
        cin >> AList.at(i);
    }

    long sum = 0;
    long fi = 0;
    for (long i = 0, j = 1; j <= n; ++j, ++i)
    {
        sum += fi * (AList[j] - AList[i]);
        ++fi;
        if (j == n && N > n)
        {
            sum += fi * (N - AList[j]);
        }
    }

    cout << sum;

    return EXIT_SUCCESS;
}
