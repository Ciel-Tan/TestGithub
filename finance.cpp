#include "finance.h"
#include <iostream>



turnover::turnover(){}

turnover::~turnover(){}

int turnover::getmonth(){
    return this->month;
}

int turnover::getyear(){
    return this->year;
}

long long turnover::getbill(){
    return this->bill;
}


void turnover::setmonth(const int& thang){
    if (thang <= 0 || thang > 12){
        std::cout << "\nUNKNOWN NUMBER OF THE MONTH!";
    }
    else{
        this->month = thang;
    }
}

void turnover::setyear(const int& nam){
    if (nam < 1950 || nam >= 3000){
        std::cout << "\nUNKNOWN NUMBER OF THE YEAR!";
    }
    else this->year = nam;
}

void turnover::setbill(const long long& bill){
    this->bill = bill;
}

void turnover::init(int thang, int nam, long long doanhso){
    this->month = thang;
    this->year = nam;
    this->bill = doanhso;
}

