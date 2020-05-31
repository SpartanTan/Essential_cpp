#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string user_first_name;
	string user_last_name;
	cout << "please enter your first name and last name:\n ";
	cin >> user_first_name;
	cin >> user_last_name;
	cout << '\n'
	     << "hello, " << user_first_name << user_last_name << endl; 
	return 0;
}
