#include <iostream>
#include <list>
#include <vector>
#include<queue>
using namespace std;


class Graph
{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    };
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (isUndir)
        {
            l[v].push_back(u);
        }
    };

    bool isBipartite(){
        queue<int> q;
        vector<int> color(V,-1);
        q.push(0);
        color[0]= 0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            list<int> neighbours = l[curr];
            for(int v:neighbours){
                if(color[v] == -1){
                    color[v]= !color[curr];
                    q.push(v);
                }else{
                    if(color[curr] == color[v]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


int main()
{   //undirected bipartite graph
    Graph graph(4,true);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 2);
   
    cout<<graph.isBipartite()<<endl;
return 0;
}