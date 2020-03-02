#include <bits/stdc++.h>
#include "entry.h"
#include "hashtable.h"
#include "functions.h"

using namespace std;

int main()
{
  char a[1000];
  cout << "Enter name of the file (with extension) :- ";
  cin >> a;
  ifstream input(a);
  vector <string> word;
  vector <string> keys;
  vector <string> meanings;
  string w;
  int i=0;
  while(1)
  {
    if(!input)
    break;
    else
    {
       string str;
       input >> str;
       if(str[0]=='\0')
       break;
       keys.push_back(str);
       input.ignore();
       getline(input,w);
       meanings.push_back(w);
    }
  }

  int no_words = keys.size();
  int ss = no_words / 0.5;
  hashtable <string,string> *table = new hashtable<string,string>(ss);
  int j=0;
  for(j=0;j<no_words;j++)
  {
    entry<string,string> *en = new entry <string,string>(keys[j],meanings[j]);
    table->add(en->get_key(),en->get_value());
  }

  int n;
  while(1)
  {
    cout << "\nSelect the functionality you want to execute:-" << endl;
    cout << "1. Add a word." << endl;
    cout << "2. Remove a word." << endl;
    cout << "3. Check meaning of a word." << endl;
    cout << "4. View size of the dictonary." << endl;
    cout << "0. EXIT." << endl << endl;
    cin >> n;
    cout << endl;

    if(n == 0)
    {
      break;
    }

    else if(n == 1)
    {
      string word,mean;
      cout << "Enter the word:- ";
      cin >> word;
      cout << "Enter the meaning:- ";
      getline(cin,mean);
      getline(cin,mean);
      entry<string,string> *e = new entry <string,string>(word,mean);
      table->add(e->get_key(),e->get_value());
      cout << "Successfully added." << endl;
    }

    else if(n == 2)
    {
      string word;
      cout << "Enter the word to be removed:- ";
      cin >> word;
      int rem;
      rem = table->remove(word);
      int i;
      for(i=0;i<keys.size();i++)
      {
        if(keys[i] == word)
        {
          keys.erase(keys.begin()+i);
          meanings.erase(meanings.begin()+i);
          break;
        }
      }
      if(rem == 1)
      cout << "Successfully removed." << endl;
      else
      cout << "No such element exist." << endl;
    }

    else if(n == 3)
    {
      string word;
      cout << "Enter the word:- ";
      cin >> word;
      string v = table->search(word);
      if(v != "-1")
      {
        cout << word << " -- " << v << endl;
      }

      else
      {
        cout << "Word does not exist in the dictonary." << endl;
        cout << "\nDid you mean....." << endl;
        int dist,k,sub,temp=0,sub1;
        for(k=0;k<table->size();k++)
        {
          dist = distance(keys[k],word,keys[k].length(),word.length());
          sub = isSubstring(word,keys[k]);
	  sub1 = isSubstring(keys[k],word);
          if((dist <= 2) || (sub != -1) || (sub1 != -1))
          {
            if((sub != -1) || (sub1 != -1))
            {
              if(word.length() >= 3)
	      {
                 cout << keys[k] << " -- " << meanings[k] << endl;
                 temp=1;
		 continue;
              }
            }
            else if(dist <= 2)
            {
              if(keys[k].length() <= 3)
              {
                if(((keys[k][0] == word[0]) && (keys[k][1] == word[1])) || ((keys[k][0] == word[0]) && (keys[k][2] == word[2])) || ((keys[k][2] == word[2]) && (keys[k][1] == word[1])))
                {
                  cout << keys[k] << " -- " << meanings[k] << endl;
                  temp=1;
		  continue;
                }
              }

              else
              {
                cout << keys[k] << " -- " << meanings[k] << endl;
                temp=1;
		continue;
              }
            }
          }
        }
        if(temp==0)
        {
          cout << "No similar word found!" << endl;
        }
      }
    }

    else if(n == 4)
    {
      int s = table->size();
      cout << "Current size of the dictonary is:- " << s << endl;
    }

    else
    {
      cout << "Enter the valid key!" << endl;
    }
  }
}
