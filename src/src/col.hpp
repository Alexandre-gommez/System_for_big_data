#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class ColBase
{
public:
  virtual void print_values(){};
  virtual void get_value(){};
  virtual void add_value(string val){};
  virtual double sum(){};
};

class ColInt : public ColBase
{

public:
  vector<int> values;

  ColInt() {}

  vector<int> get_values() { return values; }

  void add_value(string val) { values.push_back(stoi(val)); }

  void print_values()
  {
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
  double sum()
  {
    cout<<"je code comme un pied "<<endl;
    cout << "La taille de la colonne est " << values.size() << endl;
    int res=0;
    for(int i=0;i< (int) values.size();i++)
    {
      cout<<values[i]<<endl;
      res +=values[i];
    }
    return(res);
  }
};

class ColFloat : public ColBase
{

public:
  vector<float> values;

  ColFloat() {}

  vector<float> get_values() { return values; }

  void add_value(string val) { values.push_back(stof(val)); }

  void print_values()
  {
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
  double sum()
  {
    cout<<"je code comme un pied "<<endl;
    cout<<"La taille de la colonne est "<<values.size()<<endl;
    double res = 0;
    for (int i = 0; i < (int)values.size(); i++)
    {
      cout<<values[i]<<endl;
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

  void add_value(string val) { 
    char* temp =(char*)malloc(sizeof(char) * m_length);
    strcpy(temp,val.c_str());
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