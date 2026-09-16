#pragma once
#include <iostream>
#include "Item.h"

class Book : public Item {
    private:
    std:: string author;
    
    public:
    Book(int i , std::string t ,  std::string a);
    std:: string getAuthor() const;
    void display() const override;



    



};