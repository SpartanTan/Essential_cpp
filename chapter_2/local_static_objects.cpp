

const vector<int> *fibon_seq( int size )
{
	const int max_size = 1024;
	static vector<int> elems;//将elems定义为空vector，按需要插入元素

	if( size <= 0 || size > max_size )
	{
		cerr << "fibon_seq(): oops: invalid size: "
			 << size << " --can't fulfill request.\n";

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
