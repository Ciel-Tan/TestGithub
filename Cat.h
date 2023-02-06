// #ifndef _Cat
// #define _Cat
#include <string>
#include "Pet.h"
#include <fstream>
using std::ifstream;
using std::string;
class Cat : public Pet
{
public:
    Cat();

    ~Cat();

    void Input();

    void Output();

    long long Price();

    void init1(string, string, float, float, float, string, float, int);

    Cat *operator=(Cat *);
};
// #endif