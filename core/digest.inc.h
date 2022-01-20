uint64_t digest(char* data, size_t size)
{
	uint64_t mask = 0x3C948FE923CD4530; //Just big random mask
	uint64_t res = 81163 * mask; //Relatively big prime
	
	for(size_t i=0; i<size; i++)
	{
		res += data[i];
		res *= mask; //Another relatively big prime
		res <<= sizeof(res) / 2;
		res ^= mask;
		res += data[i];
	}
	
	return res;
}
