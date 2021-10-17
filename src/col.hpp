#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class ColBase
{
public:
  virtual void print_values(){};
  virtual void add_value(string val){};
  virtual void get_value(int i){};
  virtual int get_size() { return 0; };
  virtual double sum() { return 0; };
};

// il faudrait aussi créer un type de colonne "date"

class ColInt : public ColBase
{

public:
  vector<int> values;

  ColInt() {}

  vector<int> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  void add_value(string val) { values.push_back(stoi(val)); }

  int get_size() { return values.size(); }

  void print_values()
  {
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }

  double sum()
  {
    int res = 0;
    for (int i = 0; i < (int)values.size(); i++)
    {
      res += values[i];
    }
    return (res);
  }
};

class ColFloat : public ColBase
{

public:
  vector<float> values;

  ColFloat() {}

  vector<float> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  void add_value(string val) { values.push_back(stof(val)); }

  int get_size() { return values.size(); }

  void print_values()
  {
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }

  double sum()
  {
    double res = 0;
    for (int i = 0; i < (int)values.size(); i++)
    {
      res += values[i];
    }
    return (res);
  }
};

class ColChar : public ColBase
{

public:
  int m_length;
  vector<char *> values;

  ColChar(int length) { m_length = length; }

  vector<char *> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  int get_size() { return values.size(); }

  void add_value(string val)
  {
    char *temp = (char *)malloc(sizeof(char) * m_length);
    strcpy(temp, val.c_str());
    values.push_back(temp);
  }

  void print_values()
  {
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};