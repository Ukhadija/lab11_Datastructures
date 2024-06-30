#pragma once
#include <iostream>
using namespace std;
///////////////Question 2//////////////////////
class Professor
{
public:
	string profName;
	string Specialzation;
	string Degree;

	Professor(string name="\0", string specialization="\0", string degr="\0")
	{
		profName = name;
		Specialzation = specialization;
		Degree = degr;
	}

};

istream& operator>> (istream& in, Professor& p)
{
	cout << "Enter Professor Name : ";
	in >> p.profName;
	cout << "Enter Specialzation : ";
	in >> p.Specialzation;
	cout << "Enter Degree : ";
	in >> p.Degree;
	return in;

}
ostream& operator<< (ostream& out, Professor& p)
{
	out << "Professor Name : " << p.profName;
	out << "Specialzation : " << p.Specialzation;
	out << "Degree Name : " << p.Degree;
	return out;
}
class Laboratory
{
private:
	int labID;
	int experimentNo;
public:
	Laboratory(int a=0, int b=0)
	{
		labID = a;
		experimentNo = b;
	}
};

class Department
{
public:
	int deptID;
	string deptName;
	//int labs;
	 Laboratory Laboratories[10];
	 Professor professors[10];
	Department(Professor profs[], Laboratory labs[],int num, string name, int ID)
	{
		deptID = ID;
		deptName = name;
		for (int i = 0; i < num; i++)
		{
			professors[i] = profs[i];
		}
		for (int i = 0; i < num; i++)
		{
			Laboratories[i] = labs[i];
		}
		
	}
	Professor operator [](int& Index)
	{
		return professors[Index];
	}
};
class University
{

	string universityName;
	string location;
	Department depts[3];

	Department operator [](int& Index)
	{
		return depts[Index];
	}
};