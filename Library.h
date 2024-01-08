#include <string>
#include <vector>
#include "Book.h"
#include "Patron.h"
#include "Loan.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "AudioBook.h"

using namespace std;

class Library{
public:
  Library();
  Library(string libraryName);
  ~Library();
  string getName();
  Book* searchBook(string title);
  Patron* searchPatron(string name);
  void addPrintedBook(string title, int numPages);
  void addEBook(string title, int sizeCharacters, int charsPerPage);
  void addAudioBook(string title, int durationSeconds);
  void addPatron(string name, string address, string phoneNumber);
  void checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay);
  void returnBook(Book* aBook, Patron* aPatron);


private:
  string name;
  vector<Loan*> *loans;
  vector<Patron*> *patrons;
  vector<Book*> *books;
};