#pragma once
#include <iostream>


class Item 
{
     private :

     int id;
     std::string title;
     bool borrowed;

     public:

     Item (int id , std::string title );
     int getId() const;
     std::string getTitle() const;
     bool isBorrowed() const;
     void borrow();
     void giveBack();
     virtual void display() const;
     virtual ~Item();
     virtual std::string toCsv() const = 0;



};
