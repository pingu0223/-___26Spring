int is_mid(vector<int>& a,int i,int j,int p){
    if((a[i]<=a[j]&&a[i]>=a[p])||(a[i]<=a[p]&&a[i]>=a[j])){
        return 1;
    }
    if((a[j]<=a[i]&&a[j]>=a[p])||(a[j]<=a[p]&&a[j]>=a[i])){
        return 0;
    }
    else return -1;
}
void quick_sort(vector<int>& a){
    int n=a.size();
    if(n==0||n==1) return;
    int mid=(n-1)/2;
    int is=is_mid(a,0,mid,n-1);
    if(is==0) swap(a[0],a[mid]);
    if(is==-1) swap(a[0],a[n-1]);
    vector<int> l;vector<int> r;
    for(int i=1;i<n;i++){
        if(a[i]<a[0])l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    quick_sort(l);quick_sort(r);
    l.push_back(a[0]);
    l.insert(l.end(),r.begin(),r.end());
    a=l;
}
