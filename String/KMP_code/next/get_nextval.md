# nextval数组——跳过重复的值

## 算法思想

```text
本质上是在记录next数组的时候观看自己的前一步有没有问题这样子！
```
## 标准代码

```cpp
int* get_next_val(string t){
    int n=t.size();
    if(n==0)return nullptr;
    int* next=new int[n]; next[0]=-1;
    if(n==1) return next;
    next[1]=0;
    int i,j;
    i=1;j=0;
    while(i<n){
        if(j==-1||t[i]==t[j]){
            i++;
            j++;
            if(t[i]==t[j]){
                next[i]=next[j];
            }
            else{
                next[i]=j;
            }
        }
        else{
            j=next[j];
        }

    }
    return next;
}
```

## 我的误解思路=.=

```cpp
 while(i<n){
        if(j==-1||t[i]==t[j]){
            i++;
            j++;
            next[i]=j+1;
        }
        else{
            while(t[j]==t[next[j]]){
                j=next[j];
            }
            j=next[j];
        }

    }
```

**失误原因**:只是跳过了，得到的nextval数组肯定是对的，但是思路不够优化
