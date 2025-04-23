#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(){ spouse = nullptr;} //0...1
// -- ажилчны ерөнхий мэдээлэл --
string Employee::getCompanyID(){return CompanyID;}
string Employee::getTitle(){return Title;}
string Employee::getStartDate(){return Date;}

void Employee::setCompanyID(string c){CompanyID = c;}
void  Employee::setTitle(string t){Title = t;}
void Employee::setStartDate(string s){Date = s;}

//-- Employee-д нэмэгдэж байгаа "Child", "Spouse", "Division" зэрэг объектуудын мэдээллийг ажилтны мэдээлэлд нэмэх хэсэг --

// Division
Division Employee::getDivision(){return division;} 
void Employee::setDivision(Division d){division = d;}

// Job Description
void Employee::addJobDescription(JobDescription jd){
    jobDescriptions.push_back(jd); // jd гэдэг утгыг векторын сүүлд нь нэмнэ.
}
vector<JobDescription> Employee::getJobDescriptions() { return jobDescriptions; } // векторт хадгалагдсан үүргийн жагсаалтыг буцаана.

// Spouse
void Employee::setSpouse(Spouse* s) { spouse = s; }
Spouse* Employee::getSpouse() { return spouse; }

// Children
void Employee::addChild(Child c) { // хүүхэд нэмэгдэх үед "children"-д нэмэгдэнэ. (жагсаалт)
    children.push_back(c);
}

vector<Child> Employee::getChildren() { return children; } // векторт хадгалагдсан хүүхдүүдийн жагсаалтыг буцаана.