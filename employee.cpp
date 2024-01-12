#include<bits/stdc++.h>
using namespace std;

class Employee {
public:
 string name;
vector<Employee*> directReports;
vector<string> report_name;

  
Employee(string name) {
    this->name=name;
}

   
    void addDirectReport(Employee* directReport) {
        directReports.push_back(directReport);
    }
    void add_reports_name(string s){
       report_name.push_back(s);

    }
    void print_reports_name_with_info(){

    for(int i=0;i<report_name.size();i++){
        cout<<report_name[i]<<endl;
    }
  
}
};

void printOrgChart(Employee* employee, int depth = 0) {
    if (employee == nullptr) {
        return;
    }

   
    for (int i = 0; i < depth; ++i) {
       cout << "  ";
    }

    
  cout << employee->name << endl;
  cout<<"Report Information for"<<employee->name<<endl;

   employee->print_reports_name_with_info();
    for (Employee* directReport : employee->directReports) {
        printOrgChart(directReport, depth + 1);
    }
 
}

int main() {
   
    Employee* CEO = new Employee("CEO");

    Employee* manager1 = new Employee("Manager 1");
    Employee* manager2 = new Employee("Manager 2");

    Employee* employee1 = new Employee("Employee 1");
    Employee* employee2 = new Employee("Employee 2");
    Employee* employee3 = new Employee("Employee 3");
    Employee* employee4 = new Employee("Employee 4");
   
    CEO->addDirectReport(manager1);
    CEO->addDirectReport(manager2);

    manager1->addDirectReport(employee1);
    manager1->addDirectReport(employee2);
    manager2->addDirectReport(employee3);
    manager2->addDirectReport(employee4);
    manager1->add_reports_name("Accounts");
    manager1->add_reports_name("Treasury");
    manager2->add_reports_name("operations and recruitment");
    manager2->add_reports_name("Staff Development");
    
  
    employee1->add_reports_name("customer service");
    employee1->add_reports_name("Domestic Sales");
    employee1->add_reports_name("Department");
    employee2->add_reports_name("Purchasing");
    employee2->add_reports_name("Recieving and inspection");
    employee3->add_reports_name("fabrication");
    employee3->add_reports_name("Assembly");
    employee3->add_reports_name("Testing");
    employee3->add_reports_name("Production Engineering");
    employee4->add_reports_name("System Engineering");
    employee4->add_reports_name("Electronic  Engineering");
    employee4->add_reports_name("Software Engineering");
    employee4->add_reports_name("Mechanical Engineering");
    employee4->add_reports_name("Technical Engineering");

    cout << "Organization Chart:" << std::endl;
    printOrgChart(CEO);
  string s;
   cout<<"enter the name of the employee you want to report"<<endl;
getline(cin,s);
cout<<"the name of the employee is:"<<s<<endl;
if(s==employee1->name){
    if(employee1){
          cout<<CEO->name<<" "<< manager1->name<<" "<<manager2->name<<endl;
    }
employee1->print_reports_name_with_info();
}
else if(s==employee2->name){
      if(employee2){
           cout<<CEO->name<<" "<< manager1->name<<" "<<manager2->name<<endl;
       
    }
employee2->print_reports_name_with_info();
}
else if(s==employee3->name){
     if(employee3){
        cout<<CEO->name<<" "<< manager1->name<<" "<<manager2->name<<endl;
    }
employee1->print_reports_name_with_info();
}
else if(s==employee4->name)
{
     if(employee4){
        cout<<manager1->name<<" "<<manager2->name<<endl;
    }
employee1->print_reports_name_with_info();
}
else if(s==manager1->name){
    if(manager1){
        cout<<CEO->name<<endl;
    }
    manager1->print_reports_name_with_info();
}
else if(s==manager2->name){
    if(manager2){
        cout<<CEO->name<<endl;
    }
    manager2->print_reports_name_with_info();
}
else{
    cout<<"invalid employee name"<<endl;
}
   
   

    return 0;
}
