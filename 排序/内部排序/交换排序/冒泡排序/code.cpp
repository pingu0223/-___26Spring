#include <iostream>
#include <vector>
using namespace std;
void pop_sort(int* a,int left,int right){
    for(int i=left;i<right;i++){
        for(int j=right;j>i;j--){
            if(a[j]<a[j-1])swap(a[j],a[j-1]);
        }
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
    int left,right;
    cin>>left>>right;
    pop_sort(a,left,right);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";   
    }
}
