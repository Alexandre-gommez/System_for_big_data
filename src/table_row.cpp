#include "table_row.hpp"
#include "string.h"

int main () {
    FieldSchema id_schema(FieldType::Integer, "id");
    FieldSchema name_schema(FieldType::String, "name");
    vector<FieldSchema> row_schema{id_schema, name_schema};

    FieldValue id_value; id_value.m_integer = 123;
    FieldValue name_value; strcpy(name_value.m_string, "José Bové");
    vector<FieldValue> row_value{id_value, name_value};

    Row row1;
    row1.row_value = row_value;

    cout << row1.get_row_value()[0].m_integer << endl;
    cout << row1.get_row_value()[1].m_string << endl;

    return 0;
}