#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream fin("kruskal.in");

struct edge{
  int src, dest, weight;
};

int myComp(const void* x, const void* y)
{
  edge* e1 = (edge*)x;
  edge* e2 = (edge*)y;
  if(e1->weight > e2->weight)
    return 1;
  return 0;
}

int find(int* parents, int i)
{
  while(parents[i] != 0)
    i = parents[i];
  return i;
}

void unioni(int* height, int* parents, int x, int y)
{
  if(height[x] > height[y])
    parents[y] = x;
  else
  {
    parents[x] = y;
    if(height[x] == height[y])
      height[x]++;
  }
}

int main()
{
  int nrV, nrE;
    fin>>nrV>>nrE;

  int *parents = new int[nrV + 1];
  int *height = new int[nrV + 1];
  edge* edges = new edge[nrE];
  edge* MST = new edge[nrV - 1];


  for(int i = 0; i < nrE; i++)
    fin>>edges[i].src>>edges[i].dest>>edges[i].weight;

  qsort(edges, nrE, sizeof(edge), myComp);
  cout<<endl;
  for(int i = 0; i < nrE; i++, cout<<endl)
    cout<<edges[i].src<<" _ "<<edges[i].dest<<" : "<<edges[i].weight;

  for(int i = 1; i <= nrV; i++)
    parents[i] = 0, height[i] = 0;

  int e = 0;
  int i = 0;
  while(e < nrV - 1 && i < nrE)
  {
    edge X = edges[i++];
    int x = find(parents, X.src);
    int y = find(parents, X.dest);

    if(x != y)
    {
      MST[e++] = X;
      unioni(height, parents, x, y);
    }
  }

  for(int i = 0; i < nrV - 1; i++)
    cout<<MST[i].weight;

}
