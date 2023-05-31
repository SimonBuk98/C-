#include "Library.h"
#include "Work.h"
#include "Book.h"
#include "CD.h"



int main()
{
    CD c1("John Lemon", "Hey Dude", 1968);
    CD c2("Lion Maiden", "The slumber of the beast", 1982);
    Book b1("Hank Frerbert", "A lot of sand");
    Book b2("Fen Kollet", "Caterpillars of the earth");
    Library library;
    library.add(&c1);
    library.add(&c2);
    library.add(&b1);
    library.add(&b2);
    c1.borrow();
    b2.borrow();
    library.searchLibrary("sand");
    std::cout << std::endl;
    library.searchLibrary("of");
    std::cout << std::endl;
    library.searchLibrary("Lemon");
    std::cout << std::endl;
    return 0;
}