void quick_save_sort(vector<int>&a,int left,int right){
    if(left>=right) return;int i=left;int j=right;
    int mid=(left+right)/2;
    int is=is_mid(a,left,mid,right);
    if(is==0) swap(a[left],a[mid]);
    if(is==-1) swap(a[left],a[right]);
    int value=a[left];bool is_left=true;
    while(left<right){
        if(is_left){
            if(a[right]<value) {a[left]=a[right];left++;is_left=false;}
            else right--;
        }
        else{
            if(a[left]>value){a[right]=a[left];right--;is_left=true;}
            else left++;
        }
    }
    a[left]=value;
    quick_save_sort(a,i,left-1);quick_save_sort(a,left+1,j);
    return;
}
