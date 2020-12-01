#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	istream_iterator<string> is( cin );
	istream_iterator<string> eof;

	vector<string> text;
	copy( is, eof, back_inserter( text ) );

	sort( text.begin(), text.end() );

	ostream_iterator<string> os( cout, " " );
	copy( text.begin(), text.end(), os );
}

int main()//文件
{

	ifstream in_file( "input_file.txt " );
	ofstream out_file( "output_file.ext " );

	if( !in_file || !out_file )
	{

	}
}





