#include<iostream>
#include<vector>
#include<algorithms>

using namespace std;

extern bool grow_vec( vector<int> &, int );
vector<int> temp( vec.begin() );
//在Fibonacci中搜索
bool is_elem(vector<int> &vec, int elem )
{
	//需要确保数列中存在足够数量的元素，elem必须在数列中
	//方法之一是用elem与数列最大元素作比较
	int max_value = max_element( vec.begin(), vec.end() );
	if( max_value < elem )
	  return grow_vec(vec,elem);
	if( max_value == elem )
	  return true;
	//需要vector为排序后的
	//如果不确定可以复制一份排序
	copy( vec.begin(), vec.end(), temp.begin() );
	sort( temp.begin(),temp.end() );
	return binary_search( temp.begin(), temp.end(), elem );
}

