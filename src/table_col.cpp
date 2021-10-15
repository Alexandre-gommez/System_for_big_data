#include "table_col.hpp"

int main() {
  vector<string> cols_names = { 
    "P_PARTKEY", "P_NAME", "P_MFGR", "P_BRAND", "P_TYPE",
    "P_SIZE", "P_CONTAINER", "P_RETAILPRICE", "P_COMMENT"
  };
  vector<Type> types = { 
    Type::Identifier, Type::Text, Type::Text, Type::Text, Type::Text, 
    Type::Integer, Type::Text, Type::Decimal, Type::Text
  };
  Table part(cols_names, types);

  for (int i = 0; i < part.cols_names.size(); i++)
    cout << part.cols_names[i] << endl;
  cout << part.n_cols << endl;

  for (int i = 0; i < part.cols.size(); i++)
    part.cols[i].print_values();
  
  return 0;
}