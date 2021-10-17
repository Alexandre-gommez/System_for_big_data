#include "col.hpp"
using namespace std;
class Table
{
public:
  vector<string> m_cols_names;
  vector<string> m_cols_types;
  vector<ColBase *> m_cols;
  int n_row;

  Table() {}

  Table(vector<string> cols_names, vector<string> cols_types)
  {
    n_row=0;
    m_cols_names = cols_names;
    m_cols_types = cols_types;
    m_size = 0;
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
    for (int i = 0; i < (int) m_cols.size(); i++)
    {
      m_cols[i]->add_value(data[i]);
    }
    n_row++;
  }

  void sum(string query_col_name)
  {
    int i = -1;   //En sortie de boucle l'itérateur ne prend pas +1
    bool test = true; 
    while (i < (int)m_cols_names.size() && test)
    {
      i++;
      test = (query_col_name != m_cols_names[i]);
    }
    if ((m_cols_types[i]==("Integer")) || (m_cols_types[i]==("Float")))
    {
      cout << "La moyenne de la colonne : " << query_col_name << " est egale a : " << m_cols[i]->sum() << endl;
    }
    else
    {
      cout << "On ne peux sommer le type de cette colonne" << endl;
    }
  }

  Table *selection(vector <string> query)
  {
    vector <string> col_typ;
    //On récupère les colonnes et leur type pour construire la nouvelle table
    int limit = query.size();
    int n_cols = m_cols_types.size();
    for(int i=0;i<n_cols;i++)
    {
      for(int j=0;j<limit;j++)
      {
        if(m_cols_names[i]==query[j])
        {
          col_typ.push_back(m_cols_types[i]);
        }
      }
    }
    //Création de la table que l'on va retourner 
    Table *res=new Table(query,col_typ);
    res->n_row=n_row;
    //Ajout de la valeur des colonnes de cette nouvelle table;
    for (int i = 0; i < n_cols; i++)
    {
      for(int j=0;j<limit;j++)
      {
        if (m_cols_names[i] ==res->m_cols_names[j])
        {
          cout<<"Wsh on est la"<<endl;
          ColBase *tmp=new ColBase();
          tmp=m_cols[i];
          tmp->print_values();
          res->m_cols.push_back(tmp);
        }
      }
    }
    return(res);
  }

  void print()      // création de la méthode print pour l'affichage de la table
  {
    for (int i = 0; i < m_cols_names.size(); i++)
    {
      cout << m_cols_names[i] << " - ";
    }
    cout << endl;
    
    int nb_col = m_cols.size();
    for (int l = 0; l < m_size; l++)
    {
      for (int i = 0; i < nb_col; i++)
      {
        m_cols[i]->get_value(l);
        cout << " - ";
      }
      cout << endl;
    }
  }
};
