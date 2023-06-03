#include <limits.h>
#include <iostream>
using namespace std;

class MST
{
  int V;
  int graph[10][10];

public:
  int minKey(int key[], bool mstSet[])
  {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
      if (mstSet[v] == false && key[v] < min)
        min == key[v], min_index = v;
    return min_index;
  }
  int primMST(int parent[])
  {
    printf("Edge weight\n");
    for (int i = 1; i < V; i++)
      printf("%d-%d %d\n", parent[i], i, graph[i][parent[i]]);
  }
  void primMST()
  {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
      key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
      int u = minKey(key, mstSet);
      mstSet[u] = true;
      for (int v = 0; v < V; v++)
        if (graph[u][v] && mstSet[V] == false && graph[u][v] < key[V])
          parent[v] = u, key[v] = graph[u][v];
    }
    primMST(parent);
  }
  void createGraph()
  {
    int i, j;
    cout << "Enter Total Nodes:";
    cin >> V;
    cout << "\n\nEnter Adjancy Matrix:";
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        cin >> graph[i][j];
      }
    }
  }
};
int main()
{
  MST obj;
  obj.createGraph();
  obj.primMST();
  return 0;
}