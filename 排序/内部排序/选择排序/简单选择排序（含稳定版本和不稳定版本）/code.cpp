#include <iostream>
using namespace std;
void select_sort(int a[],int left,int right){
    for(int i=left;i<right;i++){
        int min=i;
        for(int j=i+1;j<=right;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
    }
}
void select_sort_stable(int a[],int left,int right){
    for(int i=left;i<right;i++){
        int min=i;
        for(int j=i+1;j<=right;j++){
            if(a[j]<a[min]) min=j;
        }
        //这里改变了
        for(int j=min;j>i;j--){
            swap(a[j],a[j-1]);
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
    //select_sort(a,left,right);
    select_sort_stable(a,left,right);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
