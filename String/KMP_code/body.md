# KMP body部分代码：

```cpp
int main(){
    string s;
    string t;
    cin>>s>>t;
    int* next=get_next(t);
    int i=0;int j=0;
    while(i<s.size()&&j<t.size()){
        if(j==-1||s[i]==t[j]){
            i++;j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==t.size()){
        cout<<"Match: pos="<<i-j<<endl;
    }
    else{
        cout<<"Mismatch"<<endl;
    }

}
```

**易错点**：别忘记j==-1的情况
