#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> ResultList((int)1e8+1, 0);
    vector<int> YList;
    int m; //评估人数
    int maxY=-1;
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int y;
        int result;
        cin >> y >> result;
        YList.push_back(y);
        maxY=max(maxY,y);
        if (result == 1)
        {
            ++ResultList.at(y);
        }
        else
        {
            --ResultList.at(y);
        }
    }
    for(int i=maxY-1;i>=0;--i){
        ResultList[i]+=ResultList[i+1];
    }

    auto itM=minmax_element(ResultList.begin(),ResultList.end()).second;

    while(itM>ResultList.begin()){
        if(find(YList.begin(),YList.end(),itM-ResultList.begin())!=YList.end()){
            cout<<itM-ResultList.begin();
            break;
        }
        --itM;
    }

    
    return EXIT_SUCCESS;
}