int loading(string file_name, Table table)
{
   string line;
   string delimiter = "|";
   ifstream file(file_name);
   if (file.is_open())
   {
      
      while (!file.eof())
      {
         getline(file, line);
         cout<<line<<endl;
      }
      file.close();
   }
   return 0;
}

/* 
int nb_l_fichier(string file_name)
{
   int numLines = 0;
   std::string line;
   ifstream file(file_name);
   if (file.is_open())
   {
      while (!file.eof())
      {
         getline(file, line);
         if (line.length() > 0)
            numLines++;
      }
      file.close();
   }
   return numLines;
};

void row_nation_loading(nation_tuple *nation_table)
{
   std::string file_name = "..\\Scale 1\\nation.tbl";
   std::string line;
   int pos = 0;
   ifstream file(file_name);
   nation_tuple *tuple;
   tuple = nation_table;
   if (file.is_open())
   {
      getline(file, line);
      while (!file.eof())
      {
         pos = line.find(delimiter);
         (*tuple).N_NATIONKEY = std::stoi(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).N_NAME = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).N_REGIONKEY = std::stoi(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).N_COMMENT = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         tuple++;
         getline(file, line);
      }
      file.close();
   }
};

void row_region_loading(region_tuple *region_table)
{
   std::string delimiter = "|";
   std::string file_name = "..\\Scale 1\\region.tbl";
   std::string line;
   int pos = 0;
   ifstream file(file_name);
   region_tuple *tuple;
   tuple = region_table;
   if (file.is_open())
   {
      getline(file, line);
      while (!file.eof())
      {
         pos = line.find(delimiter);
         (*tuple).R_REGIONKEY = std::stoi(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).R_NAME = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).R_COMMENT = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         tuple++;
         getline(file, line);
      }
      file.close();
   }
};

void row_customer_loading(customer_tuple *customer_table)
{
   std::string delimiter = "|";
   std::string file_name = "..\\Scale 1\\customer.tbl";
   std::string line;
   int pos = 0;
   ifstream file(file_name);
   customer_tuple *tuple;
   tuple = customer_table;
   if (file.is_open())
   {
      getline(file, line);
      while (!file.eof())
      {
         pos = line.find(delimiter);
         (*tuple).C_CUSTKEY = std::stoi(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_NAME = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_ADDRESS = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_NATIONKEY = std::stoi(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_PHONE = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_ACCTBAL = std::stof(line.substr(0, pos));
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_MKTSEGMENT = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         pos = line.find(delimiter);
         (*tuple).C_COMMENT = line.substr(0, pos);
         line.erase(0, pos + delimiter.length());

         tuple++;
         getline(file, line);
      }
      file.close();
   }
};

void test(customer_tuple *customer_table)
{
   std::cout << sizeof(customer_table) << std::endl;
   std::cout << sizeof(*customer_table) << std::endl;
   std::cout << sizeof(customer_tuple) << std::endl;
}; */