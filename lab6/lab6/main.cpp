#include<iostream> 
using namespace std;
class  Set {

public:
	int *mass = (int*)malloc(0); int num = 0;

	Set() {}

	Set(int n ...)
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
	friend void operator +=(Set& temp, int tempNum)
	{
		temp.mass = (int*)realloc(temp.mass, sizeof(int)*++temp.num);
		temp.mass[temp.num - 1] = tempNum;
	}

	friend void operator >> (istream& input, Set&	temp)
	{
		int *N = (int*)malloc(0);
		int n = 0;
		int tempInt = 0;
		input >> tempInt;
		do {
			N = (int*)realloc(N, sizeof(int)*++n);
			N[n - 1] = tempInt;
			input >> tempInt;
		} while (tempInt != -1);
		temp.mass = N;
		temp.num = n;
	}

	friend ostream& operator << (ostream& output, Set& temp)
	{

		for (int i = 0; i < temp.num; i++)
		{
			output << temp.mass[i] << " ";
		}
		return output;
	}

	friend  Set  operator + (Set& x, Set& y) {
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


	friend  bool  operator <= (Set& x, Set& y) {
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
	int &operator[] (int i) {
		return this->mass[i];
	}

	operator int()
	{
		return this->num;
	}
};
void main() {

	
	Set a;
	cin >> a;
	Set b;
	cin >> b;
	cout << endl;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	Set c = (a + b);
	cout << "A+B: " << (a + b) << endl;
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