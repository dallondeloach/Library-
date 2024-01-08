#include "EBook.h"

EBook::EBook(int aSizeCharacters, int aCharsPerPage){
  sizeCharacters=aSizeCharacters;
  charsPerPage=aCharsPerPage;
}

EBook::~EBook(){}

//Returns string of size of book
string EBook::getBookSizeRepresentation(){
  int pages;
  if((sizeCharacters/charsPerPage)%2==0){
    pages=(sizeCharacters/charsPerPage);
  }
  else{
    pages = (((sizeCharacters/charsPerPage)+1)/1);
  }

  return "has "+to_string(pages)+" digital pages.";
}