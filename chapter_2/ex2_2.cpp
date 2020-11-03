#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern bool calc_elements(vector<int> &vec, int pos);
extern void display_elems(vector<int>&, const string&, ostream& = cout );

void ex2_2()
{
	vector<int> pent;//用户指定的vector
	const string title("Pentagonal Numeric Series");

	calc_elements(pent,10);//计算数列
	display_elems(pent,title);//显示数列
}

int main()
{
	ex2_2();

	return 0;
}

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

void display_elems( vector<int> &vec, const string &title, ostream &os)
{
	os << '\n' << title << "\n\t";
	for( int ix = 0; ix < vec.size(); ++ix )
	{
		os << vec[ ix ] << ' ';
	}
	os << endl;
}











