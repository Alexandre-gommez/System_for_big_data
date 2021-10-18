#include "col.hpp"

using namespace std;

class Table
{
public:
  vector<string> m_cols_names;
  vector<string> m_cols_types;
  vector<ColBase*> m_cols;
  int n_row;

  Table() {}

  Table(vector<string> cols_names, vector<string> cols_types)
  {
    n_row = 0;
    m_cols_names = cols_names;
    m_cols_types = cols_types;

    for (int i = 0; i < m_cols_types.size(); i++)
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
    for (int i = 0; i < (int)m_cols.size(); i++)
    {
      m_cols[i]->add_value(data[i]);
    }
    n_row++;
  }

  vector<string> get_row(int l)
  {
    vector<string> temp;
    string token;
    for (int i = 0; i < m_cols_names.size(); i++)
    {
      token = m_cols[i]->get_value(l);
      temp.push_back(token);
    }
    return temp;
  }

  // Méthode print pour l'affichage de la table
  void print() 
  {
    for (int i = 0; i < m_cols_names.size(); i++)
    {
      cout << m_cols_names[i] << " - ";
    }
    cout << endl;

    //int nb_col = m_cols.size();
    for (int l = 0; l < n_row; l++)
    {
      for (const string& word : get_row(l))
      {
        cout << word << " - ";
      }
      cout << endl;
    }
  }

  // Méthode save pour sauvegarder en fichier .tbl
  void save(string filename)
  {
    ofstream file;
    file.open(filename, ios::out);
    for (int l = 0; l < n_row; l++)
    {
      for (const string& word : get_row(l))
      {
        file << word << "|";
      }
      file << endl;
    }
    file.close();
  }

  // Méthode concat pour concaténer 2 tables de même type
  void concat(Table tab2)
  {
    if (m_cols_names == tab2.m_cols_names)
    {
      for (int i =0; i< m_cols.size();i++)
      {
        m_cols[i] -> insert(tab2.m_cols[i]);
      }
      n_row = n_row + tab2.n_row;
    }
  }

};
