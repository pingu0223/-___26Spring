#include <iostream>
#include <vector>
using namespace std;
void siftdown(int a[],int temp,int n){
    int l_child=2*temp+1;
    int r_child=2*temp+2;
    //先把后面有空结点的情况处理一下
    if(l_child>=n) return;
    if(r_child==n) {
        if(a[l_child]<=a[temp])return;
        swap(a[l_child],a[temp]);
        return;
    }
    //再处理普通情况
    if(a[l_child]<a[r_child]){
        if(a[r_child]<=a[temp])return;
        swap(a[r_child],a[temp]);siftdown(a,r_child,n);
    }
    else{
        if(a[l_child]<=a[temp]) return;
        swap(a[l_child],a[temp]);
        siftdown(a,l_child,n);
    }
}
int main(){
    int n{0};
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int value{0};
        cin>>value;
        a[i]=value;}
    //先变成大根堆
    int last_noleaf=(n-2)/2;
    for(int i=last_noleaf;i>=0;i--){
       siftdown(a,i,n);
    }
    //再排序
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        siftdown(a,0,i);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}
//我自己简单写了一下嘿嘿，可能还需要补充一个swim
