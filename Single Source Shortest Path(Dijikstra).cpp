#include <iostream>
#include <climits>
#include <set>
using namespace std;
int V;
int minDist(int dist[100], bool Set[100])//calculate minimum distance
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
   if (Set[v] == false && dist[v] <= min)
   min = dist[v], min_index = v;
   return min_index;
}
int printSol(int dist[100], int n)//print the solution
{
   cout<<"Vertex Distance from Source"<<endl;
   for (int i = 0; i < V; i++)
   cout<<" \t\t "<<endl<< i<<" \t\t "<<dist[i];
}
void dijkstra(int g[100][100],int src)
{
   int dist[100];
   bool Set[100];
   for (int i = 0; i < V; i++)
   dist[i] = INT_MAX, Set[i] = false;
   dist[src] = 0;
   for (int c = 0; c < V- 1; c++)
   {
      int u = minDist(dist,Set);
      Set[u] = true;
      for (int v = 0; v < V; v++)
      if (!Set[v] && g[u][v] && dist[u] != INT_MAX && dist[u]
         + g[u][v] < dist[v])
         dist[v] = dist[u] + g[u][v];
   }
   printSol(dist, V);
}
int main()
{
    cin>>V;
    int g[100][100];
    for(int i=0;i<V;i++)
     for(int j=0;j<V;j++)
        cin>>g[i][j];
   dijkstra(g,0);
   return 0;
}
