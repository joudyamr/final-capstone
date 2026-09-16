
#include <iostream> 
#include "Book.h"
#include "Item.h"

using namespace std;

Book :: Book (int i , string t , string a):Item(i , t){
    author = a;
}

string Book::getAuthor() const{
    return author;
}

void Book::display() const {
    
    cout<<"["<<"Book"<<"] " << Item::getId() << " | " << Item::getTitle()<<" | "<<getAuthor()<<" | ";
    if (isBorrowed()) {
        cout << "borrowed";
    }
    else {
        cout << "available";
    }

    cout << endl;

}