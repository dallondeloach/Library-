
#include "Patron.h"

Patron::Patron(){
  name="";
  address="";
  phoneNumber="";
  this->listCheckedBooks= new vector<Book*>;
}
Patron::Patron(string aName, string anAddress, string aPhone){
  name=aName;
  address=anAddress;
  phoneNumber=aPhone;
}
Patron::~Patron(){
  listCheckedBooks=nullptr;
}

string Patron::getName(){
  return name;
}
void Patron::setName(const string aName){
  name = aName;
}

string Patron::getAddress(){
  return address;
}
void Patron::setAddress(const string anAddress){
  address = anAddress;
}

string Patron::getPhoneNumber(){
  return phoneNumber;
}

void Patron::setPhoneNumber(const string aPhoneNumber){
  phoneNumber=aPhoneNumber;
}

void Patron::addCheckedBook(Book* aBook){
  this->listCheckedBooks->push_back(aBook);
}

void Patron::removeCheckedBook(Book *aBook){
  for(int i=0; i<this->listCheckedBooks->size();i++){
    if(this->listCheckedBooks->at(i)==aBook){
      listCheckedBooks->erase(this->listCheckedBooks->at(i));
      break;
    }
  }
}

bool Patron::isBookCheckedOutByPatron(Book* aBook){
  for(int i=0; i<this->listCheckedBooks->size();i++){
    if(this->listCheckedBooks->at(i)==aBook){
      return true;
    }
  }
}