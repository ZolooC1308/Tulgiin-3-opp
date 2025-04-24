#include <iostream>
#include <vector>
#include "Employee.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"

using namespace std;

int main() {
    // 1. Division объектууд үүсгэх
    Division d1, d2; // Division class-д объект үүсгэх
    d1.setDivisionName("Development");
    d2.setDivisionName("Manager");

    // 2. JobDescription объектууд үүсгэх
    JobDescription jd1, jd2, jd3; // JobDescription class-д объект үүсгэх
    jd1.setDescription("Design software architecture");
    jd2.setDescription("Develop core modules");
    jd3.setDescription("Test and debug code");

    // 3. Employee 1
    Employee e1;
    e1.setName("Bishrelt");
    e1.setSSNum("976 99999999");
    e1.setAge(24);
    e1.setCompanyID("num5790");
    e1.setTitle("Software Engineer");
    e1.setStartDate("2022-01-10");
    e1.setDivision(d1);
    e1.addJobDescription(jd1);
    e1.addJobDescription(jd2);

    // Spouse e1
    Spouse* s1 = new Spouse();
    s1->setName("Dulguun");
    s1->setAge(25);
    s1->setAnniversaryDate("2020-09-20");
    e1.setSpouse(s1); 

    // Child 1
    Child c1;
    c1.setName("Erdene");
    c1.setAge(5);
    c1.setFavoriteToy("Lego");
    e1.addChild(c1);

    // Child 2
    Child c2;
    c2.setName("Urin");
    c2.setAge(1);
    c2.setFavoriteToy("Chiwing toy");
    e1.addChild(c2);

    // ------- 4. Employee 2 -------
    Employee e2;
    e2.setName("Odhvv");
    e2.setSSNum("976 88888888");
    e2.setAge(40);
    e2.setCompanyID("num0012");
    e2.setTitle("QA Manager");
    e2.setStartDate("2012-04-27");
    e2.setDivision(d2);
    e2.addJobDescription(jd3);

    // No spouse for e2
    // No children for e2

    // ------------------ Харуулах ------------------
    vector<Employee> employees = {e1, e2}; // Үүсэгсэн ажилчдын жагсаалт

    for (int i = 0; i < employees.size(); i++) {
        Employee emp = employees[i];      // Шинэ obj үүсгэж жагсаалтын i-р элементтэй ажиллана.
        
        cout << "------ Employee #" << (i + 1) << " ------\n";
        cout << "Name: " << emp.getName() << endl;
        cout << "SSN: " << emp.getSSNum() << endl;
        cout << "Age: " << emp.getAge() << endl;
        cout << "Company ID: " << emp.getCompanyID() << endl;
        cout << "Title: " << emp.getTitle() << endl;
        cout << "Start Date: " << emp.getStartDate() << endl;
        cout << "Division: " << emp.getDivision().getDivisionName() << endl;

        // Job Descriptions - Үүрэг олон байж болох тул давталт ашиглав.
        vector<JobDescription> jobs = emp.getJobDescriptions();
        cout << "Job Descriptions:\n";
        for (int j = 0; j < jobs.size(); j++) {
            cout << "  - " << jobs[j].getDescription() << endl;
        }

        // Spouse info - Хүнтэй суусан эсхийг шалгах
        if (emp.getSpouse() != nullptr) {  // Гэрэлсэн эсхийг шалгах.
            Spouse* sp = emp.getSpouse();  // Гэрлсэн бол мэдээлэлийг нь татах.
            cout << "Spouse: " << sp->getName() << " (Age: " << sp->getAge() << ")" << endl;
            cout << "Anniversary: " << sp->getAnniversaryDate() << endl;
        } else {
            cout << "Spouse: None" << endl;
        }

        // Children
        vector<Child> kids = emp.getChildren(); // "kids" гэдэг жагсаалтад хүүхдүүдийн мэдээллийг хадгална.
        if (kids.size() == 0) {    // Хүүхэдтэй эсхийг шалгах
            cout << "Children: None" << endl;
        } else {
            cout << "Children:\n";
            for (int k = 0; k < kids.size(); k++) {
                cout << "  - " << kids[k].getName()
                     << " (Age: " << kids[k].getAge()
                     << ", Favorite Toy: " << kids[k].getFavoriteToy()
                     << ")" << endl;
            }
        }

        cout << endl;
    }

    // Memory cleanup
    delete s1;

    return 0;
}
