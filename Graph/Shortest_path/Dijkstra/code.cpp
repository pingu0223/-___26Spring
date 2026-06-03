#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int INF=1e9;
int main(){
    int n;
    cin>>n;
    int matrix[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            matrix[i][j]=INF;
        }
    }
    vector<int> distance(n+1,INF);
    vector<bool> visited(n+1,false);
    vector<int> pre(n+1,0);
    int it;
    cin>>it;
    visited[it]=true;pre[it]=0;distance[it]=0;
    for(int cnt=0;cnt<n-1;cnt++){//可以有次数哟哟哟
        for(int i=1;i<=n;i++){
            if(matrix[it][i]!=INF&&visited[i]!=true){
                int d=matrix[it][i]+distance[it];
                if(d<distance[i]){
                    distance[i]=d;
                    pre[i]=it;
                }
            }
        }
          int min=0;
            for(int i=1;i<=n;i++){
                if((!visited[i])&&distance[i]<distance[min]){
                    min=i;
                }
            }
            if(min==0) break;
            else{
                it=min;
                visited[it]=true;
            }
    }
}
