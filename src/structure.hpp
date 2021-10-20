#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct{
    int C_CUSTKEY;
    string C_NAME;
    string C_ADDRESS;
    int C_NATIONKEY;
    string C_PHONE;
    float C_ACCTBAL;
    string C_MKTSEGMENT;
    string C_COMMENT;
}tuple_customer;

typedef struct{
    int N_NATIONKEY;
    string N_NAME;
    int N_REGIONKEY;
    string N_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(N_NATIONKEY));
        temp.push_back(N_NAME);
        temp.push_back(to_string(N_REGIONKEY));
        temp.push_back(N_COMMENT);

        return temp;
    }
}tuple_nation;

typedef struct{
    int R_REGIONKEY;
    string R_NAME;
    string R_COMMENT;
}tuple_region;

//typedef struct{
//    std::vector<int> N_NATION;
//    std::vector<std::string> N_NAME;
//    std::vector<int> N_REGIONKEY;
//    std::vector<std::string> N_COMMENT;
//}nation_col;