#include "functions.h"
#include <bits/stdc++.h>

using namespace std;

int distance(string word1,string word2,int w1,int w2)
{
	if(w1 == 0)
  return w2;

  if(w2 == 0)
  return w1;

  if(word1[w1-1] == word2[w2-1])
  return distance(word1,word2,w1-1,w2-1);

  return 1 + minimum(distance(word1,word2,w1,w2-1),distance(word1,word2,w1-1,w2),distance(word1,word2,w1-1,w2-1));
}
