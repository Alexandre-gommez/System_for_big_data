int loading(string file_name, Table *table)
{
   string line;
   string delimiter = "|";
   int pos = 0;
   vector<string> temp;
   ifstream file(file_name);
   if (file.is_open())
   {
      getline(file, line);
      while (!file.eof())
      {
         pos = line.find(delimiter);
         while (pos>0)
         {
            temp.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
            pos = line.find(delimiter);
         }
         getline(file, line);
         (*table).add_row(temp);
         temp.clear();
      }
      file.close();
   }
   //(*table).m_cols[1]->print_values();
   //cout << "fin load - size : " << (*table).m_size << endl;
   return 0;
}