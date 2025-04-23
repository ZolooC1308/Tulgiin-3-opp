#include "Person.h"
#include <string>
using namespace std;

string Person::getName() {return Name;}
string Person::getSSNum() {return SSNum;}
int Person::getAge() {return Age;}
void Person::setName(string n) {Name = n;}
void Person::setSSNum(string s) {SSNum = s;}
void Person::setAge(int a) {Age = a;}