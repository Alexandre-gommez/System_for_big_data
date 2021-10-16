#include "table.hpp"

int main() {
  vector<string> cols_names = { 
    "P_PARTKEY", "P_NAME", "P_MFGR", "P_BRAND", "P_TYPE",
    "P_SIZE", "P_CONTAINER", "P_RETAILPRICE", "P_COMMENT"
  };
  vector<string> types = { 
    "Integer","55", "25", "10", "25", "Integer", "10", "Float", "23"
  };
  Table part(cols_names, types);

  vector<string> values = { 
    "5","test1", "test2", "test3", "test4", "10", "test5", "5.5", "test6"
  };

  part.add_row(values);

  for (int i = 0; i < part.m_cols_names.size(); i++)
    cout << part.m_cols_names[i] << endl;

  for (int i = 0; i < part.m_cols.size(); i++)
    part.m_cols[i]->print_values();
  
  return 0;
}