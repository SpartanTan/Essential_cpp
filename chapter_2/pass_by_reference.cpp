#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ofstream ofil( "pass_by_reference_log.txt" );//定义一个ofstream对象，传入文件名

void display_reference( const vector<int> &vec );//传址方式传递vector，避免复制操作
void display( vector<int> );

void bubble_sort( vector<int> & );
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

void swap( int & a, int & val2 )
{
	//实际参数会因此而变
	int temp = a;
	a = val2;
	val2 = temp;
}

int main()
{
	int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );//vector初始化，用数组ia和ia的地址

	cout << "vector before sort: ";
	//display( vec );
	display_reference( vec );

	bubble_sort( vec );

	cout << "vector after sort: ";
	//display( vec );
	display_reference( vec );
}

void display( vector<int> vec )
{
	for( int ix = 0; ix < vec.size(); ++ix )
		cout << vec[ix] << ' ';
	cout << endl;
}

void display_reference( const vector<int> &vec )//传址方式传递vector，避免复制操作
{
	for( int ix = 0; ix < vec.size(); ++ix )
	{
		cout << vec[ix] << ' ';
		cout << endl;
	}
}


void bubble_sort( vector<int> &vec )
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		for( int jx = ix + 1; jx < vec.size(); ++jx )
			if( vec[ix] > vec[jx] ){
				ofil << "about to call swap!"
					 << "ix: " << ix << " jx: " << jx << '\t'
					 << " swapping: " << vec[ix]
					 << " with " << vec[jx] << endl;
				//swap2( vec[ix], vec[jx] );
				swap( vec[ix] , vec[jx] );
			}
}
