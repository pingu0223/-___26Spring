#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF=4e18;
void prim(vector<vector<long long>>&cost, int n, int start){
    //这是邻接矩阵存储法，先来判断start合不合法,稠密一般用这个方法
    if(start<1||start>n){
        cout<<"初始结点不合法"<<endl;
        return;
    }
    //我们所需要记录的：结点的parent，现有连通变量到其余结点的最短距离，以及每个结点是否被访问过
    vector<long long>parent(n+1,-1);
    vector<long long>distance(n+1,INF);
    vector<bool>visited(n+1,false);//注意是小括号哟
    int i=0;
    //先对我们的第一部分整一整！
    for(i=1;i<=n;i++){
        if(cost[start][i]<INF)//更新当前结点距离以及parent
        {distance[i]=cost[start][i];
        parent[i]=start;}
    }
    distance[start]=0;
    visited[start]=true;
    long long result=0;
    int flag=1;
    int current=start;
    while(flag==1){
        flag=0;
        long long min_d=INF;
        for(i=1;i<=n;i++){
            if(visited[i]==false){
                flag=1;
                if(distance[i]<min_d) {min_d=distance[i];current=i;}
            }
        }
        if(flag==0)break;
        if(min_d==INF){
            cout<<"Error:不连通"<<endl;
            return;
        }
        //更新更短的距离
        for(i=1;i<=n;i++){
            if(cost[current][i]<distance[i]&&visited[i]==false){
                distance[i]=cost[current][i];
                parent[i]=current;
            }
        }
        result+=distance[current];
        visited[current]=true;
        distance[current]=0;
    }
    cout<<"最小代价是："<<result<<endl;

}
