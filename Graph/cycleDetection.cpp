#include <iostream>
#include <list>
#include <vector>
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
    }
    bool isCycleUndirHelper(int src, vector<bool> &vis, int parent)
    {
        vis[src] = true;
        list<int> neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (isCycleUndirHelper(v, vis, src))
                {
                    return true;
                };
            }
            else
            {
                if (v != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleUndir()
    {
        vector<bool> vis(V, false);
        return isCycleUndirHelper(0, vis, -1);
    };

    bool isCycleDirHelper(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (isCycleDirHelper(v, vis, recPath))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[v])
                {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    };

    bool isCycleDir()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleDirHelper(i, vis, recPath))
                {
                    return true;
                };
            }
        }
        return false;
    }
};

int main()
{
    Graph graph(5,false);
    graph.addEdge(1, 0);
    graph.addEdge(2, 3);
    graph.addEdge(0, 2);
    graph.addEdge(3, 0);

    cout << graph.isCycleDir();
}