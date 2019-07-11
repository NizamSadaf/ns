#include<iostream>
using namespace std;
int V;
bool graph[100][100];
void showColors(int color[]) {
   cout << "Assigned Colors are: " <<endl;
   for (int i = 0; i < V; i++)
      cout << color[i] << " ";
   cout << endl;
}
bool isValid(int v,int color[], int c) {    //check whether putting a color valid for v
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}
bool graphColoring(int colors, int color[], int vertex) {
   if (vertex == V)    //when all vertices are considered
      return true;

   for (int col = 1; col <= colors; col++) {
      if (isValid(vertex,color, col)) {     //check whether color col is valid or not
         color[vertex] = col;
         if (graphColoring (colors, color, vertex+1) == true)    //go for additional vertices
            return true;

         color[vertex] = 0;
      }
   }
   return false; //when no colors can be assigned
}

bool checkSolution(int m) {
   int *color = new int[V];    //make color matrix for each vertex

   for (int i = 0; i < V; i++)
      color[i] = 0;      //initially set to 0

   if (graphColoring(m, color, 0) == false) {    //for vertex 0 check graph coloring
      cout << "Solution does not exist.";
      return false;
   }
   showColors(color);
   return true;
}

int main() {
   int colors;
   cout<<"Enter Number of colors:";
   cin>>colors;
   cout<<"Enter Number of vertex:";
   cin>>V;// Number of colors
   cout<<"Enter 1 for edge or 0 for no edge between two vertex:";
   for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
    cin>>graph[i][j];
    checkSolution (colors);
}
