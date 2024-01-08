#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Patron.h"
using namespace std;

class Book{
public:
  Book();
  Book(string aTitle);
  virtual ~Book();
  string getTitle();
  void setTitle(string aTitle);
  Patron* getCurrentPatron();
  void checkOut(Patron* aPatron);
  void returnBook();
  bool isCheckedOut();
  string toString();
  virtual string getBookSizeRepresentation() = 0;
  
  
  

private:
  string title;
  Patron* patron;

};

#endif //BOOK_H