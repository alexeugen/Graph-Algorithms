#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;



int **matrice(vector <pair<int, int> > v, int n, int m);
void print_muchii(vector <pair<int, int> > v, int m);
void citire(vector <pair<int, int> > &v, int*** a, int &m, int &n);
void print_matrice(int **a, int n);
void lista(int*** listi, int **a, int m, int n);
void print_lista(int** list, int n);
void BF(int **list, int n);
void _df(int **list, int i, bool *viz);
void DF(int **list, int n);
void DF_iterative(int **list, int n);
void BF_parents(int** list, int n, int sc, vector <int> &parents);
int min_road(int** list, int n, int x, int y);
void cmapc(int** list, int n, int x, vector <int> puncte_control);
int check_tree(int** list, int n);


#endif
