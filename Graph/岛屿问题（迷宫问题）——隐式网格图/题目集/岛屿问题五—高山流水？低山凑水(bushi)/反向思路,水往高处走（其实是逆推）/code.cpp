#include <iostream>
#include <vector>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
void DFS(vector<vector<int>>&matrix,vector<vector<bool>>& v,int i,int j){
    int n=matrix.size();int m=matrix[0].size();
    if(i<0||j<0||i>=n||j>=m) return;
    if(v[i][j]) return;
    v[i][j]=true;
    for(int p=0;p<4;p++){
        int ii=i+dir[p][0];int jj=j+dir[p][1];
        if(ii<0||jj<0||ii>=n||jj>=m) continue;
        if(v[ii][jj]||matrix[ii][jj]<matrix[i][j]) continue;
        DFS(matrix,v,ii,jj);
    }
    return;
}
int main(){
    int n{0},m{0};
    cin>>n>>m;
    vector<vector<int>> matrix;
    vector<vector<bool>>visited_fir;
    vector<vector<bool>>visited_sec;
    for(int i=0;i<n;i++){
        vector<int> M;
        vector<bool> v1;
        vector<bool> v2;
        for(int j=0;j<m;j++){
            int value{0};
            cin>>value;
            M.push_back(value);
            v1.push_back(false);
            v2.push_back(false);
        }
        matrix.push_back(M);
        visited_fir.push_back(v1);
        visited_sec.push_back(v2);
    }
    for(int j=0;j<m;j++){
        if(!visited_fir[0][j])
        DFS(matrix,visited_fir,0,j);
        if(!visited_sec[n-1][j])
        DFS(matrix,visited_sec,n-1,j);
    }
    for(int i=0;i<n;i++){
        if(!visited_fir[i][0])
        DFS(matrix,visited_fir,i,0);
        if(!visited_sec[i][m-1])
        DFS(matrix,visited_sec,i,m-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited_fir[i][j]&&visited_sec[i][j]) cout<<i<<" "<<j<<'\n';
        }
    }

}
