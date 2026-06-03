#include <iostream>
using namespace std;
void select_sort(int a[],int left,int r){
    if(left>=r) return;
    for(int i=left;i<r;i++){
        int min=i;
        for(int j=i+1;j<=r;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min==i) continue;
        swap(a[min],a[i]);
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
    select_sort(a,left,r);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
