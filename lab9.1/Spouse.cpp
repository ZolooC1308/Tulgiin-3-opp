#include "Spouse.h"
#include <string>
using namespace std;

string Spouse::getAnniversaryDate() {
    return AnniversaryDate;
}
void Spouse::setAnniversaryDate(string date) {
    AnniversaryDate = date;
}