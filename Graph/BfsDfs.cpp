#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    { // u--v
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbours = l[u]; // 0,1,2,3,4
            cout << u << " : ";
            for (int v : neighbours)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void BFS()
    { // O(V+E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0]=true;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int> neighbours = l[u];
            for (int v : neighbours)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    };

    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout<<u<<" ";
        list<int> neighbours = l[u];
        for(int v:neighbours){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){ //O(V+E)
        vector<bool> vis(V,false);
        dfsHelper(0,vis);
    }

    bool pathHelper(int src,int dest,vector<bool>& vis){ // O(V+E)
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int> neighbours = l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(pathHelper(v,dest,vis)){
                    return true;
                };
            }
        }
        return false;
    };
    bool hasPath(int src, int dest){
        vector<bool> vis(V,false);
        return pathHelper(src,dest,vis);
    };

};

int main()
{
    Graph graph(7);
    // undirected
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    // graph.BFS();
    
    // graph.dfs();
    cout<<graph.hasPath(4,1);

    return 0;
}