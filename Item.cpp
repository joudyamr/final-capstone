#include <iostream>
#include "Item.h"
using namespace std;

Item :: Item (int id , string title ){
    id = id;
    title = title ;
    borrowed = false;

}

int Item::getId() const {
    return id;
}

string Item::getTitle() const {
    return title;
}

 bool Item::isBorrowed() const {
        return borrowed;
 }

 void Item::borrow() {
    borrowed = true;
 }

 void Item::giveBack() {
    borrowed = false;
 }

 void Item::display() const {}

 Item::~Item() {}




