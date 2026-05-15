# 这是标准的next数组计算方法

## 算法思路概述

```text
我们从第二个元也就是t[1]开始，观察前后字符串匹配的方式
使用两个指针，i代表现在要观察的元素，j代表已匹配的字符串长度
我们通过拿t[i]与t[j]匹配，其实是看第j+1个元素和第i个元素是否相等，
若是相等则我们下一个元素所对应的前缀匹配长度+1
```

## 代码展示

```cpp
int* get_next(string t){
    int n=t.size();
    if(n==0) return nullptr;
    int* next=new int[n];next[0]=-1;
    if(n==1)return next;
    next[1]=0;
    int i,j;
    i=1;j=0;
    while(i<n){
        if(j==-1||t[i]==t[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}
```

## 难点提示

**重点在于**：理解j代表的是长度，我们在找的是前缀与后缀相同的最大长度！













