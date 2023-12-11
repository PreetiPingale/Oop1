/*Write a C++ program that creates an output file, writes information to it,
closes the file, open it again as an input file and read the information from
the file. */
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee
{
    string Name;
    int ID;
    double salary; 
    public:
        void accept()
        {
            cin>>Name;
            cin>>ID;
            cin>>salary;
        }
        void display()
        {
            cout<<"\n Name:"<<Name;
            cout<<"\n Id:"<<ID;
            cout<<"\n Salary:"<<salary;
        }
};
       
int main()
{
    Employee o[5];
    fstream f;
    int i,n;
   
    f.open("A.txt");
    cout<<"\n How many employee information do you need to store?";
    cin>>n;
    cout<<"\n Enter information of employee in this format(NAME/ID/SALARY)";
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter information of:"<<i<<"\n Employee";
        o[i].accept();
        f.write((char*)&o[i],sizeof o[i]);
    }
   
    f.close();
   
    f.open("A.txt",ios::in);
    cout<<"\n Information of Employees is as follows:";
    for(i=0;i<n;i++)
    {
        f.read((char*)&o[i],sizeof o[i]);
        o[i].display();
    }
    f.close();
   
    return 0;
}
