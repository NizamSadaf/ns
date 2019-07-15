#include<iostream>
using namespace std;
int main() {
    int NODE;
    cin>>NODE;
    int graph[100][100];
    for(int i=0;i<NODE;i++)
        for(int j=0;j<NODE;j++)
        cin>>graph[i][j];
   int cost[100][100];
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         cost[i][j] = graph[i][j];
   for(int k = 0; k<NODE; k++) {
      for(int i = 0; i<NODE; i++)
         for(int j = 0; j<NODE; j++)
            if(cost[i][k]+cost[k][j] < cost[i][j])
               cost[i][j] = cost[i][k]+cost[k][j];
   }
    cout << "The matrix:" << endl;
   for(int i = 0; i<NODE; i++) {
      for(int j = 0; j<NODE; j++)
         cout <<"\t"<< cost[i][j];
      cout << endl;
   }
   return 0;
}
