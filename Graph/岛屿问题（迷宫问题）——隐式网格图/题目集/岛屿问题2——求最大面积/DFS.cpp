#include <iostream>
#include <vector>
using namespace std;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int DFS(vector<vector<int>>& matrix,vector<vector<bool>>& v,int i,int j){
    int r_l=matrix.size();int c_l=matrix[0].size();
    if(i<0||i>=r_l||j<0||j>=c_l) return 0;
    if(v[i][j]) return 0;
    if(matrix[i][j]==0) return 0;
    int result=1;v[i][j]=true;
    for(int p=0;p<4;p++){
    result+=DFS(matrix,v,i+dir[p][0],j+dir[p][1]);
    }
    return result;
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
    int max_S=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j])continue;
            int s=DFS(matrix,visited,i,j);
            if(s>max_S)max_S=s;
        }
    }
    cout<<max_S;
}
