#include <iostream>
using namespace std;
void douinsert(int a[],int left,int r){
    if(left>=r) return;
    for(int i=left+1;i<=r;i++){
        int val=a[i];
        int low=left;int high=i-1;
        while(low<=high){//是小于等于哦~
            int mid=(low+high)/2;
            if(a[mid]<val){
                low=mid+1;
                continue;
            }
            if(a[mid]>val){
                high=mid-1;
                continue;
            }
            if(a[mid]==val){
                low=mid+1;
                break;
            }
        }
        for(int j=i;j>low;j--){
            swap(a[j],a[j-1]);  
        }

    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        a[i]=val;
    }
    int left,r;
    cin>>left>>r;
    douinsert(a,left,r);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
