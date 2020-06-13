#include<iostream>
using namespace std;

//前置z声明(forward declaration)
//让编译器知道这个函数的存在
bool fibon_elem( int , int & );

int main()
{
	int pos;
	cout << "Please enter a position: ";
	cin >> pos;

	int elem;
	if( fibon_elem( pos,elem ))
		cout << "element # " << pos
			 << " is " << elem << endl;
	else
		cout << "Sorry. Could not calculate element # "
			 << pos << endl;
}

bool fibon_elem( int pos, int &elem)
{
	//检查位置值是否合理
	if( pos <= 0 || pos > 1024 )
	{
		elem = 0;
		return false;
	}
	elem = 1;
	int n_2 = 1, n_1 = 1;
	
	for( int ix = 3;ix <= pos; ++ix )
	{
		elem = n_2 + n_1;
		n_1 = n_2;
		n_2 = elem;
		//cout << n_1
		//	 << n_2 << endl;
	}
	return true;
}




