#pragma once
#include "Person.h"
#include <string>

class JobDescription : public Person {
    protected:
        string Description;
    public:
        string getDescription();
        void setDescription( string d);    
};