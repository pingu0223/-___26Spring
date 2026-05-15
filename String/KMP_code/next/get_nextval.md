# nextval数组——跳过重复的值

## 算法思想

```text
```
## 标准代码

```cpp
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
