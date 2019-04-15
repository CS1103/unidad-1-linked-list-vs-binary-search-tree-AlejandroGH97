#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    //Variables para guardar datos en estructuras
    std::string temp_string;
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;


    // Grabar Datos del archivo "Locations.csv" en ll

    std::ifstream locations_ll(LOCATION_FILE);

    getline(locations_ll, temp_string);

    while(!locations_ll.eof()){

        getline(locations_ll, temp_string, ',');
        position_id = std::stoi(temp_string);

        getline(locations_ll, state_code, ',');
        getline(locations_ll, county, ',');
        getline(locations_ll, temp_string, ',');
        latitude = std::stof(temp_string);
        getline(locations_ll, temp_string, ',');
        longitude = std::stof(temp_string);
        getline(locations_ll, line, ',');
        getline(locations_ll, construction, '\n');
        Location *location_temp_ll = new Location(position_id, state_code, county, latitude, longitude, line, construction);
        ll.add_tail(*location_temp_ll);
    }
    locations_ll.close();


    //
    // Grabar Datos del archivo "Locations.csv" en bst
    std::ifstream locations_bst(LOCATION_FILE);
    getline(locations_bst, temp_string);

    while(!locations_bst.eof()){

        getline(locations_bst, temp_string, ',');
        position_id = std::stoi(temp_string);

        getline(locations_bst, state_code, ',');

        getline(locations_bst, county, ',');

        getline(locations_bst, temp_string, ',');
        latitude = std::stof(temp_string);

        getline(locations_bst, temp_string, ',');
        longitude = std::stof(temp_string);

        getline(locations_bst, line, ',');

        getline(locations_bst, construction, '\n');

        Location *location_temp_bst = new Location(position_id, state_code, county, latitude, longitude, line, construction);
        bst.insert(bst.get_root(),*location_temp_bst);
    }
    locations_bst.close();

    //bst.search(398149)->data.print();
    //ll.find_id(398149)->data.print();


    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream locations_search(SEARCH_FILE);
    while(!locations_search.eof()){
        getline(locations_search,temp_string,'\n');
        position_id = stoi(temp_string);
        vsearch.push_back(position_id);
    }
    locations_search.close();




    double avgtime_ll = 0;
    double avgtime_bst = 0;
    clock_t inicio;
    int entradas = 0;



    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    //for (const auto& id: vsearch) {}

        // Buscar en ll
    inicio = clock();
    for (const auto& id: vsearch) {
        ll.find_id(id);
        entradas++;
    }
    avgtime_ll = (clock()-inicio)*1000000.0/CLOCKS_PER_SEC/entradas;


        // Buscar en bsd
        inicio = clock();
    for (const auto& id: vsearch) {
        bst.search(id);
    }
    avgtime_bst = (clock()-inicio)*1000000.0/CLOCKS_PER_SEC/entradas;


    std::cout<<"AVG time ll: "<<avgtime_ll<<" microsegundos."<<std::endl;
    std::cout<<"AVG time bst: "<<avgtime_bst<<" microsegundos."<<std::endl;

    return 0;
}