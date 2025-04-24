#pragma once
#include "Person.h"
#include <string>

class Spouse : public Person {
    private:
        string AnniversaryDate;
    public:
        string getAnniversaryDate();
        void setAnniversaryDate(string d); 
};