#include "functions.h"

using namespace std;

int darb(int** list, int n)
{

}

int extrent(int** list, int n, int x)
{
  int max = 0;
  for(int i = 1; i <= n; i++)
  {

    int s = min_road(list, n, x, i);
    if(s > max)
      max = s;
  }
  return max;
}

int main()
{
  int n; // numarul de noduri
  vector <pair<int, int> > v;
  int **a;
  int m; //numarul de muchii
  int** list; //lista de adiacenta

  citire(v, &a, m, n);
  lista(&list, a, m, n);

  cout<<"$";
  BF(list, n);cout<<"$";

  print_lista(list, n);

  cout<<check_tree(list, n);cout<<endl;
/*
  int l = extrent(list, n, 5);
  cout<<"#"<<l<<"#";

/*
  vector <int> puncte_control(n+1, 0);
  puncte_control[9] = 1;
  puncte_control[8] = 1;


  min_road(list, n, 9, 8);
  cmapc(list, n, 5, puncte_control);
*/
}
