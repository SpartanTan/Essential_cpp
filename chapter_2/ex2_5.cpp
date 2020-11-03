#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//a)两个整数
inline int max( int t1, int t2 )
{
	return t1 > t2 ? t1 : t2;
}

//b)两个浮点数
inline float max( float t1, float t2 )
{
	return t1 > t2 ? t1 : t2;
}

//c)两个字符串
inline string max( const string &t1, string &t2 )
{
	return t1 > t2 ? t1 : t2;
}

//d)整数vector
inline int max( const vector<int> &vec )
{
	return *max_element( vec.begin(), vec.end() );//库函数，返回最大元素
}

//e)一个浮点数vector
inline float max( const vector<float> &vec )
{
	return *max_element( vec.begin(), vec.end() );//库函数，返回最大元素
}

//f)一个字符串vector
inline string max( const vector<string> &vec )
{
	return *max_element( vec.begin(), vec.end() );//库函数，返回最大元素
}

//g)一个整数数组
inline int max( const int *parray, int size )
{
	return *max_element( parray, parray+size );
}

//h)浮点数组
inline float max( const float *parray, int size )
{
	return *max_element( parray, parray+size );
}

//i)字符串数组
inline string max( const string *parray, int size )
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
	//			a)   d)			g)
	float fmax = max( max(fvec), max( farray, 5) );
	//			 b)		e)		  h)
	string smax = max( max(svec),max(sarray, 6) );
	//			   c)	f)		   g)
	
	cout << "imax should be 169 -- found: " << imax << "\n"
		 << "fmax shoulde be 24.8 -- found: " << fmax << "\n"
		 << " smax should be were -- found: " << smax << "\n";


	return 0;
}
