#include <iostream>
#include <vector>

using namespace std;

enum class FieldType {
  // Scalar types:
  Boolean, Integer, FloatingPoint, String,

  // Array types:
  ArrayBit = 0x1000, // This bit set for array types
  Boolean_Array = Boolean | ArrayBit,
  Integer_Array, FloatingPoint_Array, String_Array
};

class FieldSchema {
  FieldType m_type;
  string    m_name;  // Optional, if fields are named

public:
  FieldSchema (FieldType m_type, string m_name) : m_type(m_type), m_name(m_name) {}
};

// ATTENTION MAXIMUM LENGTH DES STRING = 50
union FieldValue {
  bool   m_boolean;
  int    m_integer;
  double m_floatingpoint;
  char m_string[50];
};

class Row {

public:
  vector<FieldSchema> row_schema;
  vector<FieldValue> row_value;

  Row () {}

  // marche pas help j'ai pas envie de copier chaque truc dans les attributs à la main
  Row (vector<FieldSchema> row_schema, vector<FieldValue> row_value) {
    row_schema = row_schema;
    row_value = row_value;
  }

  vector<FieldSchema> get_row_schema () const {
    return row_schema;
  }

  vector<FieldValue> get_row_value () const {
    return row_value;
  }
};

class Table {

public:
  vector<Row> table_value;
};