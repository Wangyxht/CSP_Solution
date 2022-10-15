#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int n; //购物车图书数量
    int x; //包邮条件
    int ans;
    cin >> n >> x;
    vector<int> Price((int)(3e5 + 1), 0);

    for (int i = 1; i <= n; ++i)
    {
        int p; //价格
        cin >> p;
        for (int j = (int)3e5; j >=0 ; --j)
        {
            if (Price.at(j) == 1)
            {
                Price[j + p] = 1;
            }
        }
        Price.at(p) = 1;
    }

    for (int i = x; i < (int)3e5; ++i)
    {
        if (Price.at(i) == 1)
        {
            ans = i;
            break;
        }
    }

    cout << ans;

    return EXIT_SUCCESS;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Sum(51);

void DFS(const vector<int> price, int start, int sum, int x, int& ans)
{
    if (sum + Sum[price.size() - 1] - Sum[start -1] < x)//如果现有和加后缀和小于包邮条件，直接剪枝
    {
        return;
    }

    if (ans == x)//包邮条件等于结果，直接返回
    {
        return;
    }

    if (sum >= x)//如果∑大于包邮条件
    {
        ans = ans >= sum ? sum : ans;//更新结果
    }

    if (start == price.size())//读取到尾部，返回
    {
        return;
    }

    DFS(price, start + 1, sum + price.at(start), x, ans);//取start继续DFS
    DFS(price, start + 1, sum, x, ans);//不取start继续DFS

    return;
}

int main(int argc, char* argv[])
{

    vector<int> Price(1, 0);

    Sum.at(0) = 0;
    int ans = INT_MAX;
    int n; //购物车图书数量
    int x; //包邮条件

    cin >> n >> x;

    for (int i = 1; i <= n; ++i)
    {
        int p; //价格
        cin >> p;
        Price.push_back(p);
        Sum[i] = Price[i] + Sum[i - 1];//前缀和数组
    }

    DFS(Price, 1, 0, x, ans);//深度优先遍历列表
    cout << ans;

    return EXIT_SUCCESS;
}

*/