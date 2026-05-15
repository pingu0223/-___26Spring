# 我自己胡编乱造的求next数组的方法

## 思路简述

```text
真的在求解next数组！
对于next[0]与next[1]进行直接赋值。
之后的每个值按与上一个值的next数组对应值是否匹配成功来计算。
有亿点繁琐…………
```

## 代码预览

```cpp
int* get_next(string t){
    int n=t.size();//先创建一个next数组
    int* next=new int[n];
    next[0]=-1;
    if(n==0) return next;
    next[1]=0;//赋初始值
    int i=0;
    for(i=2;i<n;i++){//我们需要处理从2到n-1的value所对应的next数组的值
        //因为我们上一个值的next数组的值就是我们要匹配的
        if(t[i-1]==t[next[i-1]]){//成功的话直接拓展
            next[i]=next[i-1]+1;
        }
        else{//失败的话那不停回退直到达到0或者相似
            int x=i-1;
            while(x!=0){
                x=next[x];
                if(t[i-1]==t[next[x]+1]){
                    break;
                }
            }
            next[i]=next[x]+1;
        }
    }
    return next;
}
```

## 易错整理

1. **注意n的取值**：如果n=1，那直接赋值next[1]就会导致越界。
2. **对next数组的理解**：next[i-1]代表下一个要匹配谁！所以直接拿t[i-1]与t[next[i-1]]去比就好啦！




