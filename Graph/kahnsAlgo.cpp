#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;


class Graph{
    int v;
    list<int> *l;
    bool isUndir;
    
    public:
    Graph(int v , bool isUndir = true){
        this->v = v;
        l = new list<int>[v];
        this->isUndir = isUndir;
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void calIndegree(vector<int> &indg){
        for(int u=0;u<v;u++){
            list<int> neighbours = l[u];
            for(int v:neighbours){
                indg[v]++;
            }
        }
    }

    void topoSort2(){
        vector<int> indg(v,0);
        calIndegree(indg);
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neighbours = l[curr];
            for(int v:neighbours){
                indg[v]--;
                if(indg[v]==0){
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

};

int main(){
    Graph graph(6,false);
    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();
}