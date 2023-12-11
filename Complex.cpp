/*Implement a class Complex which represents the Complex Number data
type. Implement the following 1. Constructor (including a default constructor
which creates the complex number 0+0i). 2. Overload operator+ to add two
complex numbers. 3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers. 
*/
#include<iostream>
using namespace std;

class complex
{
	private:
		 float img,real;//data member 
	public:
		
		complex()
		{
			real=0;
			img=0;
		}
		//member function
		complex operator+(complex &);//return_type operator opr() 
		
		complex operator*(complex &);
		//parameterized constructor
		complex(float real,float img)
		{
				this->real=real;
				this->img=img;
			
		}
		
		friend istream &operator>>(istream &,complex &);//friend return_type functionName() 
		friend ostream &operator<<(ostream &,complex &);
};


istream &operator>>(istream &din,complex &c)
{
	cout<<"Enter real part of complex num 2: ";
	din>>c.real;
	cout<<"Enter img part of complex num 2: ";
	din>>c.img;
	return din;
}

ostream &operator<<(ostream &dout,complex &c)
{
	dout<<c.real<<" + "<<c.img<<"i";
	dout<<endl;
	return dout;
}

//member fun:  return_type classname :: functionNAme(arg1...)
complex complex::operator+(complex &c)
{
	complex temp;
	temp.real=real+c.real;    
	temp.img=img+c.img;
	return temp;
}

complex complex::operator*(complex &c)
{
	complex temp;
	temp.real=(real*c.real)-(img*c.img);
	temp.img=(real*c.img)+(img*c.real);
	return temp;
}

int main()
{
	complex c1(1.2,3.4),c2,c3,c4;
	cout<<"Complex num 1: "<<c1;
	cout<<"Enter complex number 2: ";
	cin>>c2;
	
	c3=c1+c2;  //
	cout<<"After addition of 2 complex num: ";
	cout<<c3;
	
	c4=c1*c2;
	cout<<"Multi of 2 cmplx num : "<<c4;
	
	return 0;
}
