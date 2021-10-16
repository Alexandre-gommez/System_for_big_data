#include <iostream>
#include <vector>

using namespace std;

class ColBase
{
public:
  string name;

  virtual void print_values(){};
  virtual void get_value(){};
  virtual void add_value(){};
};

class ColInt : public ColBase
{

public:
  vector<int> values;

  ColInt() {}

  vector<int> get_values() { return values; }

  void add_value(int val) { values.push_back(val); }

  void print_values()
  {
    cout << name << " :" << endl;
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};

class ColFloat : public ColBase
{

public:
  vector<float> values;

  ColFloat() {}

  vector<float> get_values() { return values; }

  void add_value(float val) { values.push_back(val); }

  void print_values()
  {
    cout << name << " :" << endl;
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
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
    for (int i =0;i<val.size();i++)
      temp[i]=val[i];
    values.push_back(temp); 
    }

  void print_values()
  {
    cout << name << " :" << endl;
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};