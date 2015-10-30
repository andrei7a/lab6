#pragma once
#include<iostream> 
#include <conio.h>
class  Set {

public:
	int *mass = (int*)malloc(0); int num = 0;

	Set() {}
	
	Set(int n ...);
	
	friend void operator +=(Set& , int );

	friend void operator >> (std::istream&, Set&);

	friend std::ostream& operator << (std::ostream&, Set&);

	friend  Set  operator + (Set&, Set&);

	friend  bool  operator <= (Set& , Set& );

	int &operator[] (int );

	operator int();
};