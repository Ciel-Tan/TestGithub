#ifndef FINANCE_H
#define FINANCE_H

class turnover{
    private:
        int month;
        int year;
        long long bill;
    public:

        turnover();
        ~turnover();
        
        int getmonth();
        int getyear();
        long long getbill();

        void setmonth(const int&);
        void setyear(const int&);
        void setbill(const long long&);

        void init(int, int, long long);
};

#endif