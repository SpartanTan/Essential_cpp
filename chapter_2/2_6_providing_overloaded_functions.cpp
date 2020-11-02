
bool is_size_ok (int size)
{
	const int max_size = 1024;
	const string msg("Requested size is not supported");

	if( size <= 0 || size > max_size)
	{
		display_message( msg, size );
		return false;
	}
	return true;
}
