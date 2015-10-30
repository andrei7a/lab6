#include<iostream> 
#include "Set.h"
using namespace std;

void main() {

	
	Set a;
	cout << "Enter A (a b c <Enter>): ";	cin >> a;
	cout << endl;
	Set b;
	cout << "Enter B (a b c <Enter>): "; cin >> b;
	cout << endl;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	Set c = (a + b);
	cout << "A+B: " << c << endl;
	cout << "A<=B: ";
	if (a <= b)
	{
		cout <<"True" << endl;
	}
	else
	{
		cout <<"False" << endl;
	}
	cout << "A[3]: " << a[2] << endl;
	cout<<"Int(A): "<< int(a)<<endl;


}