# 写希尔排序的错误集合=。=
## 增量序列计算错误
**我的错误代码**:
```cpp
vector<int> h;
    int nn=n/2;
    if(nn==0) h.push_back(1);
    while(nn>0){
        nn/=2;
        h.push_back(nn);
    }
```
**问题**: 忽略了最后会加入0的情况

**修改后**: 
```cpp
vector<int> h;
    int gap=n/2;
    if(gap==0)h.push_back(1);
    while(gap!=0){
        h.push_back(gap);
        gap/=2;
    }
```
## 越界问题
**我的写法**:
```cpp
for(int p=0;p<gap;p++){
        for(int i=left+p;i<right;i+=gap){
            for(int j=i+gap;j>left+gap;j-=gap){
                if(a[j]<a[j-gap]){
                    swap(a[j],a[j-gap]);
                }
                else break;
            }
        }}
//本质上是让i作为第一个值 j为i后面一个值，开始插入
```
**问题**：这样写就会出大问题哦，因为j没有被<right的界限所限制！

          而且j大于left+gap也不严谨：不是每个组都从头开始的（）

**正确解法**：
```cpp
  for(int i=left+p+gap;i<=right;i+=gap){
            for(int j=i;j>=left+p+gap;j-=gap){
                if(a[j]<a[j-gap]){
                    swap(a[j],a[j-gap]);
                }
                else break;
            }
        }}
```








