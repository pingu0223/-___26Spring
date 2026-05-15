void DFS(vector<vector<long long>>& matrix,vector<bool>&visited,int start){//注意引用，注意使用visited
    int n=matrix.size()-1;
    if(start<=0||start>n){
        cout<<"起始值不合法"<<endl;
        return;
    }
    int i=0;
    visited[start]=true;
    cout<<start<<" ";
    for(i=1;i<=n;i++){//注意for循环的范围
        if(visited[i]==false&&matrix[start][i]<INF){
            DFS(matrix,visited,i);
        }
    }
}
