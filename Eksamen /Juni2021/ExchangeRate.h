#pragma once
#include <iostream>
#include <string>

class ExchangeRate
{
private:
    std::string valuta;
    double kurs;
public:
    ExchangeRate(std::string valute, double kurs);
    void setExchangeRate(double kurs);
    double getKurs();

};
