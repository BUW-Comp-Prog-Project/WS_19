//https://www.spoj.com/problems/PT07Y/cstart=110
// submission : Prem Kumar Tiwari
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
    int src;
    int dest;
};
// first we convert hte set of edges into a graph
class Graph
{

public:
    vector<vector<int>> adjList;
//    void show();

//    defining a constructor her
    Graph(vector<Edge> const& edges, int N)
    {
        adjList.resize(N+1);
        for(auto edge:edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);

        }
    }

};
//void Graph ::show() {
//    for (auto elements: adjList)
//    {
//        for(int i : elements)
//        {
//            cout << i << "-->";
//        }
//        cout <<endl;
//    }
//}


// so to check if the graph is a tree or not following properties should hold:
// 1. There is no cycle
// 2. The graph is connected

bool DFS(Graph const& graph, int v, vector<bool> &discovered, int parent)
{
    discovered[v] = true;
    for(int i: graph.adjList[v])
    {
        if(!discovered[i])
        {
           if(DFS(graph,i,discovered,v)) return true;

        }
//        not a parent imply it is a cycle
        else if(i!= parent) return true;

    }
    return false;

}






int main() {
    vector<Edge> edges;
    int n,m;
    int src,dest;
    cin >> n >> m;
    edges.resize(m);
    for(int i = 0;i<m;i++)
    {
//        we have here collection of all the edges
        cin >> src >> dest;
        edges[i].src = src;
        edges[i].dest = dest;
    }
    Graph graph(edges, n);
    vector<bool> discovered(n+1);
//    for(auto i: discovered)
//    {
//        cout << i <<endl;
//    }
    int start = edges[1].src;
    bool cycle = DFS(graph, start, discovered, -1);
    int count = 0;
//    cout<<"*************************"<<endl;
//    for(auto i: discovered)
//    {
//        cout << i <<endl;
//    }
    for(int i= 0 ; i<=n;i++)
    {
        if(discovered[i]) count+=1;
    }
    if(count==n ){
        (!cycle) ? cout << "YES" << endl : cout << "NO" <<endl;

        return 0;
    }
    cout << "NO" << endl;




    return 0;
}
