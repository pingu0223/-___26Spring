#include <iostream>
using namespace std;
void insert_sort(int a[],int left,int right){
    for(int i=left;i<right;i++){
        for(int j=i+1;j>left;j--){
            if(a[j]>a[j-1]) break;
            swap(a[j],a[j-1]);
        }
    }
}
void dou_insert(int a[],int left,int right){
    for(int i=left;i<right;i++){
        int j=i+1;
        int head=left;int tail=i;
        while(head<=tail){
            int mid=(head+tail)/2;
            if(a[mid]<a[j])head=mid+1;
            else if(a[mid]>a[j])tail=mid-1;
            else if(a[mid]==a[j]){
                head=mid+1;
                break;
            }
        }
        for(int q=j;q>head;q--){
            swap(a[q],a[q-1]);
        }
    }
}
int main(){
    int n{0},value{0};
    cin>>n;
    int a[n]{};
    for(int i=0;i<n;i++){
        cin>>value;
        a[i]=value;
    }
    int left{0},right{0};
    cin>>left>>right;
    insert_sort(a,left,right);
    dou_insert(a,left,right);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
