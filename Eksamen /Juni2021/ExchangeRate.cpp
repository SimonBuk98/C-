#include "ExchangeRate.h"

ExchangeRate::ExchangeRate(std::string _valuta, double _kurs){
    valuta= _valuta;
    kurs= _kurs;
}

void ExchangeRate::setExchangeRate(double _kurs){
    kurs=_kurs;
}

double ExchangeRate::getKurs(){
    return kurs;
}