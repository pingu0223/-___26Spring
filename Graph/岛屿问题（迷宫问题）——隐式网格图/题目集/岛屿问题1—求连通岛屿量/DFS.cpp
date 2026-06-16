#include <iostream>
#include <vector>
using namespace std;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int DFS(vector<vector<int>>&matrix,vector<vector<bool>>& v,int a,int b){
    if(matrix.size()==0) return 0;
    if(a>=matrix.size()||b>=matrix[0].size()) return 0;
    if(v[a][b]) return 0;
    if(matrix[a][b]==0) {v[a][b]=true;return 0;}
    v[a][b]=true;
    DFS(matrix,v,a+dir[0][0],b+dir[0][1]);
    DFS(matrix,v,a+dir[1][0],b+dir[1][1]);
    DFS(matrix,v,a+dir[2][0],b+dir[2][1]);
    DFS(matrix,v,a+dir[3][0],b+dir[3][1]);
    return 1;
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
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
    result+=DFS(matrix,visited,i,j);
}
    }
    cout<<result;
}
