#include "functions.h"
#include <bits/stdc++.h>

using namespace std;

int minimum(int x,int y,int z)
{
  int min = x;
  if(y < min)
  min = y;
  if(z < min)
  min = z;
  return min;
}
