#ifndef QUOKKA_H
#define QUOKKA_H

#include <iostream>

class Quokka_Immortal
{
    public:
        Quokka_Immortal();
        Quokka_Immortal(std::string name);
        ~Quokka_Immortal();

    private:
        std::string _name;
};

#endif