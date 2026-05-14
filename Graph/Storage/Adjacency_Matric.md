# 邻接矩阵——利用NxN的矩阵来存储图

## 适用情况

1. 数据量比较小
2. 稠密图

## 代码示例

```cpp
#include <iostream>
#include <vector>
using namespace std;
const long long INF=4e18;
//就这样尝试来写邻接矩阵的存储方式
int main(){
    int n;
    cin>>n;
    vector<vector<long long>> matrix(n+1,vector<long long>(n+1,INF));
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            long long weight;
            cin>>weight;
            matrix[i][j]=weight;
        }
    }
}
```

## 易错总结

` vector<vector<long long>> matrix(n+1,vector<long long>(n+1,INF))`

不要忘掉初始化时**初始内部的vector**，为了之后操作方便最好也要把每个weight初始化成**INF**。
















