#include "Child.h"
#include <string>
using namespace std;

string Child::getFavoriteToy(){
    return FavoriteToy;
}
void Child::setFavoriteToy(string toy){
    FavoriteToy = toy;
}