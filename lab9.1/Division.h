#pragma once
#include "Person.h"
#include <string>

class Division : public Person {
    protected:
        string DivisionName;    
    public:
        string getDivisionName();
        void setDivisionName(string n);
};