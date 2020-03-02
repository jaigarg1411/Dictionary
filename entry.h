#ifndef ENTRY_H
#define ENTRY_H

#include <bits/stdc++.h>

using namespace std;

template <typename K,typename V>
class entry
{
  V value;
  K key;

public:
  entry(K key,V value);
  K get_key();
  V get_value();
  void set_value(V value);
  bool operator==(entry<K,V> *e1)
  {
    return (this->key == e1->key);
  }
};

template <typename K,typename V>
void entry<K,V> :: set_value(V value)
{
  this->value = value;
}

template <typename K, typename V>
entry<K,V> :: entry (K key,V value)
{
  this->key = key;
  this->value = value;
}

template <typename K,typename V>
K entry<K,V> :: get_key()
{
  return key;
}

template <typename K,typename V>
V entry<K,V> :: get_value()
{
  return value;
}
#endif
