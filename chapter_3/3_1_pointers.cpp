

//如果给定值存在vector内，返回一个指针指向该值
int* find( const vector<int> &vec, value )
{
	for( int ix = 0; ix < vec.size(); ++ix )
	  if( vec[ ix ] == value )
		return &vec[ ix ];
	return 0;
}

//以模板形式实现
template <typename elemType>
elemType* find( const vector<elemType> &vec, const elemType &value )
{
	for(  )
	  if()
		return &vec[ ix ];
}

//传入array（其实是传入array的首地址）
//和array大小
template <typename elemType>
elemType* find( const elemType *array,int size, const elemType &value )
{
	if( ! array == 0 || size < 1 )
	  return 0;
	for ( int ix = 0; ix < size; ++ix )
	  if( array[ix] == value)
		return &array[ix];//返回了该元素所在的地址
	return 0;
}

//另一种实现
template <typename elemType>
elemType* find( const elemType *array,int size, const elemType &value )
{
	if( ! array == 0 || size < 1 )
	  return 0;
	//++array会令array指向下一个元素
	for ( int ix = 0; ix < size; ++ix, ++array )
	{
		if( *array == value )//*array提领了该地址的值
		  return array;//返回array的地址，等效array[ix]
	}
	return 0;
}


//传入array的首尾地址
template <typename elemType>
elemType* find( const elemType *first, const elemType *last, const elemType &value )
{
	if( ! first || ! last )
	  return 0;
	//++array会令array指向下一个元素
	for ( ; first != last; ++first )
	{
		if( *first == value )//*array提领了该地址的值
		  return first;//返回array的地址，等效array[ix]
	}
	return 0;
}

//将取用第一个元素的地址封装成函数
template <typename elemType>
inline elemType* begin( const vector<elemType> &vec )
{
	return vec.empty() ? 0 : &vec[0];
}

//取最后一个元素地址
template <typename elemType>
inline elemType* end( const vector<elemType> &vec )
{
	return vec.empty() ? 0 : &vec[vector.size()];
}








