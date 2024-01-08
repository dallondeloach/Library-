#include "Book.h"

Book::Book(){
  title="";
  }

Book::Book(string aTitle){
  title=aTitle;
}

Book::~Book(){
  patron=nullptr;
}

string Book::getTitle(){
  return title;
}

void Book::setTitle(string aTitle){
  title=aTitle;
}

Patron* Book::getCurrentPatron(){
  return this->patron;
}
//Sets the patron who has checked out the book
void Book::checkOut(Patron* aPatron){
  patron=aPatron;
}

void Book::returnBook(){
  patron=nullptr;
}
//Returns if the book is checked out
bool Book::isCheckedOut(){
  if(patron!=nullptr){
    return true;
  }
  else{
    return false;
  }
}

string Book::toString(){
  return title+" "+getBookSizeRepresentation();
}


