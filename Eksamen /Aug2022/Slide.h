#pragma once
#include <iostream>
#include <string>
#include <vector>
class Slide
{
private:
    std::string title;
    std::vector <std::string> bulltes;
public:
    Slide(std::string title, std::vector<std::string> bullets);
    virtual std::string getTitle();
    virtual std::vector<std::string> getBullets();
};