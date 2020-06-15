#include<iostream>
using namespace std;

//前置声明(forward declaration)
//让编译器知道这个函数的存在
bool fibon_elem( int , int & );
bool print_sequence( int );

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
	print_sequence( pos );
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
		n_2 = elem;//这二者的赋值顺序不能搞错
		//cout << n_1
		//	 << n_2 << endl;
	}
	return true;
}

bool print_sequence( int pos )
{
	if( pos <= 0 || pos > 1024 )
	{
		cerr << "invalid position: " << pos
			 << " -- cannot handle request!\n";
		return false;
	}
	cout << "The Fibonacci Sequence for "
		 << pos << " positions: \n\t";

	//所有位置都会打印出1 1，只有pos == 1除外
	switch( pos )
	{
		default:
		case 2:
			cout << "1 ";
			//注意，此处没有break
		case 1:
			cout << "1 ";
			break;
	}

	int elem;
	int n_1 = 1, n_2 = 1;
	for( int ix = 3; ix <= pos; ++ix )
	{
		elem = n_1 + n_2;
		n_1 = n_2;
		n_2 = elem;
		//一行打印10个元素
		cout << elem << ( !( ix % 10 ) ? "\n\t" : " " );
	}
	cout << endl;

	return true;
}

