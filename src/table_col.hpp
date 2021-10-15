#include <iostream>
#include <vector>

using namespace std;

using Identifier = int;
using Integer = int;
using Decimal = double;
using Text = char[200];


enum class Type {
  Identifier, Integer, Decimal, Text
};

class ColBase {
public:
  int size = 0;
  string name;

  virtual void print_values() {};
};

template <class T>
class Col : public ColBase {

  vector<T> values;

  public:

    Col () {}

    Col (vector<T> vals) {
      values = vals;
      size = vals.size();
    }

    void set_values(vector<T> vals) {
      values = vals;
      size = vals.size();
    }

    vector<T> get_values() { return values; }

    void print_values() {
      cout << name << " :" << endl;
      for (int i = 0; i < values.size(); i++) {
        cout << values[i] << endl;
      }
    }

    void add_values () {
      
  }
};

class Table {
public:
  vector<string> cols_names;
  vector<Type> types;
  int n_cols;
  vector<ColBase> cols;

  Table () {}

  Table (vector<string> cn, vector<Type> t) {
    cols_names = cn;
    types = t;
    n_cols = cn.size();
    for (int i = 0; i < n_cols; i++) {
      switch (t[i]) {
        case Type::Identifier: {
          Col<Identifier> tmp1; tmp1.name = cn[i];
          cols.push_back(tmp1);
          break;
        }
        case Type::Integer: {
          Col<Integer> tmp2; tmp2.name = cn[i];
          cols.push_back(tmp2);
          break;
        }
        case Type::Decimal: {
          Col<Decimal> tmp3; tmp3.name = cn[i];
          cols.push_back(tmp3);
          break;
        }
        case Type::Text: {
          Col<Text> tmp4; tmp4.name = cn[i];
          cols.push_back(tmp4);
          break;
        }
      }
    }
  }

  void add_values () {
    for (int i = 0; i < n_cols; i++) {
      cols[i].add_values();
    }
  }
};