#include<iostream>
#include<vector>
using namespace std;

//前置声明(forward declaration)
//让编译器知道这个函数的存在
inline bool fibon_elem( int , int & );
const vector<int> *fibon_seq( int );
bool print_sequence( int );
inline bool is_size_ok( int );

int main()
{
	int pos;
	cout << "Program_name: *** declearing_a_function_inline ***\n" 
		 << "Please enter a position: ";
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

//返回Fibonacci数列中位置为pos的元素
//必须将该位置减1，因为第一个元素位于位置0
//如果程序无法支持返回pos的位置，返回0
inline bool fibon_elem( int pos, int &elem)
{
	const vector<int> *pseq = fibon_seq( pos );
	if( !pseq )
	{
		elem = 0;
		return false;
	}
	elem = (*pseq)[pos-1];
	return true;
}

//计算Fibonacci数列中的size个元素
//返回持有这些元素的静态容器地址
const vector<int> *fibon_seq( int size )
{
	const int max_size = 1024;
	static vector<int> elems;//将elems定义为空vector，按需要插入元素，静态容器

	if( !is_size_ok( size ) )
	{
		return 0;
	}

	//如果size等于或小于elems.size(),
	//就不需要重新计算
	for( int ix = elems.size(); ix < size; ++ix)
	{
		if( ix == 0 || ix == 1)
		  elems.push_back( 1 );
		else
		  elems.push_back( elems[ix-1]+elems[ix-2] );
	}
	return &elems;
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

//检验有效位置的操作
inline bool is_size_ok( int size )
{
	const int max_size = 1024;
	if( size <= 0 || size > max_size )
	{
		cerr << "Oops: requested size is not supported: "
			 << size << " -- can't fullfill request.\n";
		return false;
	}
	return true;
}

