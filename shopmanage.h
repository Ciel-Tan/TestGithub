#ifndef SHOPMANAGE_H
#define SHOPMANAGE_H
#include <bits/stdc++.h>
#include <string>
#include "Cat.h"
#include "Dog.h"

using std::string;

class QLCAT
{
private:
    Cat *A;
    int n;

public:
    QLCAT(int = 100);

    ~QLCAT();

    int Getn();

    void Setn(int);

    int getsl_atpos(int);

    void setsl_atpos(int, int);

    void showforcat();

    string getname_atpos(int);

    void init();

    void addcat(int, Cat *);

    void findcat(string);

    long long getPrice_atpos(int);

    void delete_atpos(string);

    void Update(string);

    int SumPrice();

    void MenuForCat();

    void getf();

    void writef();

    void show_forcat_Customer();
};

class QLDOG
{
private:
    Dog *B;
    int n;

public:
    QLDOG(int = 100);

    ~QLDOG();

    int Getn();

    void Setn(int);

    int getsl_atpos(int);

    void setsl_atpos(int, int);

    void showfordog();

    void showatpos(int);

    void init();

    void add_dog(int, Dog *);

    void find_dog(string);

    string getname_atpos(int);

    void delete_atpos(string);

    long long getPrice_atpos(int);

    void Update(string);

    long long SumPrice();

    void MenuFordog();

    void getf();

    void writef();

    void show_fordog_Customer();
};

#endif
