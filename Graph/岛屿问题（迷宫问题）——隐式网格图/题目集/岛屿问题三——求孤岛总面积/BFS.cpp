#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int BFS(vector<vector<int>>&matrix,vector<vector<bool>>&v,int i,int j){
    int flag=0;
    int r_l=matrix.size();int c_l=matrix[0].size();
    if(i<0||i>=r_l||j<0||j>=c_l) return 0;
    if(v[i][j]||matrix[i][j]==0) return 0;
    int result=0;
    queue<pair<int,int>> q;
    q.push({i,j});v[i][j]=true;
    while(!q.empty()){
        pair<int,int>curr=q.front();q.pop();
        i=curr.first;j=curr.second;
        result++;
        if(i==0||j==0||i==r_l-1||j==c_l-1) flag=1;
        for(int b=0;b<4;b++){
            int ii=i+dir[b][0];int jj=j+dir[b][1];
            if(ii<0||ii>=r_l||jj<0||jj>=c_l)continue;
            if(v[ii][jj]||matrix[ii][jj]==0) continue;
            q.push({ii,jj});
            v[ii][jj]=true;
        }
    }
    if(flag==1) return 0;
    else return result;
}
int main(){
    int n{0},m{0};
    cin>>n>>m;
    vector<vector<int>> matrix;
    vector<vector<bool>> V;
    for(int i=0;i<n;i++){
        vector<int>M;
        vector<bool>v;
        for(int j=0;j<m;j++){
            int value{0};
            cin>>value;
            M.push_back(value);
            v.push_back(false);
        }
        matrix.push_back(M);
        V.push_back(v);
    }
    int all_S=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(V[i][j])continue;
            if(matrix[i][j]==0) continue;
            all_S+=BFS(matrix,V,i,j);
        }
    }
    cout<<all_S;
}
