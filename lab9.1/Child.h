#pragma once
#include "Person.h"
#include <string>

class Child: public Person {
    protected:
        string FavoriteToy;
    public:
        string getFavoriteToy();
        void setFavoriteToy(string ftoy);
};