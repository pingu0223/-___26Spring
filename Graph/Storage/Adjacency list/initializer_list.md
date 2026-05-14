# 构造函数初始化列表

## 引入

当你定义一个类，而类中存在**vector成员**时，你会不会想：**“我该怎么在构造函数里初始化vector呢？**

而**构造函数初始化列表**就能帮助你解决这个问题。

## 使用示例

以我们这里用到的的**Graph类**为例子：

```cpp
class Graph{
   private:
   int n;
   vector<Edge*> head;
}
```

**构造函数**可以这样写：

```cpp
Graph(int num): n(num), head(num, nullptr){
}
```

## 含义解析

```: n(num), head(num, nullptr)```

代表进入{}前先构造成员变量

### 补充——vector的构造函数

``` vector(大小，初始值）```

## 使用场景

1. 含有vector
2. 含有string
3. 含有map<int,int>







