#include "table.hpp"

void sum(string query_col_name, Table t)
{
    int index = -1;
    for (int i = 0; i < t.m_cols_names.size(); i++)
        if (query_col_name == t.m_cols_names[i])
            index = i;
    
    if ((t.m_cols_types[index] == ("Integer")) || (t.m_cols_types[index] == ("Float")))
    {
        cout << "La moyenne de la colonne : " << query_col_name << " est egale a : " << t.m_cols[index]->sum() << endl;
    }
    else
    {
        cout << "On ne peux sommer le type de cette colonne" << endl;
    }
}

Table selection(vector<string> query, Table t)
{
    vector<string> col_typ;
    //On récupère les colonnes et leur type pour construire la nouvelle table
    int limit = query.size();
    int n_cols = t.m_cols_types.size();
    for (int i = 0; i < n_cols; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            if (t.m_cols_names[i] == query[j])
            {
                col_typ.push_back(t.m_cols_types[i]);
            }
        }
    }
    //Création de la table que l'on va retourner
    Table res(query, col_typ);
    res.n_row = t.n_row;
    //Ajout de la valeur des colonnes de cette nouvelle table;
    for (int i = 0; i < n_cols; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (t.m_cols_names[i] == query[j])
            {
                res.m_cols[j] = t.m_cols[i];
            }
        }
    }
    return res;
}