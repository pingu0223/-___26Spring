void BFS(vector<vector<long long>>&matrix,int start){
    int n=matrix.size()-1;
    if(n==0) return;
    vector<bool>visited(n+1,false);
    //先来检查开始的边
    if(start<0||start>n){
        cout<<"起始点不合法"<<endl;
        return;
    }
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int current=q.front();
        for(int i=1;i<matrix[current].size();i++){
            if(visited[i]==false&&matrix[current][i]<INF){
                q.push(i);
                visited[i]=true;
            }
        }
        cout<<current<<" ";
        q.pop();
    }
    
}
