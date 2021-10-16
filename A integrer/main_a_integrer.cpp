#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "structure.hpp"
#include "db_loading.hpp"


using namespace std;

int main(){
   std::string file_name;
   int nb_nation, nb_region, nb_customer;

   // Table nation
   file_name = "..\\Scale 1\\nation.tbl";
   nb_nation = nb_l_fichier(file_name);
   nation_tuple nation_table[nb_nation];
   row_nation_loading(&nation_table[0]);
   std::cout << "Fin nation - " << nb_nation<< std::endl;
   
   // Table region
   file_name = "..\\Scale 1\\region.tbl";
   nb_region = nb_l_fichier(file_name);
   region_tuple region_table[nb_region];
   row_region_loading(&region_table[0]);
   std::cout << "Fin region - " << nb_region << std::endl;

   // Table customer
   file_name = "..\\Scale 1\\customer.tbl";
   nb_customer = nb_l_fichier(file_name);
   int t = (nb_customer +nb_region + nb_nation) * sizeof(customer_tuple)/1000;
   std::cout << t << " k" << std::endl;
   customer_tuple customer_table[11240]; //11240
   std::cout << "Customer " << sizeof(customer_table) << std::endl;
//   row_customer_loading(&customer_table[0]);
   test(&customer_table[0]);
   
   std::cout << "ici2 " << nb_nation << std::endl;

   for (int cpt=0 ; cpt<nb_nation ; cpt++ ){
      std::cout << cpt << " - ";
      std::cout << (nation_table[cpt]).N_NAME << " - "; 
      std::cout << (nation_table[cpt]).N_NATIONKEY << " - ";
      std::cout << (nation_table[cpt]).N_COMMENT << std::endl;
   }

   return 0;
}