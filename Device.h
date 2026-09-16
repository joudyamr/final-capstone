#pragma once 
#include <iostream>
#include "Item.h"

class Device : public Item {
    private :
    std::string location ;
    
    public:
    Device (int i , std::string t , std::string l):Item(i , t){}
    std::string getLocation() const;
    void display() const override;


};