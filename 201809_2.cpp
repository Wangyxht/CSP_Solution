/*问题描述
　　小H和小W来到了一条街上，两人分开买菜，他们买菜的过程可以描述为，去店里买一些菜然后去旁边的一个广场把菜装上车，两人都要买n种菜，所以也都要装n次车。具体的，对于小H来说有n个不相交的时间段[a1,b1],[a2,b2]...[an,bn]在装车，对于小W来说有n个不相交的时间段[c1,d1],[c2,d2]...[cn,dn]在装车。其中，一个时间段[s, t]表示的是从时刻s到时刻t这段时间，时长为t-s。
　　由于他们是好朋友，他们都在广场上装车的时候会聊天，他们想知道他们可以聊多长时间。
输入格式
　　输入的第一行包含一个正整数n，表示时间段的数量。
　　接下来n行每行两个数ai，bi，描述小H的各个装车的时间段。
　　接下来n行每行两个数ci，di，描述小W的各个装车的时间段。
输出格式
　　输出一行，一个正整数，表示两人可以聊多长时间。*/
#include <bits/stdc++.h>
using namespace std;

struct TimeList
{
    int A_status = 0;
    int B_status = 0;
};

int main(int argc, char **argv)
{
    int ans = 0;
    int maxT = 0;
    int n;
    cin >> n;

    vector<TimeList> TList(1000000 + 1);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; ++j)
        {
            TList[j].A_status = 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int c, d;
        cin >> c >> d;
        maxT = max(maxT, c);
        maxT = max(maxT, d);
        for (int j = c; j < d; ++j)
        {
            TList[j].B_status = 1;
        }
    }

    int i = 1;
    while (i <= maxT-1)
    {
        if (TList[i].A_status == 1 && TList[i].B_status == 1)
        {
            ++ans;
        }
        i++;
    }

    cout << ans;
    return EXIT_SUCCESS;
}
