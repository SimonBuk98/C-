#include "Slide.h"
#include "SlideShow.h"
#include "AdcencedSlide.h"



int main()
{ // Title and bullets for first slide
    std::string t1 = "Lad mig se dig";
    std::vector<std::string> b1;
    b1.push_back("trykke frem og tilbage");
    b1.push_back("fra side til side");
    // Title and bullets for second slide
    std::string t2 = "Lad mig se";
    std::vector<std::string> b2;
    b2.push_back("lidt kaffe i din kop");
    b2.push_back("skriv kode, lad vaere at stop"); 
    // Create Slides, add to show1, and print show1    
    Slide s1(t1, b1);    
    Slide s2(t2, b2);    
    SlideShow show1;    
    show1.add(s1);    
    show1.add(s2);    
    show1.printSlideShow();    
    //Create AdvancedSlides, add to show2, and print show2    
    AdcencedSlide as1(t1,b1,"*");    
    AdcencedSlide as2(t2,b2,"-");    
    SlideShow show2;    
    show2.add(as1);    
    show2.add(as2);
    std::cout << " ------------------------------- ";
    std::cout << std::endl
              << std::endl;
    show2.printSlideShow();
    return 0;
}