#include <iostream>
#include <vector>
#include "col.hpp"

using namespace std;

class Table
{
public:
  vector<string> m_cols_names;
  vector<string> m_cols_types;
  vector<ColBase *> m_cols;

  Table() {}

  Table(vector<string> cols_names, vector<string> cols_types)
  {
    m_cols_names = cols_names;
    m_cols_types = cols_types;
    int n_cols = m_cols_types.size();
    for (int i = 0; i < n_cols; i++)
    {
      if (cols_types[i] == "Integer")
        m_cols.push_back(new ColInt());
      else if (cols_types[i] == "Float")
        m_cols.push_back(new ColFloat());
      else
        m_cols.push_back(new ColChar(stoi(cols_types[i])));
    }
  }

  void add_row(vector<string> data)
  {
    for (int i = 0; i < m_cols.size(); i++)
    {
      m_cols[i]->add_value(data[i]);
    }
  } 
};