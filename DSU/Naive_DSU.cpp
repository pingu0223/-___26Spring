#include <iostream>
#include <vector>
using namespace std;
class disjoinSet{
    private:
    int n;
    vector<int> parent;
    public:
    disjoinSet(int nn):n(nn),parent(nn+1,-1){
        int i=0;
        for(i=1;i<nn+1;i++){
            parent[i]=i;
        }
    }
    ~disjoinSet(){
        return;
    }
    int find(int x){
        if(x<=0||x>n){
            cout<<"越界了"<<endl;
            return -1;
        }
        else{
            int result=parent[x];
            while(parent[result]!=result){
                result=parent[result];
            }
            return result;
        }
    }
    void union_set(int x,int y){
        if(x<=0||x>n||y<=0||y>n){
            cout<<"越界了"<<endl;
            return;
        }
        int fir_parent=find(x);
        int las_parent=find(y);
        if(fir_parent==las_parent){
            cout<<"Error: 本来就处于同一个集合"<<endl;
        }
        parent[las_parent]=fir_parent;
    }
    
};
