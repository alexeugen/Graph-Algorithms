#include "functions.h"

ifstream fin("graph.in");

int **matrice(vector <pair<int, int> > v, int n, int m)
{

  int** a = new int*[n + 1];
  for(int i = 0; i <= n; i++)
    a[i] = new int[n + 1];


  for(int i = 0; i < m; i++)
  {
    a[v[i].first][v[i].second] = 1;
    a[v[i].second][v[i].first] = 1;
  }
  return a;
}

void print_muchii(vector <pair<int, int> > v, int m)
{
  for(int i=0; i<m; i++)
  {
    cout<<v[i].first<<" ";
    cout<<v[i].second<<" "<<endl;
  }
}

void citire(vector <pair<int, int> > &v, int*** a, int &m, int &n)
{
  fin>>n;
  fin>>m;
  v.resize(m);

  for(int i=0; i<m; i++)
  {
    fin>>v[i].first;
    fin>>v[i].second;
  }


  *a = matrice(v, n, m);
}

void print_matrice(int **a, int n)
{
  for(int i = 1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
      cout<<(a)[i][j];
    cout<<endl;
  }
}

void lista(int*** listi, int **a, int m, int n)
{
  *listi = new int*[n+1];
  int **list = *listi;

  for(int i = 1; i <= n; i++)
  {
    int c = 0;
    for(int j = 1; j <= n; j++)
      if(a[i][j])
        c++;
    list[i] = new int [c+1];
    list[i][0] = c;
    c = 1;
    for(int j = 1; j <= n; j++)
      if(a[i][j])
      {
        list[i][c] = j;
        c++;
      }
  }
}

void print_lista(int** list, int n)
{
  for(int i = 1; i <= n; i++, cout<<endl)
  {
    cout<<i<<" -> ";
    for(int j = 1; j <= list[i][0]; j++)
      cout<<list[i][j]<<" ";
  }
}

void BF(int **list, int n)
{
  bool* viz = new bool[n+1];
  for(int i = 1; i <= n; i++)
    viz[i] = false;

  queue <int> Q;
  viz[1] = true;
  Q.push(1);
  while(!Q.empty())
  {
    int x = Q.front();
    Q.pop();
    cout<<x<<" ";
    for(int i = 1; i <= list[x][0]; i++)
      if(!viz[list[x][i]])
      {
        Q.push(list[x][i]);
        viz[list[x][i]] = true;
      }
  }
  cout<<endl;
}

void _df(int **list, int i, bool *viz)
{
  viz[i] = true;
  cout<<i<<" ";
  for(int j = 1; j <= list[i][0]; j++)
    if(!viz[list[i][j]])
      _df(list, list[i][j], viz);
}

void DF(int **list, int n)
{
  bool* viz = new bool[n+1];
  for(int i = 1; i <= n; i++)
    viz[i] = false;

//  for(int i = 1; i <= n; i++)
  //  if(!viz[i])
      _df(list, 1, viz);
  cout<<endl;
}

void DF_iterative(int **list, int n)
{
  bool* viz = new bool[n+1];
  for(int i = 1; i <= n; i++)
    viz[i] = false;

  stack <int> Q;
  viz[1] = true;
  Q.push(1);
  while(!Q.empty())
  {
    int x = Q.top();
    Q.pop();
    cout<<x<<" ";
    for(int i = list[x][0]; i >= 1; i--)
      if(!viz[list[x][i]])
      {
        Q.push(list[x][i]);
        viz[list[x][i]] = true;
      }
  }
  cout<<endl;
}

void BF_parents(int** list, int n, int sc, vector <int> &parents)
{
  vector <bool> viz(n+1, false);
  queue <int> Q;
  Q.push(sc);
  viz[sc] = true;


  while(!Q.empty())
  {
    int x = Q.front();
    Q.pop();
    cout<<x<<" ";
    for(int i = 1; i <= list[x][0]; i++)
    {
      if(!viz[list[x][i]])
      {
        parents[list[x][i]] = x;
        Q.push(list[x][i]);
        viz[list[x][i]] = true;
      }
    }
  }
  cout<<endl;
}

int min_road(int** list, int n, int x, int y)
{
  vector <int> parents(n+1, 0);
  BF_parents(list, n, x, parents);
  int s = 1;
  int z = y;
  while(z != x)
  {
    s++;
    cout<<z<<" ";
    z = parents[z];
  }
  cout<<z;
  return s;
}

void cmapc(int** list, int n, int x, vector <int> puncte_control)
{
  vector <bool> viz(n+1, false);
  vector <int> parents(n+1, 0);
  queue <int> Q;
  Q.push(x);
  viz[x] = true;

  int q = 1;
  while(!Q.empty() && q)
  {
    int y = Q.front();
    Q.pop();
    cout<<y<<" ";
    for(int i = 1; i <= list[y][0]; i++)
    {
      if(!viz[list[y][i]])
      {
        parents[list[y][i]] = x;
        Q.push(list[y][i]);
        viz[list[y][i]] = true;

        if(puncte_control[list[y][i]])
        {
          q = 0;
          min_road(list, n, x, list[y][i]);
          break;
        }
      }
    }
  }
  cout<<endl;

}


int check_tree(int** list, int n)
{
  vector <bool> viz(n+1, false);
  vector <int> parents(n + 1, -1);
  int r = 0;

  stack <int> S;
  S.push(1);
  viz[1] = true;
  while(!S.empty())
  {
    int x = S.top();

    r++;
    S.pop();
    for(int i = 1; i <= list[x][0]; i++)
      if(viz[list[x][i]] && list[x][i] != parents[x])
        return 0;
      else if(!viz[list[x][i]])
      {

        S.push(list[x][i]);
        viz[list[x][i]] = true;
        parents[list[x][i]] = x;
      }
  }
  if(r == n)
    return 1;
  else
   return 0;
}
