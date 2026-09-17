#include <iostream>
#include <vector>
#include "Item.h"
#include "Book.h"
#include "Device.h"
#include <fstream>
#include <string>
using namespace std;



Item* findById(vector<Item*>& shelf, int id );

int main()
{
    vector<Item*> shelf;
    int choice;
    do 
    {
        //print the job menu
        cout << "===== Mini Library Desk =====" << endl << "1. Add book" << endl << "2. Add device" << endl << "3. List all" << endl;
        cout << "4. Find by ID" << endl << "5. Borrow" << endl << "6. Return" << endl << "7. Delete" << endl << "8. Save" << endl << "9. Load" << endl << "0. Quit" <<endl;
        cout << "Choice:" ;
        cin >> choice;
        cout<<endl;

        switch(choice)
        {
            case 1 :
            {
             int id ;
             string title;
             string author;

             cout<<"ID: ";
             cin>>id;
             cout<<endl;

             cout<<"Title: ";
             cin>>title;
             cout<<endl;

             cout<<"Author:";
             cin>>author;
             cout<<endl;

             if(findById(shelf,id) == nullptr)
             {
                shelf.push_back(new Book(id , title , author));
                cout<<"Added."<<endl;
             }
             else{
                cout<<"ID already exists"<<endl;
             }

             break;
            }

             case 2 :
            {
              int id2;
              string title2;
              string location;

              cout<<"ID: ";
              cin>>id2;
              cout<<endl;

              cout<<"Title: ";
              cin>>title2;
              cout<<endl;

              cout<<"Location: ";
              cin>>location;
              cout<<endl;

              if(findById(shelf,id2) == nullptr)
             {
                shelf.push_back(new Device(id2 , title2 , location));
                cout<<"Added."<<endl;
             }
             else{
                cout<<"ID already exists"<<endl;
             }
             break;
            }

            case 3 :
            {
                if(shelf.empty())
                {
                    cout<<"Shelf is empty."<<endl;
                    break;
                }
                else 
                {
                    for (int i = 0 ; i < shelf.size() ; i ++)
                    {
                        shelf[i]->display();
                    }

                }
                break;
            }

            case 4 :
            {
                int id3;
                cout<<"ID: ";
                cin>>id3;
                cout<<endl;

                Item* item = findById(shelf, id3);
                if(item != nullptr)
                {
                   item->display();
                }
                else
                {
                   cout << "ID not found" << endl;
                }

                break;


            }
            case 5 :
            { 
                int id4;
                cout<<"ID: ";
                cin>>id4;
                cout<<endl;
                Item* item = findById(shelf, id4);
                
            

                if(item == nullptr)
                {
                    cout << "ID not found" << endl;
                }
                else if(item->isBorrowed())
                {
                     cout << "Already Borrowed" << endl;
                }
                else
                {
                    item->borrow();
                     cout << "borrowed" << endl;
                }
                break;


            }
            case 6 :
            {
                int id5;
                cout<<"ID: ";
                cin>>id5;
                cout<<endl;
                Item* item = findById(shelf, id5);
                
                if(item == nullptr)
                {
                    cout << "ID not found" << endl;
                }
                else if(!item->isBorrowed())
                {
                     cout << "Not borrowed" << endl;
                }
                else
                {
                    item->giveBack();
                     cout << "Returned" << endl;
                }
                break;

            }

            case 7 :
            {   
                char answer;
                int id6;
                cout<<"ID: ";
                cin>>id6;
                cout<<endl;
                Item* item = findById(shelf, id6);
                
                if(item == nullptr)
                {
                    cout << "ID not found" << endl;
                }
                else if(item->isBorrowed())
                {
                     cout << "return first" << endl;
                }
                else
                {   
                    cout << "Delete " << id6 << "? (y/n): ";
                    cin >> answer;

                    if(answer == 'y' || answer == 'Y')
                    {
                        for(int i = 0; i < shelf.size(); i++)
                        {
                            if(shelf[i]->getId() == id6)
                            {
                                delete shelf[i];
                                shelf.erase(shelf.begin() + i);
                                cout << "Deleted" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                
                break;
    
            }

            case 8 :
            {
                ofstream out("library.csv");
                if(out.is_open())
                {
                    for(int i = 0; i < shelf.size(); i++)
                    {
                        out << shelf[i]->toCsv() << endl;
                    }
                    out.close();

                    cout << "Saved." << endl;
                }
                else
                {
                    cout << "No library file yet." << endl;
                }
                break;
            }

            case 9:
            {
                 for(int i = 0; i < shelf.size(); i++)
                {
                     delete shelf[i];
                }

                 shelf.clear();

                ifstream in("library.csv");

                 if(!in.is_open())
                {
                     cout << "No library file yet." << endl;
                     break;
                }

                 string line;
                 bool loadedSomething = false;

                 while(getline(in, line))
                {
                    if(line.empty())
                    {
                        continue;
                    }

                    loadedSomething = true;

                    int c1 = line.find(',');
                    int c2 = line.find(',', c1 + 1);
                    int c3 = line.find(',', c2 + 1);
                    int c4 = line.find(',', c3 + 1);

                    string type = line.substr(0, c1);
                    string idStr = line.substr(c1 + 1, c2 - c1 - 1);
                    string title = line.substr(c2 + 1, c3 - c2 - 1);
                    string extra = line.substr(c3 + 1, c4 - c3 - 1);

                    bool borrowed = stoi(line.substr(c4 + 1));

                    int id = stoi(idStr);

                    Item* item = nullptr;

                    if(type == "B")
                    {
                         item = new Book(id, title, extra);
                    }
                    else if(type == "D")
                    {
                        item = new Device(id, title, extra);
                    }

                    if(item != nullptr)
                    {
                        if(borrowed)
                        {
                             item->borrow();
                        }

                        shelf.push_back(item);
                    }
                }

                in.close();

                if(!loadedSomething)
                {
                     cout << "Shelf is empty." << endl;
                }
                else
                {
                     cout << "Loaded." << endl;
                }

                break;
            }

            case 0 :
            {
                for(int i = 0; i < shelf.size(); i++)
                {
                     delete shelf[i];
                }
                shelf.clear();
                cout << "Goodbye" << endl;
                break;
            }

            default :
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
            
    } while(choice != 0);

    return 0;

}

// define functions
Item* findById(vector<Item*>& shelf, int id )
{
    for(int i = 0; i < shelf.size(); i++)
    {
        if(shelf[i]->getId() == id)
        {
            return shelf[i];
        }
        
    }
    return nullptr;
}