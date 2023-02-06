#ifndef _Pet
#define _Pet
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using std::string;

class Pet
{
protected:
    string Key;

    string Binomial_nomenclature;

    float Ageold;

    float Height;

    float Weight;

    string Skincolor;

    float Thoroughbred_index;

    int Nums;

public:
    Pet(string = "", string = "", float = 0, float = 0, float = 0, string = "", float = 0, int = 0);

    ~Pet();

    string getKey();

    void setKey(string);

    string GetBinomial_nomenclature();

    void SetBinomial_nomenclature(string);

    float GetAgeold();

    void SetAgeold(float);

    float GetHeight();

    void SetHeight(float);

    float GetWeight();

    void SetWeight(float);

    string GetSkincolor();

    void SetSkincolor(string);

    float GetThoroughbred_index();

    void SetThoroughbred_index(float);

    int getNums();

    void setNums(int);

    virtual void Input();

    virtual void Output();

    virtual long long Price() = 0;
};
#endif