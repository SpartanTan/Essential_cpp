#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//*****************//
//******STEP1******//
//*****************//
//最简单实现一个返回一个vector包含所有原vector中小于10的数
//该函数过于死板，没有弹性
vector<int> less_than_10( const vector<int> &vec )
{
	vector<int> nvec;
	for( int ix = 0; ix < vec.size(); ++ix )
	  if( vec[ix] < 10 )
		nvec.push_back( vec[ix] );
	return nvec;
}

//*****************//
//******STEP2******//
//*****************//
//将上一个函数通用化，能和不同的值进行比较
vector<int> less_than_v(const vector<int> &vec, int less_than_val );


//*****************//
//******STEP3******//
//*****************//
//允许用户指定不同的比较操作，如大于，小于等
//加入参数三为函数指针，用于指定比较方式
vector<int> filter_ver1( const vector<int> &vec, int filter_value, bool (*pred)( int, int ) );
//缺点是参数列表只支持传入int

//定义一些可以传给filter()的关系比较函数
//调用filter时可传入以下两个函数或其他 *返回类型为bool，且参数列表只接受两个整数* 的函数
bool less_than( int v1, int v2 )
{
	return v1 < v2 ? true : false;
}
bool greater_than( int v1, int v2 )
{
	return v1 > v2 ? true : false;
}

//filter函数实现
//找到所有小于某个值的元素，并且放入一个新的vector中
vector<int> filter_ver1( const vector<int> &vec, int filter_value, bool(*pred)( int, int ) )
{
	vector<int> nvec;
	
	for( int ix = 0; ix < vec.size(); ++ix )
	  //调用pred所指函数
	  //比较vec[ix]和filter_value
	  if( pred( vec[ix], filter_value ) )
		nvec.push_back( vec[ix] );
	return nvec;
}

//用find取代for
//find每次找到之后会返回一个iterator
//每次找到之后，++iter，继续寻找之后符合要求的元素
//避免对任一元素进行两次以上的查看
int count_occurs( const vector<int> &vec, int val )
{
	vector<int>::const_iterator iter = vec.begin();
	int occurs_count = 0;
	while(( iter = find( iter, vec.end(), val )) != vec.end() )
	{
		++occurs_count;
		++iter;//指向下一元素
	}
	return occurs_count;
}


//*****************//
//******STEP4******//
//*****************//
//引入 function object，可以将某组行为传递给函数，比指针的效率更高
//使用了bind2nd adapter的filter
vector<int> filter_ver2( const vector<int> &vec, int val, less<int> &lt )
{
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();

	//bind2nd( less<int>, val);
	//把val绑定于less<int>的第二个参数上
	//于是less<int>会将每个元素与val比较
	
	//容器内每个元素与val进行二元运算
	while(( iter = find_if( iter, vec.end(), bind2nd( lt, val ))) != vec.end() )
	{
		//每当iter != vec.end(),
		//iter 指向某个小于val的元素
		nvec.push_back( *iter );
		iter++;
	}
	return nvec;
}



//*****************//
//******STEP5******//
//*****************//
//将函数用function template的方式重新实现，可以支持多种容器
//传入一对iterator标识出一组元素范围，将元素类型参数化，也将比较操作参数化
//该函数与元素类型无关，与比较操作无关，也和容器类型无关
template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator
filter_ver3( InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred )
{
	while(( first = find_if( first, last, bind2nd( pred, val ))) != last )
	{
		cout << "found value: " << *first << endl;
		*at++ = *first++;
	}
	return at;
}

int main()
{
	const int elem_size = 8;

	int ia[ elem_size ] = {12,8,43,0,6,21,3,7 };
	vector<int> ivec( ia, ia+elem_size );

	//存储过滤后的结果
	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	cout << "filtering integer array for values less than 8\n";
	filter_ver3( ia, ia+elem_size, ia2, elem_size, less<int>() );
	
	cout << "filtering integer vector for values greater than 8\n";
	filter_ver3( ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>() );
}







			
