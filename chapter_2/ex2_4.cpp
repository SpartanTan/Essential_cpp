#include <iostream>
#include <vector>
#include <string>

using namespace std;


extern bool pentagonal_elem( int pos, int &elem );
extern const vector<int>* pentagonal_series( int pos );//返回指向vector的指针

inline bool check_validity( int pos )
{
	return ( pos <= 0 || pos > 64 ) ? false : true;
}

void ex2_4()
{
	int elem;
	if( pentagonal_elem( 8, elem ))
	  cout << "element 10 is " << elem << '\n' << endl;
}

int main()
{
	ex2_4();

	return 0;
}

const vector<int>* pentagonal_series( int pos )//返回指向vector的指针
{
	static vector<int> _elems;//存储整个计算的pentagonal数组
	if( check_validity( pos ) && ( pos > _elems.size() ))
	{
		for( int ix = _elems.size()+1; ix <= pos; ++ix )
		{
			_elems.push_back( (ix*(3*ix-1)/2) );
		}
	}
	return &_elems;//通过指针的方式传出去
}

bool pentagonal_elem( int pos, int &elem )
{
	if( !check_validity( pos ))
	{
		cout << "sorry. Invalid position: " << endl;
		elem = 0;
		return false;
	}
	const vector<int> *pent = pentagonal_series( pos );//令pent这个指针指向_elems这个数组
	elem = (*pent)[pos-1];
	return true;
}







