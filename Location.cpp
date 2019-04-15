//
// Created by ruben on 4/5/19.
//

#include "Location.h"
#include <iostream>
Location::Location(int position_id, std::string state_code, std::string county, double latitude, double longitude,
                   std::string line, std::string construction) {
    this->position_id=position_id;
    this->state_code=state_code;
    this->county=county;
    this->latitude=latitude;
    this->longitude=longitude;
    this->line=line;
    this->construction=construction;

}

// Defina los metodos que crea necesario

int Location::getID(){
    return position_id;
}

void Location::print(){
    std::cout<<"Position ID: \t"<<position_id<<std::endl;
    std::cout<<"State code: \t"<<state_code<<std::endl;
    std::cout<<"County: \t\t"<<county<<std::endl;
    std::cout<<"Latitude: \t\t"<<latitude<<std::endl;
    std::cout<<"Longitude: \t\t"<<longitude<<std::endl;
    std::cout<<"Line: \t\t\t"<<line<<std::endl;
    std::cout<<"Construction: \t"<<construction<<std::endl;

}