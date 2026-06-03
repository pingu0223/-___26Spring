#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int INF=1e9;
struct Edge{
    int to;
    int w;
};
struct Node{
    int val;
    int distance;
};
struct cmp{
    bool operator ()(Node a,Node b){
        return a.distance>b.distance;
    }
};
void Dijkstra(vector<vector<Edge>>&E,vector<int>&pre,vector<bool>&v,vector<int>&cnt,vector<int>&dis,int item){
    int curr=item;
    dis[item]=0;
    pre[item]=item;
    cnt[item]=1;
    priority_queue<Node,vector<Node>,cmp>pq;
    pq.push({item,0});
    while(!pq.empty()){
        Node now=pq.top();
        pq.pop();
        if(v[now.val])continue;
        v[now.val]=true;
        curr=now.val;
        for(int i=0;i<E[curr].size();i++){
            int node=E[curr][i].to;
            if(dis[node]>dis[curr]+E[curr][i].w){
                dis[node]=dis[curr]+E[curr][i].w;
                pre[node]=curr;
                pq.push({node,dis[node]});
                cnt[node]=cnt[curr];//这个说得特别好
            }
            else if(dis[node]==dis[curr]+E[curr][i].w){
                cnt[node]+=cnt[curr];//这个也特别好！
            }
        }
    }
}
int main(){
    vector<vector<Edge>> E;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        vector<Edge> x;
        E.push_back(x);
    }
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        E[a].push_back({b,w});
    }
    vector<int>pre(n+1,0);
    vector<bool>visited(n+1,false);
    vector<int>cnt(n+1,0);
    vector<int>distance(n+1,INF);
    int i;cin>>i;
    Dijkstra(E,pre,visited,cnt,distance,i);
}
