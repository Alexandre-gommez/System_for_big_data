#include <fstream>
#include "structure.hpp"

using namespace std;
//1. PART**************************************************************
class Table_row_p
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_part> m_tuples;
    int n_row;

    Table_row_p() {}

    Table_row_p(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_part tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.P_PARTKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_NAME = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_MFGR = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_BRAND = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_TYPE = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_SIZE = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());
            
                pos = line.find(delimiter);
                tuple.P_CONTAINER = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_RETAILPRICE = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.P_COMMENT = line.substr(0, pos) ;
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

    void concat(Table_row_p tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};

//2. SUPPLIER**************************************************************
class Table_row_s
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_supplier> m_tuples;
    int n_row;

    Table_row_s() {}

    Table_row_s(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_supplier tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.S_SUPPKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_NAME = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_ADDRESS = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_NATIONKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_PHONE = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_ACCTBAL = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.S_COMMENT = line.substr(0, pos) ;
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

    void concat(Table_row_s tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};

//3. PARTSUPP**************************************************************
class Table_row_ps
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_partsupp> m_tuples;
    int n_row;

    Table_row_ps() {}

    Table_row_ps(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_partsupp tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.PS_PARTKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.PS_SUPPKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.PS_AVAILQTY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.PS_SUPPLYCOST = std::stof(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.PS_COMMENT = line.substr(0, pos) ;
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

    void concat(Table_row_ps tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};

//4. CUSTOMER**************************************************************
class Table_row_c
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_customer> m_tuples;
    int n_row;

    Table_row_c() {}

    Table_row_c(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_customer tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.C_CUSTKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_NAME = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_ADDRESS = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_NATIONKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_PHONE = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_ACCTBAL = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_MKTSEGMENT = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.C_COMMENT = line.substr(0, pos) ;
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

    void concat(Table_row_c tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};

//7. NATION**************************************************************
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

//8. REGION**************************************************************
class Table_row_r
{
public:
    vector<string> m_cols_names;
    vector<string> m_cols_types;
    vector<tuple_region> m_tuples;
    int n_row;

    Table_row_r() {}

    Table_row_r(vector<string> cols_names, vector<string> cols_types, string file_name)
    {
        n_row = 0;
        m_cols_names = cols_names;
        m_cols_types = cols_types;
        ifstream file(file_name);
        string line;
        string delimiter = "|";
        tuple_region tuple;
        int pos=0;
        if (file.is_open())
        {
            getline(file, line);
            while (!file.eof())
            {
                pos = line.find(delimiter);
                tuple.R_REGIONKEY = std::stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.R_NAME = line.substr(0, pos) ;
                line.erase(0, pos + delimiter.length());

                pos = line.find(delimiter);
                tuple.R_COMMENT = line.substr(0, pos) ;
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

    void concat(Table_row_r tab2)
    {
        for (int i = 0; i < tab2.n_row; i++)
        {
            n_row ++;
            m_tuples.push_back(tab2.m_tuples[i]);
        }
    }
};