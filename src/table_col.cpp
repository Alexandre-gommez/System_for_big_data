#include "table_col.hpp"

int main() {

}


class Table {
public:
  int n_cols;
  vector<Type> types;
  vector<string> col_names;
  vector<ColBase*> cols;
};

class Part : public Table {

public:
  Part () {
    types = { Type::Identifier, Type::Text, Type::Text, Type::Text, Type::Text, 
              Type::Integer, Type::Text, Type::Decimal, Type::Text
            };

  Col<Identifier> P_PARTKEY; Col<Text> P_NAME; Col<Text> P_MFGR; Col<Text> P_BRAND; Col<Text> P_TYPE;
  Col<Integer> P_SIZE; Col<Text> P_CONTAINER; Col<Decimal> P_RETAILPRICE; Col<Text> P_COMMENT;

    cols = {
      &P_PARTKEY, &P_NAME, &P_MFGR, &P_BRAND, &P_TYPE, &P_SIZE, &P_CONTAINER, &P_RETAILPRICE, &P_COMMENT
    };

  }
};