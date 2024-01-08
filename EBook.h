#ifndef EBOOK_H
#define EBOOK_H

#include <string>
#include "Book.h"

using namespace std;

class EBook: public Book{
public:
  EBook(int sizeCharacters, int charsPerPage);
  ~EBook();
  string getBookSizeRepresentation() override;
private:
  int sizeCharacters;
  int charsPerPage;
};

#endif //EBOOK_H