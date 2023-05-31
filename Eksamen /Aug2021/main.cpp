#include <iostream>
#include <string>
#include "Person.h"
#include "SocialSecurit.h"
#include "DigitalSS.h"
#include "GuestList.h"
void test(bool comparison, std::string description)
{
    std::string output = comparison ? "success" : "failure";
    std::cout << output << "-" << description << std::endl;
}
int main()
{
    // Createpeople
    Person father("Frederic", "Lilleputvej17");
    Person mother("Martha", "Lilleputvej17");
    Person grandMother("IngridKatrine", "Slottet1");
    Person distantRelative("Svend", "Udstrup42");
    Person circusClown("Bingo", "Cirkus123");
    Person stranger("BruceWayne", "Hulen3");
    // Createphysicalanddigitalid's
    SocialSecurit distantRelativeSS(distantRelative);
    SocialSecurit circusClownSS(circusClown);
    SocialSecurit strangerSS(stranger);
    DigitalSS motherDSS(mother);
    DigitalSS distantRelativeDSS(distantRelative);
    // TestcompareTomethods
    test(distantRelativeSS.compareTo(distantRelative) == true, "PhysicalIDstillvalid");
    test(distantRelativeDSS.compareTo(distantRelative) == true, "DigitalID");
    distantRelative.changeAddress("Forresthill9");
    test(distantRelativeSS.compareTo(distantRelative) == false, "PhysicalIDoutdated");
    test(distantRelativeDSS.compareTo(distantRelative) == true, "DigitalIDalwaysuptodate");
    std::cout << std::endl;
    // Createguestlist
    GuestList guestList;
    guestList.addVIP(father);
    guestList.addVIP(mother);
    guestList.addVIP(grandMother);
    guestList.addGuest(distantRelative);
    guestList.addGuest(circusClown);
    // TestisAllowedEntry
    test(guestList.isAllowedEntry(father) == true, "FathertriestoenterasVIP");
    test(guestList.isAllowedEntry(grandMother) == true, "GrandmothertriestoenterasVIP");
    test(guestList.isAllowedEntry(stranger) == false, "StrangertriestoenterasVIP");
    test(guestList.isAllowedEntry(motherDSS) == true, "Entryusingmother'sdigitalID");
    test(guestList.isAllowedEntry(distantRelativeDSS) == true, "Entryusingrelative'sdigitalID");
    test(guestList.isAllowedEntry(circusClownSS) == true, "Entryusingclown'sphysicalID");
    test(guestList.isAllowedEntry(strangerSS) == false, "Entryusingstranger'sphysicalID");
    test(guestList.isAllowedEntry(distantRelativeSS) == false, "Entryusingrelative'soutdatedphysicalID");
    return 0;
}