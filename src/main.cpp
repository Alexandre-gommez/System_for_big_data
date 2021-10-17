#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

#include "col.hpp"
#include "table.hpp"
#include "db_loading.hpp"

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

  loading("..\\data\\nation.tbl",part);
  vector<string> quer = {"P_PARTKEY","P_RETAILPRICE","P_COMMENT"};
  Table *subpart = part.selection(quer);
  subpart->sum("P_PARTKEY");
  vector<string> *tmp=new vector<string>;
  *tmp=quer;
  cout<<(*tmp)[0]<<endl;
  
  return 0;
}