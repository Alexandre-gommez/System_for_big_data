#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

// 1. part
typedef struct{
    int P_PARTKEY;
    string P_NAME;
    string P_MFGR;
    string P_BRAND;
    string P_TYPE;
    int P_SIZE;
    string P_CONTAINER;
    float P_RETAILPRICE;
    string P_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(P_PARTKEY));
        temp.push_back(P_NAME);
        temp.push_back(P_MFGR);
        temp.push_back(P_BRAND);
        temp.push_back(P_TYPE);
        temp.push_back(to_string(P_SIZE));
        temp.push_back(P_CONTAINER);
        temp.push_back(to_string(P_RETAILPRICE));
        temp.push_back(P_COMMENT);
        return temp;
    }
}tuple_part;

//2. supplier
typedef struct{
    int S_SUPPKEY;
    string S_NAME;
    string S_ADDRESS;
    int S_NATIONKEY;
    string S_PHONE;
    float S_ACCTBAL;
    string S_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(S_SUPPKEY));
        temp.push_back(S_NAME);
        temp.push_back(S_ADDRESS);
        temp.push_back(to_string(S_NATIONKEY));
        temp.push_back(S_PHONE);
        temp.push_back(to_string(S_ACCTBAL));
        temp.push_back(S_COMMENT);
        return temp;
    }
}tuple_supplier;

//3. PARTSUPP
typedef struct{
    int PS_PARTKEY;
    int PS_SUPPKEY;
    int PS_AVAILQTY;
    float PS_SUPPLYCOST;
    string PS_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(PS_PARTKEY));
        temp.push_back(to_string(PS_SUPPKEY));
        temp.push_back(to_string(PS_AVAILQTY));
        temp.push_back(to_string(PS_SUPPLYCOST));
        temp.push_back(PS_COMMENT);
        return temp;
    }
}tuple_partsupp;

//4. CUSTOMER
typedef struct{
    int C_CUSTKEY;
    string C_NAME;
    string C_ADDRESS;
    int C_NATIONKEY;
    string C_PHONE;
    float C_ACCTBAL;
    string C_MKTSEGMENT;
    string C_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(C_CUSTKEY));
        temp.push_back(C_NAME);
        temp.push_back(C_ADDRESS);
        temp.push_back(to_string(C_NATIONKEY));
        temp.push_back(C_PHONE);
        temp.push_back(to_string(C_ACCTBAL));
        temp.push_back(C_MKTSEGMENT);
        temp.push_back(C_COMMENT);
        return temp;
    }
}tuple_customer;

//5. ORDERS
typedef struct{
    int O_ORDERKEY;
    int O_CUSTKEY;
    string O_ORDERSTATUS;
    float O_TOTALPRICE;
    string O_ORDERDATE;
    string O_ORDERPRIORITY;
    string O_CLERK;
    int O_SHIPPRIORITY;
    string O_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(O_ORDERKEY));
        temp.push_back(to_string(O_CUSTKEY));
        temp.push_back(O_ORDERSTATUS);
        temp.push_back(to_string(O_TOTALPRICE));
        temp.push_back(O_ORDERDATE);
        temp.push_back(O_ORDERPRIORITY);
        temp.push_back(O_CLERK);
        temp.push_back(to_string(O_SHIPPRIORITY));
        temp.push_back(O_COMMENT);
        return temp;
    }
}tuple_orders;

//6. LINEITEM
typedef struct{
    int L_ORDERKEY;
    int L_PARTKEY;
    int L_SUPPKEY;
    int L_LINENUMBER;
    float L_QUANTITY;
    float L_EXTENDEDPRICE;
    float L_DISCOUNT;
    float L_TAX;
    string L_RETURNFLAG;
    string L_LINESTATUS;
    string L_SHIPDATE;
    string L_COMMITDATE;
    string L_RECEIPTDATE;
    string L_SHIPINSTRUCT;
    string L_SHIPMODE;
    string L_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(L_ORDERKEY));
        temp.push_back(to_string(L_PARTKEY));
        temp.push_back(to_string(L_SUPPKEY));
        temp.push_back(to_string(L_LINENUMBER));
        temp.push_back(to_string(L_QUANTITY));
        temp.push_back(to_string(L_EXTENDEDPRICE));
        temp.push_back(to_string(L_DISCOUNT));
        temp.push_back(to_string(L_TAX));
        temp.push_back(L_RETURNFLAG);
        temp.push_back(L_LINESTATUS);
        temp.push_back(L_SHIPDATE);
        temp.push_back(L_COMMITDATE);
        temp.push_back(L_RECEIPTDATE);
        temp.push_back(L_SHIPINSTRUCT);
        temp.push_back(L_SHIPMODE);
        temp.push_back(L_COMMENT);
        return temp;
    }
}tuple_lineitem;

//7. NATION
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

//8. REGION
typedef struct{
    int R_REGIONKEY;
    string R_NAME;
    string R_COMMENT;

    vector<string> vector_()
    {
        vector<string> temp;
        temp.push_back(to_string(R_REGIONKEY));
        temp.push_back(R_NAME);
        temp.push_back(R_COMMENT);
        return temp;
    }
}tuple_region;
