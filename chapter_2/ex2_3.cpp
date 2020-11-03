#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern bool calc_elements(vector<int> &vec, int pos);
extern void display_elems(vector<int>&, const string&, ostream& = cout );


extern void really_calc_elems(vector<int> &vec, int pos);

//inlie函数
//判断元素值是否合理，且是否被计算过，如果没有，则进行确实的计算
inline bool calc_elems(vector<int> &vec, int pos)
{
	if( pos <= 0 || pos > 64 )
	{
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;	
	}
	if( vec.size() < pos )
	  really_calc_elems( vec, pos );
	return true;
}

void ex2_3()
{
	vector<int> pent;//用户指定的vector
	const string title("Pentagonal Numeric Series");

	calc_elems(pent,10);//计算数列
	display_elems(pent,title);//显示数列
	
	calc_elems(pent,20);
	display_elems(pent,title);//显示数列
}

int main()
{
	ex2_3();

	return 0;
}

/*
bool calc_elements( vector<int> &vec, int pos )
{
	if( pos <=0 || pos >64 )
	{
		cerr << "Sorry. Invalid position: "
			 << pos << endl;
		return false;
	}

	for( int ix = vec.size()+1; ix <= pos; ++ix ){
		vec.push_back( (ix*(3*ix-1)/2) );
	}
	return true;
}
*/

void really_calc_elems(vector<int> &vec, int pos)
{
	for( int ix = vec.size()+1; ix < pos; ++ix )
	  vec.push_back( (ix *(3*ix-1)/2 ));
}

void display_elems( vector<int> &vec, const string &title, ostream &os)
{
	os << '\n' << title << "\n\t";
	for( int ix = 0; ix < vec.size(); ++ix )
	{
		os << vec[ ix ] << ' ';
	}
	os << endl;
}











