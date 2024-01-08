#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Patron.h"
#include "Date.h"

class Loan{
public:
  Loan();
  Loan(Book* aBook, Patron* aPatron, int year, int month, int day);
  ~Loan();
  Book* getBook();
  Patron* getPatron();
  Date getDueDate();
  bool isExpired();

private:
  Book* book;
  Patron* patron;
  int aYear,aMonth, aDay;
};

#endif //LOAN_H