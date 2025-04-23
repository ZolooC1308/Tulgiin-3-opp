#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------- Base Class ----------------
class Person {  // base class
protected:
    string name;
    string ssNum;
    int age;

public:
    string getName() { return name; }
    string getSSNum() { return ssNum; }
    int getAge() { return age; }

    void setName(string n) { name = n; }
    void setSSNum(string s) { ssNum = s; }
    void setAge(int a) { age = a; }
};

// ---------------- Derived: Spouse ----------------
class Spouse : public Person {  // 0..1 gerelsen hvn baigaa eseh?
private:
    string anniversaryDate;

public:
    string getAnniversaryDate() { return anniversaryDate; }
    void setAnniversaryDate(string d) { anniversaryDate = d; }
};

// ---------------- Derived: Child ----------------
class Child : public Person { // 0..n olon hvvhedtei baij bolno
private:
    string favoriteToy;

public:
    string getFavoriteToy() { return favoriteToy; }
    void setFavoriteToy(string toy) { favoriteToy = toy; }
};

// ---------------- Supporting: Division ----------------
class Division { // 1 zaawal neg baina.
private:
    string divisionName;

public:
    string getDivisionName() { return divisionName; }
    void setDivisionName(string n) { divisionName = n; }
};

// ---------------- Supporting: JobDescription ----------------
class JobDescription {   // 0..n hed ch baij bolno
private:
    string description;

public:
    string getDescription() { return description; }
    void setDescription(string d) { description = d; }
};

// ---------------- Derived: Employee ----------------
class Employee : public Person {
private:
    string companyID;
    string title;
    string startDate;

    Division division;
    vector<JobDescription> jobDescriptions;

    Spouse* spouse; // optional (0..1)
    vector<Child> children; // 0..n

public:
    // Constructor
    Employee() {
        spouse = nullptr;
    }

    string getCompanyID() { return companyID; }
    string getTitle() { return title; }
    string getStartDate() { return startDate; }

    void setCompanyID(string id) { companyID = id; }
    void setTitle(string t) { title = t; }
    void setStartDate(string d) { startDate = d; }

    // Division getter/setter
    Division getDivision() { return division; }
    void setDivision(Division d) { division = d; }

    // JobDescription functions
    void addJobDescription(JobDescription jd) {
        jobDescriptions.push_back(jd);
    }

    vector<JobDescription> getJobDescriptions() { return jobDescriptions; }

    // Gerelsen hvn?
    void setSpouse(Spouse* s) { spouse = s; }
    Spouse* getSpouse() { return spouse; }

    // Heden hvvhedtei?
    void addChild(Child c) {
        children.push_back(c);
    }

    vector<Child> getChildren() { return children; }
};

int main() {
    // ------- 1. Division объектууд үүсгэх -------
    Division d1, d2;
    d1.setDivisionName("Research");
    d2.setDivisionName("Development");

    // ------- 2. JobDescription объектууд үүсгэх -------
    JobDescription jd1, jd2, jd3;
    jd1.setDescription("Design software architecture");
    jd2.setDescription("Develop core modules");
    jd3.setDescription("Test and debug code");

    // ------- 3. Employee 1 -------
    Employee e1;
    e1.setName("Alice");
    e1.setSSNum("123-45-6789");
    e1.setAge(30);
    e1.setCompanyID("E001");
    e1.setTitle("Software Engineer");
    e1.setStartDate("2022-01-10");
    e1.setDivision(d1);
    e1.addJobDescription(jd1);
    e1.addJobDescription(jd2);

    // Spouse for e1
    Spouse* s1 = new Spouse();
    s1->setName("Bob");
    s1->setAge(31);
    s1->setAnniversaryDate("2018-06-15");
    e1.setSpouse(s1);

    // Child class-d yrunhii hvvhdiin medeelel oruulah.
    Child c1;
    c1.setName("Tommy");
    c1.setAge(5);
    c1.setFavoriteToy("Lego");
    // Oruulsan medeellee Employee e1-d oruulna.
    e1.addChild(c1);

    Child c2;
    c2.setName("Urin");
    c2.setAge(1);
    c2.setFavoriteToy("Chiwing toy");
    e1.addChild(c2);

    // ------- 4. Employee 2 -------
    Employee e2;
    e2.setName("John");
    e2.setSSNum("987-65-4321");
    e2.setAge(40);
    e2.setCompanyID("E002");
    e2.setTitle("QA Manager");
    e2.setStartDate("2020-09-20");
    e2.setDivision(d2);
    e2.addJobDescription(jd3);

    // No spouse for e2 (test 0..1)
    // No children for e2 (test 0..n)

    // ------------------ Output ------------------
    vector<Employee> employees = {e1, e2};

    for (int i = 0; i < employees.size(); i++) {
        Employee emp = employees[i];
        cout << "------ Employee #" << (i + 1) << " ------\n";
        cout << "Name: " << emp.getName() << endl;
        cout << "SSN: " << emp.getSSNum() << endl;
        cout << "Age: " << emp.getAge() << endl;
        cout << "Company ID: " << emp.getCompanyID() << endl;
        cout << "Title: " << emp.getTitle() << endl;
        cout << "Start Date: " << emp.getStartDate() << endl;
        cout << "Division: " << emp.getDivision().getDivisionName() << endl;

        // Job Descriptions
        vector<JobDescription> jobs = emp.getJobDescriptions();
        cout << "Job Descriptions:\n";
        for (int j = 0; j < jobs.size(); j++) {
            cout << "  - " << jobs[j].getDescription() << endl;
        }

        // Spouse info
        if (emp.getSpouse() != nullptr) {
            Spouse* sp = emp.getSpouse();
            cout << "Spouse: " << sp->getName() << " (Age: " << sp->getAge() << ")" << endl;
            cout << "Anniversary: " << sp->getAnniversaryDate() << endl;
        } else {
            cout << "Spouse: None" << endl;
        }

        // Children
        vector<Child> kids = emp.getChildren();
        if (kids.size() == 0) {
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

    // -------- Memory cleanup --------
    delete s1;

    return 0;
}
