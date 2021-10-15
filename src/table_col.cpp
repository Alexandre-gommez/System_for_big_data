#include "table_col.hpp"

int main() {
  Part part;

  for (int i = 0; i < part.col_names.size(); i++)
    cout << part.col_names[i] << endl;
  cout << part.n_cols;

  return 0;
}