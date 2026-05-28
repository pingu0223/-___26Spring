#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
    int a;
    int b;
    int w;
    bool operator<(Edge& o){
        return w>o.w;
    }
};
struct cmp{
    bool operator()(const Edge& x,const Edge& y){
        return x.w>y.w;
    }
};
int find(int* parent,int val){
    while(parent[val]!=val){
        val=parent[val];
    }
    return val;
}
bool merge(int i,int j,int* parent){
    int a=find(parent,i);
    int b=find(parent,j);
    if(a==b) return false;
    else{
        parent[a]=b;
    }
    return true;
}
int main(){
    int N,M;
    cin>>N>>M;
    priority_queue<Edge,vector<Edge>,cmp>q;
    int parent[N+1];
    for(int i=0;i<=N;i++){
        parent[i]=i;
    }
    for(int i=0;i<M;i++){
        int a,b,w;
        cin>>a>>b>>w;
        q.push({a,b,w});
    }
    int result=0;
    for(int i=0;i<N-1;i++){
        Edge e=q.top();
        q.pop();
        if(merge(e.a,e.b,parent)){
            result+=e.w;
        }
        else{
            i--;
        }
    }
    cout<<result;
}
