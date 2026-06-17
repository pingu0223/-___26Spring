#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int BFS(vector<vector<int>>& matrix,vector<vector<bool>>& v,int i,int j){
    int n=matrix.size();int m=matrix[0].size();
    int C=0;
    queue<pair<int,int>> q;q.push({i,j});v[i][j]=true;
    while(!q.empty()){
        pair<int,int>curr= q.front();q.pop();
        int i=curr.first;int j=curr.second;
        for(int p=0;p<4;p++){
            int ii=i+dir[p][0];int jj=j+dir[p][1];
            if(ii<0||jj<0||ii>=n||jj>=m) {C++;continue;}
            if(v[ii][jj]==true) continue;
            if(matrix[ii][jj]==0) {C++;continue;}
            q.push({ii,jj});
            v[ii][jj]=true;
        }
    }
    return C;

}
int main(){
    int n{0},m{0};
    cin>>n>>m;
    vector<vector<int>> matrix;
    vector<vector<bool>> visited;
    for(int i=0;i<n;i++){
        vector<int> M;
        vector<bool> V;
        for(int j=0;j<m;j++){
            int value{0};
            cin>>value;
            M.push_back(value);
            V.push_back(false);
        }
        matrix.push_back(M);
        visited.push_back(V);
    }
    int C=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]||matrix[i][j]==0) continue;
            cout<<BFS(matrix,visited,i,j);return 0;
        }
    }
}
