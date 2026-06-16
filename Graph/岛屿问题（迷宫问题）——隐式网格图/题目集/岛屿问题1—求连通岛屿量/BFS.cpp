#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int BFS(vector<vector<int>>& E,vector<vector<bool>>& v,int i,int j){
    queue<pair<int,int>> x;
    int r_l=E.size();
    if(r_l==0) return 0;
    int c_l=E[0].size();
    if(i<0||i>=r_l||j<0||j>=c_l) return 0;
    if(v[i][j]||E[i][j]==0) return 0;
    pair<int,int> a=make_pair(i,j);
    x.push(a);v[i][j]=true;
    while(!x.empty()){
        pair<int,int>curr={x.front().first,x.front().second}; x.pop();
        i=curr.first;j=curr.second;
        for(int b=0;b<4;b++){
            if(i+dir[b][0]<0||i+dir[b][0]>=r_l||j+dir[b][1]<0||j+dir[b][1]>=c_l) continue;
            if(v[i+dir[b][0]][j+dir[b][1]])continue;
            if(E[i+dir[b][0]][j+dir[b][1]]!=0){
                x.push({i+dir[b][0],j+dir[b][1]});
            }
            v[i+dir[b][0]][j+dir[b][1]]=true;
        }
    }
    return 1;
}
int main(){
    int n{0},m{0};
    cin>>n>>m;
    vector<vector<int>> E;
    vector<vector<bool>>visited;
    for(int i=0;i<n;i++){
        vector<int> e;
        vector<bool> b;
        for(int j=0;j<m;j++){
            int value{0};
            cin>>value;
            e.push_back(value);
            b.push_back(false);
        }
        E.push_back(e);
        visited.push_back(b);
    }int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result+=BFS(E,visited,i,j);
        }
    }
    cout<<result;
}
