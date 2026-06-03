#include <iostream>
using namespace std;
void insert_sort(int a[],int left, int r){
    if(left==r) return;
    for(int i=left+1;i<=r;i++){
        for(int j=i;j>left;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
            }
            else break;
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
    insert_sort(a,left,r);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
