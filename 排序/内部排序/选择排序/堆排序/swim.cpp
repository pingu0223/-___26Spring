void swim(int a[],int k){
    //k是最新加入的结点的索引
    while(k>0&&a[k]>a[(k-2)/2]){
        swap(a[k],a[(k-2)/2]);
        k=(k-1)/2;
    }
}
