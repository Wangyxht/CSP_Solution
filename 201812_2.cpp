/*以下代码全部测试用例通过*/
#include <bits/stdc++.h>
using namespace std;
long long n;
void RefreshTimeList(vector<pair<long long, long long>>& Timelist, int locate, vector<long long>& LightInf);
int main(int argc, char* argv[])
{
    vector<long long> LightInf(4);
    for (int i = 1; i <= 3; ++i)
    {
        cin >> LightInf.at(i);
    }

    cin >> n;

    vector<pair<long long, long long>> TimeList(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> TimeList[i].first;
        cin >> TimeList[i].second;
    }


    long long time = 0;        //总时间
    for (int i = 1; i <= n; ++i)
    {
        if (TimeList[i].first == 0)
        {
            time += TimeList[i].second;
        }
        else
        {
            TimeList[i].second %= accumulate(LightInf.cbegin()+1,LightInf.cend(),0);
            TimeList[i].second -= time;
            TimeList[i].second %= accumulate(LightInf.cbegin()+1,LightInf.cend(),0);
            RefreshTimeList(TimeList, i, LightInf);

            if (TimeList[i].first == 1) {
                time += TimeList[i].second;
            }

            else if (TimeList[i].first == 2) {
                time += TimeList[i].second + LightInf[1];
            }

            else {
                continue;
            }
        }


    }

    cout << time;
    return EXIT_SUCCESS;
}

void RefreshTimeList(vector<pair<long long, long long>>& Timelist, int locate, vector<long long>& LightInf)
{
    while (Timelist[locate].first != 0 && Timelist[locate].second <= 0)
    {
        switch (Timelist[locate].first)
        {
        case 1:
            Timelist[locate].first = 3;
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;
        case 2:
            Timelist[locate].first = 1;
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;
        case 3:
            Timelist[locate].first = 2;
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;

        default:
            break;
        }
    }
}


/*以下代码可通过70%的测试用例
#include <bits/stdc++.h>
using namespace std;
int n;
void RefreshTimeList(vector<pair<int, int>> &Timelist, int locate, vector<int> &LightInf);
int main(int argc, char *argv[])
{
    vector<int> LightInf(4);
    for (int i = 1; i <= 3; ++i)
    {
        cin >> LightInf.at(i);
    }

    cin >> n;

    vector<pair<int, int>> TimeList(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> TimeList[i].first;
        cin >> TimeList[i].second;
    }

    long long time = 0;//总时间
    for (int i = 1; i <= n; ++i)
    {
        if (TimeList[i].first == 0||TimeList[i].first == 1)//如果是通路/红灯
        {
            time += TimeList[i].second;//总时间+=通路时间/等红灯的时间
            for (int j = i + 1; j <= n; ++j)
            {
                if(TimeList[j].first != 0){
                    TimeList[j].second -= TimeList[i].second;//刷新所有后续时间
                    RefreshTimeList(TimeList, j, LightInf);//改变灯的状态
                }

            }
        }
        else if (TimeList[i].first == 2)//如果为黄灯
        {
            time += TimeList[i].second+LightInf[1];//总时间+=等黄灯红灯的时间
            for (int j = i + 1; j <= n; ++j)
            {
                if(TimeList[j].first != 0){
                    TimeList[j].second -= (TimeList[i].second+LightInf[1]);//刷新所有后续时间
                    RefreshTimeList(TimeList, j, LightInf);//改变灯的状态
                }

            }

        }
        else if(TimeList[i].first==3){
            continue;
        }
    }

    cout<<time;

    return EXIT_SUCCESS;
}

void RefreshTimeList(vector<pair<int, int>> &Timelist, int locate, vector<int> &LightInf)
{
    while (Timelist[locate].first!=0  && Timelist[locate].second <=0)
    {
        switch (Timelist[locate].first)
        {
        case 1://如果为红灯且倒计时为负
            Timelist[locate].first = 3;//切绿灯
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;
        case 2://如果为黄且倒计时为负
            Timelist[locate].first = 1;//切红灯
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;
        case 3://如果为緑且倒计时为负
            Timelist[locate].first = 2;//切黄灯
            Timelist[locate].second += LightInf[Timelist[locate].first];
            break;

        default:
            break;
        }
    }
}
*/