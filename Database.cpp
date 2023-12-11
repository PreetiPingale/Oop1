//A2_OOP_database_student.cpp
/*Develop a program in C++ to create a database of student’s information
system containing the following information: Name, Roll number, Class,
Division, Date of Birth, Blood group, contact address, Telephone number,
Driving license no. and other. Construct the database with suitable member
functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and
dynamic memory allocation operators- new and delete . 
*/
#include<iostream>
#include<string>    // header file declares a set of functions to work strings.
using namespace std;

class db {
		int roll;
		string name,Class,Div,dob,bg,city ,phone,license;

	public:
		static int stdno;      // declaration of static variable
		static void count() {  // defination of static function // calling:-  classname::fun() 
			cout<<"\n No.of objects created: "<<stdno;    //
		}

		db() {      // default constructor
			roll=0;
			name,Class,Div,dob,bg,city,phone,license="";
			++stdno;
		}
		
		void getdata() { // defining member function
			cout<<"\n\nEnter:name,roll,Class,Div,Dob,bg,city,phone,license \n\n";
			cin>>name>>roll>>Class>>Div>>dob>>bg>>city>>phone>>license;
		}
		
		friend void display(db d);   // declaration of friend function

		~db() { // destructor
			cout<<"\n\n"<<this->name<<"(Object) is destroyed!\n";
		}
};
int db::stdno; // datatypeofVar classname::var      Define static data member stdno outside the class;

void display(db d) { // defination of friend function // calling:   fun() 
	cout<<"\n Name:"<<d.name;
	cout<<"\n Roll_No:"<<d.roll;
	cout<<"\n Class:"<<d.Class;
	cout<<"\n Div:"<<d.Div;
	cout<<"\n DOB:"<<d.dob;
	cout<<"\n Blood group:"<<d.bg;
	cout<<"\n City:"<<d.city;
	cout<<"\n Phone_No:"<<d.phone;
	cout<<" \n Liacense_No:"<<d.license;
}


int main() {
	int n,i;
	db *ptr[5]; //array of object db obj1 ........obj1.getdata() 

	cout<<"\nHow many objects u want to create?:";
	cin>>n;
	for(i=0; i<n; i++) {
		ptr[i]=new db(); //new operator use to dynamic memory(run time) allocation
		ptr[i]->getdata(); //ptr->getdata() 
	}
//	cout<<"\n"<<"name"<<"roll"<<"Class"<<"Div"<<"dob"<<"bg"<<"contact"<<"phone"<<"license";
	for(i=0; i<n; i++)
		display(*ptr[i]);
		
	db::count();  // calling of static function

	for(i=0; i<n; i++) {
		delete(ptr[i]); //delete operator use to deallocation of memory
	}
//	cout<<"\nObjects deleted!" ;
}
