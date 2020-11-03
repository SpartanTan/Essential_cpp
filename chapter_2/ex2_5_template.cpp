nt elem_vals[]={1,2,3,4…};
vector<int> elem_seq(elem_vals,elem_vals+seq_size);//两个传入的参数都是地址#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

templete<typename Type>
inline Type max( Type t1, Type,t2)
{
	return t1>t2?t1:t2;
}

templete<typename elemType>
inline elemType max( const vector<elemType> &vec )
{
	return *max_element( vec.begin(), vec.end() );
}


templete<typename arrayType>
inline arrayType max( const arrayType *parray, int size )
{
	return *max_element( parray, parray+size );
}


int main()
{
	//f) 字符串vector
	string sarray[]={"we", "were", "her", "pride", "of", "ten"};
	vector<string> svec( sarray,sarray+6);//用sarry的值初始化svec

	//d) 整数vector
	int iarray[]={ 12, 70, 2, 169, 1, 5, 29 };
	vector<int> ivec( iarray, iarray+7 );

	//e) 浮点数vector
	float farray[]={2.5, 24.8, 18.7, 4.1, 23.9, };
	vector<float> fvec( farray, farray+5 );

	int imax = max( max(ivec), max( iarray,7 ) );
	
	float fmax = max( max(fvec), max( farray, 5) );
	
	string smax = max( max(svec),max(sarray, 6) );
	
	cout << "imax should be 169 -- found: " << imax << "\n"
		 << "fmax shoulde be 24.8 -- found: " << fmax << "\n"
		 << " smax should be were -- found: " << smax << "\n";


	return 0;
}
