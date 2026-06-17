#include <iostream>
#include <vector>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
bool DFS_fir(vector<vector<int>>& matrix,vector<vector<bool>>& v,int i,int j,int n,int m){
    if(i<0||j<0||i>=n||j>=m) return false;
    v[i][j]=true;
    if(i==0||j==0) return true;
    int flag=0;
    for(int p=0;p<4;p++){
        int ii=i+dir[p][0];int jj=j+dir[p][1];
        if(ii<0||jj<0||ii>=n||jj>=m) continue;
        if((matrix[i][j]<matrix[ii][jj])||v[ii][jj]) continue;
        if(DFS_fir(matrix,v,ii,jj,n,m)) {flag=1;break;}
    }
    if(flag==1) return true;
    else return false;
}
bool DFS_sec(vector<vector<int>>& matrix,vector<vector<bool>>& v,int i,int j,int n,int m){
    if(i<0||j<0||i>=n||j>=m) return false;
    v[i][j]=true;
    if(i==n-1||j==m-1) return true;
    int flag=0;
    for(int p=0;p<4;p++){
        int ii=i+dir[p][0];int jj=j+dir[p][1];
        if(ii<0||jj<0||i>=n||j>=m) continue;
        if((matrix[i][j]<matrix[ii][jj])||v[ii][jj]) continue;
        if(DFS_sec(matrix,v,ii,jj,n,m)) {flag=1;break;}
    }
    if(flag==1) return true;
    else return false;
}
int main(){
    int n{0},m{0};
    cin>>n>>m;
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int> M;
        for(int j=0;j<m;j++){
            int value{0};
            cin>>value;
            M.push_back(value);
        }
        matrix.push_back(M);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<vector<bool>>visited(n,vector<bool>(m,false));
            if(i==0||j==0||DFS_fir(matrix,visited,i,j,n,m)){
            for(auto& row: visited){
                fill(row.begin(),row.end(),false);
            }
             if(j==m-1||i==n-1||DFS_sec(matrix,visited,i,j,n,m))cout<<i<<" "<<j<<'\n';
            }
        }
    }
}
