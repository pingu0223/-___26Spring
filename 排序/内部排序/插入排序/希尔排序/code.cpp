#include <iostream>
#include <vector>
using namespace std;
void DIS(int a[],int left,int right,vector<int>&h){
    int n=h.size();
    for(int nn=0;nn<n;nn++){
        int gap=h[nn];
        for(int p=0;p<gap;p++){
        for(int i=left+p+gap;i<=right;i+=gap){
            for(int j=i;j>=left+p+gap;j-=gap){
                if(a[j]<a[j-gap]){
                    swap(a[j],a[j-gap]);
                }
                else break;
            }
        }}
    }
}
int main(){
    int n{0};
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int value{0};
        cin>>value;
        a[i]=value;
    }
    int left{0},right{0};
    cin>>left>>right;
    //来计算一下增量序列
    vector<int> h;
    int gap=n/2;
    if(gap==0)h.push_back(1);
    while(gap!=0){
        h.push_back(gap);
        gap/=2;
    }
    DIS(a,left,right,h);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}
