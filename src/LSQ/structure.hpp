typedef struct{
    int C_CUSTKEY;
    std::string C_NAME;
    std::string C_ADDRESS;
    int C_NATIONKEY;
    std::string C_PHONE;
    float C_ACCTBAL;
    std::string C_MKTSEGMENT;
    std::string C_COMMENT;
}customer_tuple;

typedef struct{
    int N_NATIONKEY;
    std::string N_NAME;
    int N_REGIONKEY;
    std::string N_COMMENT;
}nation_tuple;

typedef struct{
    int R_REGIONKEY;
    std::string R_NAME;
    std::string R_COMMENT;
}region_tuple;

//typedef struct{
//    std::vector<int> N_NATION;
//    std::vector<std::string> N_NAME;
//    std::vector<int> N_REGIONKEY;
//    std::vector<std::string> N_COMMENT;
//}nation_col;