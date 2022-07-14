#include<string>
#include<iostream>
#include "smrtPtr.h"


struct A 
{
	int x; 
	A():x(0) {}

	
};

int main() 
{
	SmartPointer<A> SmrtPtr(new A()); 
	A b; 
	std::cout << SmrtPtr->x; 
	SmrtPtr->x = 69; 
	std::cout << SmrtPtr->x; 
	return 0;
}