#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("kruskal.in");

struct edge{
  int src, dest, weight;
};

int getMinKey(int* keys, bool* mstSet, int nrV)
{
  int mini = 999999;
  int mini_index;
  for(int i = 1; i <= nrV; i++)
  {
    if(keys[i] < mini && mstSet[i] == false)
      mini_index = i, mini = keys[i];
  }
  return mini_index;
}

int main()
{
  int nrV, nrE;
  fin>>nrV>>nrE;
  int** matrix = new int*[nrV + 1];
  for(int i = 1; i <= nrV; i++)
    matrix[i] = new int[nrV + 1];

  for(int i = 1; i <= nrE; i++)
  {
    int x,y,p;
    fin>>x>>y>>p;
    matrix[x][y] = matrix[y][x] = p;
  }

  for(int i = 1; i <= nrV;  i++, cout<<endl)
    for(int j = 1; j <= nrV; j++)
      cout<<matrix[i][j]<<" ";

  bool* mstSet = new bool[nrV + 1];
  int* parents = new int[nrV + 1];
  int* keys = new int[nrV + 1];

  for(int i = 1; i <= nrV; i++)
    keys[i] = 999999, mstSet[i] = false, parents[i] = 0;
  keys[1] = 0;
  for(int i = 1; i <= nrV; i++)
  {
    int k = getMinKey(keys, mstSet, nrV);
    cout<<k<<endl;
    mstSet[k] = true;
    for(int j = 1; j <= nrV; j++)
    {
      if(matrix[k][j] && mstSet[j] == false && matrix[k][j] < keys[j])
      {
        keys[j] = matrix[k][j];
        parents[j] = k;

      }
    }
  }

  for(int i = 1; i <= nrV; i++)
    cout<<parents[i];

}
