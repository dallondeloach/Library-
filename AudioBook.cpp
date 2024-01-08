#include "AudioBook.h"

AudioBook::AudioBook(int aDurationSeconds){
  durationSeconds=aDurationSeconds;
}

AudioBook::~AudioBook(){}

//Returns string of size of book
string AudioBook::getBookSizeRepresentation(){
  int minutes = durationSeconds/60;
  string minute;
  int seconds= durationSeconds%60;
  string second;
  if(minutes<10){
    minute= "0"+to_string(minutes);
  }
  else{
    minute=to_string(minutes);
  }

  if(seconds<10){
    second="0"+to_string(seconds);
  }
  else{
    second=to_string(seconds);
  }

  return "has a duration of "+minute+":"+second+".";
   
}
  
