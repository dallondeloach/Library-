#include <iostream>
#include "Library.h"
using namespace std;

//Main Menu function
int mainMenu(){
  int choice;
  cout<<"--------------------"<<endl;
  cout<<"Main Menu"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"1) Add Patron"<<endl;
  cout<<"2) Add Book"<<endl;
  cout<<"3) Search for Patron"<<endl;
  cout<<"4) Search for Book"<<endl;
  cout<<"5) Check Out Book"<<endl;
  cout<<"6) Return Book"<<endl;
  cout<<"                 99) EXIT"<<endl<<endl;
  cout<<"Enter the number corresponding to your choice: ";
  cin>>choice;
  cout<<endl;
  return choice;
}


int main() {
  int choice=0;
  Library library;
  while(choice!=99){
    choice=mainMenu();
    switch(choice){
      //Option 1
      case 1:{
        string name;
        string address;
        string phoneNumber;
        cout<<"Enter the name of the patron: ";
        cin>>name;
        cout<<endl;
        cout<<"Enter the address of the patron: ";
        cin>>address;
        cout<<endl;
        cout<<"Enter the phone number of the patron: ";
        cin>>phoneNumber;
        cout<<endl;
        library.addPatron(name, address, phoneNumber);
        break;
      }
      //Option 2
      case 2:{
        int choice;
        cout<<"1. Add Printed Book"<<endl<<"2. Add EBook"<<endl<<"3. Add Audio Book";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
          case 1:{
            string title;
            int numPages;
            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter the number of pages: ";
            cin>>numPages;
            library.addPrintedBook(title,numPages);
            break;
          }
          case 2:{
            string title;
            int sizeCharacters;
            int charsPerPage;
            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter the total number of characters in the book: ";
            cin>>sizeCharacters;
            cout<<"Enter the number of characters per page: ";
            cin>>charsPerPage;
            library.addEBook(title,sizeCharacters,charsPerPage);
            break;
          }
          case 3:{
            string title;
            int durationSeconds;
            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter the duration of the book: ";
            cin>>durationSeconds;
            library.addAudioBook(title,durationSeconds);
            break;
          }
        }
        break;
      }
      //Option 3
      case 3:{
        string name;
        Patron* patron;
        cout<<"Enter the name of the patron: ";
        cin>>name;
        patron=library.searchPatron(name);
        if(patron->getName()==name){
          cout<<"Name: "<<patron->getName()<<endl;
          cout<<"Address: "<<patron->getAddress()<<endl;
          cout<<"Phone Number: "<<patron->getPhoneNumber()<<endl;
        }
        break;
      }
      //Option 4
      case 4:{
        string title;
        Book* book;
        cout<<"Enter the title of the book: ";
        cin>>title;
        book=library.searchBook(title);
        if(book->getTitle()==title){
          cout<<book->getBookSizeRepresentation();
        }
        break;
      }
      //Option 5
      case 5:{
        string title, name;
        int year, month, day;
        Book* book;
        Patron* patron;
        cout<<"Enter the title of the book: ";
        cin>>title;
        cout<<endl;
        cout<<"Enter the name of the patron: ";
        cin>>name;
        cout<<endl;
        cout<<"Enter the due date(year month day): ";
        cin>>year;
        cin>>month;
        cin>>day;
        cout<<endl;
        
        book=library.searchBook(title);
        patron=library.searchPatron(name);
        if(book->getTitle()==title && patron->getName()==name){
          library.checkOutBook(book, patron, year, month, day);
        }
        break;
      }
      //Option 6
      case 6:{
        string title, name;
        Book* book;
        Patron* patron;
        cout<<"Enter the title of the book: ";
        cin>>title;
        cout<<endl;
        cout<<"Enter the name of the patron: ";
        cin>>name;
        cout<<endl;
        
        book=library.searchBook(title);
        patron=library.searchPatron(name);
        if(book->getTitle()==title && patron->getName()==name){
          library.returnBook(book, patron);
        }
      }
   
    }
  }
}

