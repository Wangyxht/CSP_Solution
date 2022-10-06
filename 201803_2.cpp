#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FRONT 1
#define BACK -1

struct Ball
{
    int x;
    int direction;
};

main(int argc, char *argv[])
{
    //ios::sync_with_stdio(false);

    int n; //小球的個數
    int L; //线段长度
    int t; //需要计算t s之后小球的位置
    cin >> n >> L >> t;

    vector<Ball> BallList;
    for (int i = 0; i < n; ++i)
    {
        int a; //球的初始位置
        cin >> a;
        Ball ballInf;
        ballInf.direction = FRONT;
        ballInf.x = a;
        BallList.push_back(ballInf);
    }

    for (int i = 0; i < t; i++)
    {
        for (auto it1 = BallList.begin(); it1 != BallList.end(); ++it1)
        {
            for (auto it2 = it1; it2 != BallList.end(); ++it2) //检查是否存在碰撞
            {
                if ((*it1).x == (*it2).x) //碰撞反向
                {
                    (*it1).direction = -(*it1).direction;
                    (*it2).direction = -(*it2).direction;
                }
            }

            if ((*it1).x == L || (*it1).x == 0)
            {
                (*it1).direction = -(*it1).direction;
            }

            (*it1).x += (*it1).direction;
        }
    }

    for (auto it = BallList.begin(); it != BallList.end(); ++it)
    {
        cout << (*it).x << " ";
    }

    return EXIT_SUCCESS;
}