#pragma once
#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
#include <string>
#include <vector>
using namespace std;

class Employee : public Person {
    private:
        string CompanyID;
        string Title;
        string Date;

        Division division;
        vector<JobDescription> jobDescriptions; // нэг ажилтан олон үүрэгтэй байж болно. (жагсаалтын нэр)
        Spouse* spouse;
        vector<Child> children; // хүүхэд нэмэгдэх үед "children"-д нэмэгдэнэ. (жагсаалтын нэр)
        
    public:
    Employee(); // spouse pointer = nullptr
        string getCompanyID();
        string getTitle();
        string getStartDate();
        void setCompanyID(string c);
        void setTitle(string t);
        void setStartDate(string a);   
        
        //-- Employee-д нэмэгдэж байгаа "Child", "Spouse", "Division" зэрэг объектуудын мэдээллийг ажилтны мэдээлэлд нэмэх хэсэг --
        void setDivision(Division d); // Division-д үүссэн объектын утгыг "e"-ажилтанд хадгална.
        Division getDivision();

        void addJobDescription(JobDescription jd); // жагсаалтад нэмэгдүүлэх. Нэг ажилтанд хэд хэдэн үүрэгтэй байх боломжтой.
        vector<JobDescription> getJobDescriptions(); //Жагсаалт хадгалж байна.
        
        void setSpouse(Spouse* s); 
        Spouse* getSpouse();
        
        void addChild(Child c); // хүүхэд ажилчны мэдээлэлд нэмэгдэнэ.
        vector<Child> getChildren(); // Тухайн ажилтаны хүүхдийн жагсаалт.
};