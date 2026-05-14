#include <iostream>
#include <vector>
using namespace std;
class Graph{//先做有向表
    public:
    struct Edge{
        int to;
        int weight;
        Edge* next;
    };
    Graph(int num): n(num), head(num+1,nullptr) {    
    }
    ~Graph(){
        int i;
        for(i=1;i<=n;i++){
            Edge* current=head[i];
            Edge* temp;
            if(current==nullptr) continue;
            while(current!=nullptr){
                temp=current->next;
                delete current;
                current=temp;
            }
        }
    }
    void addEdge(int u,int v,int w){
        Edge* e=new Edge{v,w,nullptr};
        Edge* temp=head[u];
        if(temp==nullptr){
            head[u]=e;
            return;
        }
        while(temp->next!=nullptr){
            if(temp->to==v){
                cout<<"Error：已经存在这条边了"<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp->to==v){
            cout<<"Error: 已经存在这条边了"<<endl;
            return;
        }
        temp->next=e;
        return;
    }
    void deleteEdge(int u,int v){
        Edge* temp=head[u];
        if(temp==nullptr){
            cout<<"Error:不存在这条边"<<endl;
            return;
        }
        if(temp->to==v){
            head[u]=temp->next;
            delete temp;
            return;
        }
        while(temp->next!=nullptr){
            if(temp->next->to==v){
                Edge* q=temp->next;
                temp->next=temp->next->next;
                delete q;
                return;
            }
            temp=temp->next;
        }
        cout<<"Error：不存在这条边"<<endl;
        return;
    }
    int getWeight(int u,int v)const{
        Edge* temp=head[u];
        while(temp!=nullptr){
            if(temp->to==v) return temp->weight;
            temp=temp->next;
        }
        cout<<"Error: 不存在这条边"<<endl;
        return -1;
    }
    void insertNode(int u){
        if(u<head.size()){
            cout<<"Error: 该结点已存在"<<endl;
            return;
        }
        int i;
        for(i=head.size()-1;i<u;i++){
            head.push_back(nullptr);
        }
        return;
    }
    bool existEdge(int u,int v)const{
        Edge* temp=head[u];
        while(temp!=nullptr){
            if(temp->to==v){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    void removeNode(int u){
        int i=0;
        for(i=1;i<head.size();i++){
            if(i==u) continue;
            Edge* temp=head[i];
            if(temp==nullptr) continue;
            if(temp->to==u){head[i]=temp->next;delete temp; continue;}
            while(temp->next!=nullptr){
                if(temp->next->to==u){
                    Edge* p=temp->next;
                    temp->next=temp->next->next;
                    delete p;
                    break;
                }
                temp=temp->next;
            }
        }
        Edge* temp=head[u];
        Edge* q;
        while(temp!=nullptr){
            q=temp->next;
            delete temp;
            temp=q;
        }
        head[u]=nullptr;
    }
    private:
    int n;
    vector<Edge*>head;
};
