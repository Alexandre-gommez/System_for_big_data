#include <fstream>
#include "structure.hpp"

using namespace std;

class Table_row_n
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_nation> m_tuples;
    int n_row;

    Table_row_n() {}

    Table_row_n(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_nation tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.N_NATIONKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.N_NAME = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.N_REGIONKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.N_COMMENT = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                m_tuples.push_back(tuple);
                n_row ++;
                getline(file,line);
            }
            file.close();
        }
    }


    void print()
    {
        for (int i = 0; i < n_row; i++)
        {
            for (const string word : m_tuples[i].vector_())
            {
                cout << word << " - ";
            }
            cout << endl;
        }
    }

    void concat(Table_row_n tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};