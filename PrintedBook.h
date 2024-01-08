#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include <string>
#include "Book.h"

using namespace std;

class PrintedBook: public Book{
public:
  PrintedBook(int aNumPages);
  ~PrintedBook();
  string getBookSizeRepresentation() override;
private:
  int numPages;
};

#endif //PRINTEDBOOK_H