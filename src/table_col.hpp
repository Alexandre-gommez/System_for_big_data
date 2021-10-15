#include <iostream>
#include <vector>

using namespace std;

using Identifier = int;
using Integer = int;
using Decimal = double;
using Text = char[];


enum class Type {
  Identifier, Integer, Decimal, Text
};

class ColBase {
  int size;
  Type type;

public:
  int get_size() { return size; }
  Type get_type() { return type; }
};

template <class T>
class Col : public ColBase {

  vector<T> values;

  public:
    vector<T> get_values() { return values; }
};

class Table {
public:
  vector<string> col_names;
  vector<Type> types;
  int n_cols;
  vector<ColBase*> cols;
};

class Part : public Table {

  Col<Identifier> P_PARTKEY;
  Col<Text>       P_NAME;
  Col<Text>       P_MFGR;
  Col<Text>       P_BRAND;
  Col<Text>       P_TYPE;
  Col<Integer>    P_SIZE;
  Col<Text>       P_CONTAINER;
  Col<Decimal>    P_RETAILPRICE;
  Col<Text>       P_COMMENT;

public:
  Part () {
    col_names = { 
      "P_PARTKEY", "P_NAME", "P_MFGR", "P_BRAND", "P_TYPE",
      "P_SIZE", "P_CONTAINER", "P_RETAILPRICE", "P_COMMENT"
    };
    types = { 
      Type::Identifier, Type::Text, Type::Text, Type::Text, Type::Text, 
      Type::Integer, Type::Text, Type::Decimal, Type::Text
    };
    n_cols = 9;
    
    cols = {
      &P_PARTKEY, &P_NAME, &P_MFGR, &P_BRAND, &P_TYPE, &P_SIZE, &P_CONTAINER, &P_RETAILPRICE, &P_COMMENT
    };
  }
};