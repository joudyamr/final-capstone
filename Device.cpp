#include<iostream>
#include "Item.h"
#include "Device.h"
using namespace std;


Device :: Device ( int i , string t , string l):Item(i , t){
    location = l;
}

string Device::getLocation() const{
    return location;
}

void Device::display() const{
    cout<<"["<<"Device"<<"] " << Item::getId() << " | " << Item::getTitle()<<" | "<<getLocation()<<" | ";
    if (isBorrowed()) {
        cout << "Borrowed";
    }
    else {
        cout << "Available";
    }

    cout << endl;
}