// #ifndef _Dog
// #define _Dog
#include <string>
#include "Pet.h"
#include <fstream>
using std::ifstream;
using std::string;
class Dog : public Pet
{
public:
    Dog();

    ~Dog();

    void Input();

    void Output();

    long long Price();

    void init1(string, string, float, float, float, string, float, int);

    Dog *operator=(Dog *);
};
// #endif
