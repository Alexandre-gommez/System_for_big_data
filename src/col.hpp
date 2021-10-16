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

  ColInt(vector<int> vals)
  {
    values = vals;
  }

  void set_values(vector<int> vals)
  {
    values = vals;
    size = vals.size();
  }

  void print_values()
  {
    cout << name << " :" << endl;
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }

  vector<int> get_values() { return values; }

  void add_value(int val) { values.push_back(val); }
};

class ColFloat : public ColBase
{

public:
  vector<float> values;

  ColFloat() {}

  ColFloat(vector<float> vals)
  {
    values = vals;
  }

  void set_values(vector<float> vals)
  {
    values = vals;
  }

  void print_values()
  {
    cout << name << " :" << endl;
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }

  vector<float> get_values() { return values; }

  void add_value(float val) { values.push_back(val); } 
};