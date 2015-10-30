#include "Set.h"

Set::Set(int n ...)
{
	int *temp = &n;
	temp++;
	for (int i = 0; i < n; i++)
	{
		mass = (int*)realloc(mass, sizeof(int)*++num);
		mass[num - 1] = *temp;
		temp++;
	}
}



 void  operator +=(Set& temp, int tempNum)
{
	temp.mass = (int*)realloc(temp.mass, sizeof(int)*++temp.num);
	temp.mass[temp.num - 1] = tempNum;
}

 void operator >> (std::istream& input, Set&	temp)
 {
	 int *N = (int*)malloc(0);
	 int n = 0;
	 int tempInt = 0;
	 bool minus = 0;
	 bool space=0;
	 char c;
	 
	do 
	 {
		 c = _getch();
		 _putch(c);
		 if (space == 1 && c == 32);
		 else {
			 if (c == 32 || c == 13)
			 {
				 if (c == 13 && space == 1) break;
				 if (minus) { tempInt *= (-1); minus = 0; }
				 N = (int*)realloc(N, sizeof(int)*++n);
				 N[n - 1] = tempInt;
				 tempInt = 0;
				 if (c == 13)
				 {
					 break;
				 }
				 space = 1;
			 }
			 else if (c == 45)
			 {
				 minus = 1;
				 space = 0;
			 }
			 else
			 {
				 tempInt *= 10;
				 tempInt += c - '0';
				 space = 0;
			 }
		 }
	 }
	 while (1);
	 
	 temp.mass = N;
	 temp.num = n;
 }

 std::ostream& operator << (std::ostream& output, Set& temp)
 {

	 for (int i = 0; i < temp.num; i++)
	 {
		 output << temp.mass[i] << " ";
	 }
	 return output;
 }

  Set  operator + (Set& x, Set& y) {
	 Set temp(x);
	 bool flag = 0;
	 for (int i = 0; i < y.num; i++)
	 {
		 for (int j = 0; j < x.num; j++)
		 {
			 if (y.mass[i] == x.mass[j])
			 {
				 flag = 1;
			 }
		 }
		 if (flag == 0)
		 {
			 temp += y.mass[i];
		 }
		 else
		 {
			 flag = 0;
		 }
	 }
	 return temp;
 }

 bool  operator <= (Set& x, Set& y) {
	  bool flag = 0;
	  bool globalFlag = 1;
	  for (int i = 0; i < y.num; i++)
	  {
		  for (int j = 0; j < x.num; j++)
		  {
			  if (y.mass[i] == x.mass[j])
			  {
				  flag = 1;
			  }
		  }
		  if (flag == 0) { globalFlag = 0; }
		  else { flag = 0; }
	  }

	  for (int i = 0; i < x.num; i++)
	  {
		  for (int j = 0; j < y.num; j++)
		  {
			  if (x.mass[i] == y.mass[j])
			  {
				  flag = 1;
			  }
		  }
		  if (flag == 0) { globalFlag = 0; }
		  else { flag = 0; }
	  }

	  return globalFlag;
  }


 int & Set::operator[](int i)
 {
	 return this->mass[i];
 }

 Set::operator int()
 {
	 return this->num;
 }

