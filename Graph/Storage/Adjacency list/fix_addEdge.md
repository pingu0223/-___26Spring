# 添加边

## 常用方法是头插法

```cpp
void addEdge(int u, int v, int w){
     Edge* current=head[u];
     if(current!=nullptr){
       Edge* temp=current;
       while(temp!=nullptr){
          if(temp->to==v){
             cout<<"Error：已经存在这条边了"<<endl;return;
           }
          temp=temp->next;
       }
      }
     head[u]=new Edge{v,w,head[u]};
     }
'''
