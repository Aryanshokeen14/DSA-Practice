#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Edge{
    public:
    int v;
    int wt;

    Edge(int v , int wt){
        this->v = v;
        this->wt = wt;
    };
};

void bellmanford(vector<vector<Edge>> graph , int src , int V){
    vector<int> dist(V , INT_MAX);
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e: graph[u]){
                if( dist[u] != INT_MAX && dist[e.v]>dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
};

int main(){
    int v=5;
    vector<vector<Edge>> graph(v);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    
    graph[1].push_back(Edge(2,-4));
    
    graph[2].push_back(Edge(3,2));
    
    graph[3].push_back(Edge(4,4));
    
    graph[4].push_back(Edge(1,-1));
    
    bellmanford(graph , 4 , v);
return 0;
}

