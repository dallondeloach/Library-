#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class Patron{
public:
  Patron();
  Patron(string aName, string anAddress, string aPhone);
  ~Patron();
  string getName();
  void setName(const string aName);
  string getAddress();
  void setAddress(const string anAddress);
  string getPhoneNumber();
  void setPhoneNumber(const string aPhoneNumber);
  void addCheckedBook(Book* aBook);
  void removeCheckedBook(Book *aBook);
  bool isBookCheckedOutByPatron(Book* aBook);

private:
  string name;
  string address;
  string phoneNumber;
  vector<Book*> *listCheckedBooks;
};

#endif //PATRON_H