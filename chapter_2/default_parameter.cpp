#include<iostream>
#include<vector>
#include<fstream>
#include "NumericSeq.h"

using namespace std;
//修改bubble_sort(),摆脱对file scpe内 ofil的依赖
//ofstream ofil( "text_out1" );//定义一个ofstream对象，传入文件名

//void display( vector<int> );//在头文件中声明
void bubble_sort( vector<int> &, ofstream * );
/*
void swap2( int & val1, int & val2 )
{
	ofil << "swap( " << val1
		 << ", " << val2 << " )\n ";

	int temp = val1;
	val1 = val2;
	val2 = temp;
	
	ofil << "after swap(): val1 " << val1
		 << " val2: "
		 << val2 << "\n";
		 
}

*/
int main()
{
	int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );//vector初始化，用数组ia和ia的地址

	//不会产生任何调试信息
	ofstream offt( "test.txt" );
	bubble_sort( vec, &offt );
//	display( vec );
	cout << "complete stage 1" << endl;
	//产生调试信息
	ofstream ofil( "data.txt" );
	if( ofil == 0 )
	  cerr << "error" ;
	bubble_sort( vec, &ofil );
	display( vec, ofil );
	cout << "complete stage 2" << endl;

}

//void display( const vector<int> &vec, ostream &os = cout )//默认提供cout作为输出，也可自行指定
void display( const vector<int> &vec, ostream &os )//为提高可见性，默认值放在声明处而非定义处
{
	for( int ix = 0; ix < vec.size(); ++ix )
		os << vec[ix] << ' ';
	os << endl;
}

void bubble_sort( vector<int> &vec, ofstream *ofil = 0 )//将ofil声明为一个pointer，设置默认值为0
{													   //有了该参数后，以单一参数调用时不产生调试信息
	for ( int ix = 0; ix < vec.size(); ++ix )
		for( int jx = ix + 1; jx < vec.size(); ++jx )
			if( vec[ix] > vec[jx] )
			{
				if( ofil != 0 )
				  cout << "normal" << endl;
				  /*	( *ofil ) << "about to call swap!"
						<< "ix: " << ix << " jx: " << jx << '\t'
						<< " swapping: " << vec[ix]
						<< " with " << vec[jx] << endl;
				*/
				else
				{
				//  ( *ofil ) << "no ofil" << endl;
				  cout << " no ofil" << endl;
				}
				swap( vec[ix], vec[jx] );
			}
}
