#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <string>
#include "Book.h"

using namespace std;

class AudioBook: public Book{
public:
  AudioBook(int aDurationSeconds);
  ~AudioBook();
  string getBookSizeRepresentation() override;
private:
  int durationSeconds;
};

#endif //AUDIOBOOK_H