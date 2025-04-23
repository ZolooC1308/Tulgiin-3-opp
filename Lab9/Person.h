#pragma once
#include <string>
using namespace std;

class Person {
   protected:
      string Name;
      string SSNum;
      int Age;
   public:
      string getName();
      string getSSNum();
      int getAge();
      void setName(string n);
      void setSSNum(string ssnum);
      void setAge(int age);
};