#include "Library.h"

Library::Library(){
  name="";
}

Library::Library(string libraryName){
  name=libraryName;
}

Library::~Library(){
  for(int i=0; i<this->loans->size();i++){
    delete this->loans->at(i);
    this->loans->at(i)=nullptr;
  }

  for(int i=0; i<this->patrons->size();i++){
    delete this->patrons->at(i);
    this->patrons->at(i)=nullptr;
  }

  for(int i=0; i<this->books->size();i++){
    delete this->books->at(i);
    this->books->at(i)=nullptr;
  }
  delete this->loans;
  delete this->patrons;
  delete this->books;
}

string Library::getName(){
  return name;
}
//Searches for book with the same title
Book* Library::searchBook(string title){
  for(int i=0; i<this->books->size();i++){
    if(this->books->at(i)->getTitle()==title){
      return this->books->at(i);
    } 
  }
}
//Searches for patron with the same name
Patron* Library::searchPatron(string name){
  for(int i=0; i<this->patrons->size();i++){
    if(this->patrons->at(i)->getName()==name){
      return this->patrons->at(i);
    }
  }
}

//Adds printed book to the vector
void Library::addPrintedBook(string title, int numPages){
  Book *book;
  book = searchBook(title);
  if(book==nullptr){
    Book *newBook = new PrintedBook(numPages);
    newBook->setTitle(title);
    this->books->push_back(newBook);
  }
}
  
//Adds ebook to the vector
void Library::addEBook(string title, int sizeCharacters, int charsPerPage){
  Book *book;
  book = searchBook(title);
  if(book==nullptr){
    Book *newBook = new EBook(sizeCharacters, charsPerPage);
    newBook->setTitle(title);
    this->books->push_back(newBook);
  }
}

//adds audiobook to the vector
void Library::addAudioBook(string title, int durationSeconds){
  Book *book;
  book = searchBook(title);
  if(book==nullptr){
    Book *newBook = new AudioBook(durationSeconds);
    newBook->setTitle(title);
    this->books->push_back(newBook);
  }
}


//Adds patron the appropriate list
void Library::addPatron(string name, string address, string phoneNumber){
  Patron* patron;
  patron = searchPatron(name);
  if(patron==nullptr){
    Patron *newPatron = new Patron();
    newPatron->setName(name);
    newPatron->setAddress(address);
    newPatron->setPhoneNumber(phoneNumber);
    this->patrons->push_back(newPatron);
  }
}
//Adds book to loans list
void Library::checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay){
  if(aBook&&aPatron != nullptr){
    Loan *newLoan= new Loan(aBook, aPatron, dueYear, dueMonth, dueDay);
    this->loans->push_back(newLoan);
    aPatron->addCheckedBook(aBook);
    aBook->checkOut(aPatron);
  }
}
//Removes from loans list
void Library::returnBook(Book* aBook, Patron* aPatron){
  if(aBook&&aPatron != nullptr){
    for(int i=0; i<this->loans->size();i++){
      if(this->loans->at(i)->getBook()==aBook && this->loans->at(i)->getPatron()==aPatron){
        aPatron->removeCheckedBook(aBook);
        aBook->checkOut(aPatron);
        this->loans->erase(this->loans->at(i));
      }
    }
  }
}



