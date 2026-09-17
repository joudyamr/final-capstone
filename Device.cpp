#include<iostream>
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
        cout << "borrowed";
    }
    else {
        cout << "available";
    }

    cout << endl;
}
string Device::toCsv() const
{
    return "D," + to_string(getId()) + "," + getTitle() + "," + getLocation() + "," + to_string(isBorrowed());

}