# Prim 算法实现错误总结（邻接矩阵版）

## 1. 问题背景

这是一次对 Prim 算法（邻接矩阵实现）的代码复盘。
整体算法思路已经基本正确，但在：

* 变量语义
* 算法不变量
* C++ 容器初始化
* visited 逻辑

等方面仍存在一些典型错误。

这些错误非常具有代表性，因此整理成文档。

---

# 2. Prim 算法核心思想

Prim 算法用于求：

```text
无向连通带权图的最小生成树（MST）
```

核心思想：

```text
不断从“当前生成树”向外扩展，
每次选择一条最短边加入生成树。
```

---

# 3. Prim 中几个关键变量的真正含义

## `visited[i]`

表示：

```text
顶点 i 是否已经加入最小生成树
```

---

## `distance[i]`

表示：

```text
当前生成树 到 顶点 i 的最短边权
```

注意：

```text
它不是：
“是否访问过”
```

---

## `parent[i]`

表示：

```text
顶点 i 是通过哪个顶点连接进 MST 的
```

即：

```text
是谁提供了当前最短边
```

---

# 4. 错误总结

---

# 错误 1：错误使用 vector 初始化

## 错误写法

```cpp
vector<long long> parent{n+1,-1};
vector<long long> distance{n+1,INF};
```

---

## 实际效果

这不是：

```text
创建长度为 n+1 的数组
```

而是：

```text
创建一个只有两个元素的 vector
```

例如：

```cpp
vector<int> a{5,0};
```

实际得到：

```text
a = [5,0]
```

---

## 正确写法

```cpp
vector<long long> parent(n+1,-1);
vector<long long> distance(n+1,INF);
```

---

# 错误 2：使用 `distance[i]==0` 判断是否访问

## 错误写法

```cpp
if(distance[i]!=0)
```

---

## 为什么错误

`distance[i]` 的真正含义是：

```text
当前 MST 到 i 的最短边权
```

而不是：

```text
i 是否已经加入 MST
```

---

## 极端情况

若图中存在：

```text
权值为 0 的边
```

例如：

```text
1 --0-- 2
```

则：

```text
distance[2] = 0
```

会被误判为：

```text
2 已经加入 MST
```

---

## 正确做法

使用：

```cpp
visited[i]
```

单独维护访问状态。

---

# 错误 3：误解 `parent` 的意义

## 错误写法

```cpp
parent[current]=last;
```

其中：

```cpp
last=current;
```

表示“上一轮加入的点”。

---

## 为什么错误

Prim 中：

```text
当前加入的新点
不一定是由“上一轮加入的点”连接的
```

而是：

```text
由整个 MST 边界中的最短边连接
```

---

## 正确理解

`parent[i]` 应记录：

```text
是谁提供了当前最短边
```

---

## 正确更新方式

```cpp
if(cost[current][i] < distance[i]){
    distance[i] = cost[current][i];
    parent[i] = current;
}
```

---

# 错误 4：result 更新位置不严谨

## 错误写法

```cpp
result += distance[current];
```

但：

```text
distance[current]
```

可能已经在更新阶段被修改。

---

## 正确做法

使用本轮已经确定的：

```cpp
min_d
```

即：

```cpp
result += min_d;
```

---

# 错误 5：更新 distance 时未判断 visited

## 错误写法

```cpp
if(cost[current][i] < distance[i]){
```

---

## 问题

已经加入 MST 的点：

```text
不应再被更新
```

---

## 正确写法

```cpp
if(!visited[i] && cost[current][i] < distance[i]){
```

---

# 错误 6：使用 VLA（变长数组）

## 错误写法

```cpp
bool visited[n+1];
```

---

## 问题

这属于：

```text
GCC 扩展
```

并不是标准 C++。

在部分编译器中会直接报错。

---

## 正确写法

```cpp
vector<bool> visited(n+1,false);
```

---

# 5. Prim 算法最重要的不变量（Invariant）

Prim 最核心的不变量：

```text
任何时刻：

distance[i]
始终表示：

当前 MST 到 i 的最短边
```

---

理解这个不变量后：

很多错误会自动消失。

例如：

```text
distance 怎么能同时承担 visited 的作用？
```

就会立刻发现逻辑冲突。

---

# 6. 一个较规范的 Prim（邻接矩阵版）

```cpp
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

void prim(vector<vector<long long>>& cost,int n,int start){

    if(start<1 || start>n){
        cout<<"初始结点不合法"<<endl;
        return;
    }

    vector<long long> parent(n+1,-1);
    vector<long long> distance(n+1,INF);
    vector<bool> visited(n+1,false);

    distance[start]=0;

    long long result=0;

    for(int k=1;k<=n;k++){

        long long min_d=INF;
        int current=-1;

        // 找当前最近点
        for(int i=1;i<=n;i++){

            if(!visited[i] && distance[i]<min_d){

                min_d=distance[i];
                current=i;
            }
        }

        // 图不连通
        if(current==-1){

            cout<<"Error: 不连通"<<endl;
            return;
        }

        visited[current]=true;

        result += min_d;

        // 更新距离
        for(int i=1;i<=n;i++){

            if(!visited[i] && cost[current][i]<distance[i]){

                distance[i]=cost[current][i];
                parent[i]=current;
            }
        }
    }

    cout<<"最小代价是："<<result<<endl;
}
```

---

# 7. 这次复盘最大的收获

真正困难的部分不是：

```text
“背下 Prim 流程”
```

而是：

```text
理解每个变量在算法中的数学意义
```

算法实现的本质：

```text
不是“代码能跑”
而是：

代码始终维护正确的不变量。
```

---

# 8. 后续值得继续思考的问题

* 为什么 Prim 可以贪心？
* Prim 与 Dijkstra 的本质区别？
* 邻接矩阵与邻接表版本复杂度区别？
* 如何使用 priority_queue 优化 Prim？
* 为什么 MST 不唯一但权值可能唯一？
