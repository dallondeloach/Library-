#include "Loan.h"

Loan::Loan(){
  book=nullptr;
  patron=nullptr;
  aYear=0;
  aMonth=0;
  aDay=0;
}

Loan::Loan(Book* aBook, Patron* aPatron, int year, int month, int day){
  book = aBook;
  patron = aPatron;
  aYear = year;
  aMonth = month;
  aDay = day;
}

Loan::~Loan(){
  book=nullptr;
  patron=nullptr;
}

Book* Loan::getBook(){
  return this->book;
}

Patron* Loan::getPatron(){
  return this->patron;
}

Date Loan::getDueDate(){
  return Date(aYear, aMonth, aDay);
}