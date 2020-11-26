#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;


template <typename IteratorType, typename elemType>
IteratorType
find_ver6( IteratorType first, IteratorType last, const elemType &value )
{
	for( ; first!=last; ++first )
	  if( value == *first )
		return first;
	return last;
}

int main()
{
	const int asize = 8;
	int ia[asize] = {1,1,2,3,5,8,13,21};
	
	vector<int> ivec( ia, ia+asize );//初始化vector
	list<int> ilist( ia, ia+asize );//初始化list

	int *pia = find_ver6(ia, ia+asize, 5 );
	if( pia != ia+asize )
	  cerr << "array " << "\n";

	vector<int>::iterator it;
	it = find( ivec.begin(), ivec.end(), 5 );
	if( it != ivec.end() )
	  cerr << "vector " << "\n";

	list<int>::iterator iter;
	iter = find( ilist.begin(), ilist.end(), 5 );
	if( iter != ilist.end() )
	  cerr << "list " << "\n";	  
}
