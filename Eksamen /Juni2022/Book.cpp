#include "Book.h"


Book::Book(std::string _author, std::string _title): author(_author), title(_title){}

std::string Book::getInfo(){
    return author + ": " + title; 
}

