#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ofstream ofil( "text_out1" );//定义一个ofstream对象，传入文件名

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

int main()
{
	int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );//vector初始化，用数组ia和ia的地址

	cout << "vector before sort: ";
	display( vec);

	bubble_sort( vec );

	cout << "vector after sort: ";
	display( vec );
}

void display( vector<int> vec )
{
	for( int ix = 0; ix < vec.size(); ++ix )
		cout << vec[ix] << ' ';
	cout << endl;
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
				swap2( vec[ix], vec[jx] );
			}
}
