#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <bits/stdc++.h>
#include "entry.h"

using namespace std;

template <typename K,typename V>
class hashtable
{
  entry <K,V> **arr;
  int capacity;
  int _size;
  entry <K,V> *dummy;
public:
  hashtable(int capacity1);
  int hashcode1(K key);
  int hashcode2(K key);
  void add(K key,V value);
  int remove(K key);
  V search(K key);
  int size();
  bool isEmpty();
};

template <typename K,typename V>
hashtable<K,V> :: hashtable(int capacity1)
{
  capacity = capacity1;
  _size = 0;
  arr = new entry<K,V>*[capacity];
  int i;
  dummy = new entry <K,V>("-1","-1");
  for(i=0;i<capacity;i++)
  arr[i] = dummy;
}

template <typename K,typename V>
int hashtable<K,V> :: size()
{
  return _size;
}

template <typename K,typename V>
bool hashtable<K,V> :: isEmpty()
{
  return _size == 0;
}

template <typename K,typename V>
int hashtable<K,V> :: hashcode1(K key)
{
  int sum=0,i,seed = 131;
  for(i=0;i<key.length();i++)
  {
    sum = sum + int(key[i]) * seed;
  }
  return sum%capacity;
}

template <typename K,typename V>
int hashtable<K,V> :: hashcode2(K key)
{
  int seed = 131;
  unsigned long hash = 0;
  int i;
  for (i=0;i<key.length();i++)
  {
    hash = (hash*seed) + key[i];
  }
  return hash%capacity;
}

template <typename K,typename V>
void hashtable<K,V> :: add(K key,V value)
{
  entry <K,V> *temp = new entry <K,V>(key,value);
  int index = hashcode1(temp->get_key());
  int index2 = hashcode2(temp->get_key());
  int i=0,newindex;
  while(1)
  {
    newindex = (index + i*index2) % capacity;
    if((arr[newindex] == dummy) || (arr[newindex]->get_key() == temp->get_key()))
    {
      if(arr[newindex] == dummy)
      _size++;
      arr[newindex] = temp;
      break;
    }
    i++;
  }
}

template <typename K,typename V>
int hashtable<K,V> :: remove(K key)
{
  int index = hashcode1(key);
  if(arr[index]->get_key() == key)
  {
    arr[index] = dummy;
    _size--;
  }

  else
  {
    int index2 = hashcode2(key);
    int i=1;
    while(1)
    {
      int newindex = (index + i*index2) % capacity;

      if(arr[newindex]->get_key() == key)
      {
        arr[newindex] = dummy;
        _size--;
        return 1;
        break;
      }
      else if(arr[newindex] == dummy)
      {
        return 0;
        break;
      }
      i++;
    }
  }
}

template <typename K,typename V>
V hashtable<K,V> :: search(K key)
{
  int index = hashcode1(key);
  if(arr[index]->get_key() == key)
  {
    return arr[index]->get_value();
  }

  else
  {
    int index2 = hashcode2(key);
    int i=1;
    while(1)
    {
      int newindex = (index + i*index2) % capacity;

      if(arr[newindex]->get_key() == key)
      {
        return arr[newindex]->get_value();
        break;
      }
      else if(arr[newindex] == dummy)
      {
        return dummy->get_value();
        break;
      }
      i++;
    }
  }
}

#endif
