#include "PrintedBook.h"

PrintedBook::PrintedBook(int aNumPages){
  numPages=aNumPages;
}

PrintedBook::~PrintedBook(){}

//Returns string of size of book
string PrintedBook::getBookSizeRepresentation(){
  return "has "+to_string(numPages)+" pages.";
}