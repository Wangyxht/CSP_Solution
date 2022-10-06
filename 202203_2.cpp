//以下代码全部测试用例可以通过
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);

    vector<int> ans(2 * pow(10, 5) + 1, 0);

    int n; //出行计划数目
    int m; //查询个数
    int k; //等待核酸检测结果时间
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int t, c;
        cin >> t >> c;
        int minRange = max(0, t - c - k + 1);
        int maxRange = min(t - k, (int)(2 * pow(10, 5)));
        for (int j = minRange; j <= maxRange; ++j)
        {
            ++ans[j];
        }
    }

    vector<int> target;

    for (int i = 0; i < m; ++i)
    {
        int q;
        cin >> q;
        target.push_back(q);
    }

    for (int q : target)
    {
        cout << ans[q] << endl;
    }

    return EXIT_SUCCESS;
}

//以下代码：O(n^2)，70分
/*
struct DList
{
    vector<int> TravelTime;
    vector<int> Request;
};

int main(int argv, char *argc[])
{
    ios::sync_with_stdio(false);

    int n; //出行计划数目
    int m; //查询个数
    int k; //等待核酸检测结果时间

    cin >> n >> m >> k;

    DList TravelList;
    vector<int> TestTime;

    for (int i = 0; i < n; ++i)
    {
        int t; //进入场所时刻
        int c; //所需要核酸时间
        cin >> t >> c;
        TravelList.TravelTime.push_back(t);
        TravelList.Request.push_back(c);
    }

    for (int i = 0; i < m; ++i)
    {
        int q; //在q时刻做核酸检测的一次查询
        cin >> q;
        TestTime.push_back(q);
    }

    for (auto it1 = TestTime.cbegin(); it1 != TestTime.cend(); ++it1)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (*it1 + k <= TravelList.TravelTime[i] && *it1 + k > TravelList.TravelTime[i] - TravelList.Request[i])
            {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return EXIT_SUCCESS;
}
*/