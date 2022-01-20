#include <iostream>
#include <cstring>
#include "../core/digest.inc.h"

int main(int argc, char** argv){
	std::cout<<std::hex;

	if(argc < 2)
	{
		char* str1 = "Test string 1";
		char* str2 = "Test string 2";
		
		uint64_t digest1 = digest(str1, strlen(str1));
		uint64_t digest2 = digest(str2, strlen(str2));
		
		std::cout<<"Digest for '"<<str1<<"' : "<<digest1<<std::endl;
		std::cout<<"Digest for '"<<str2<<"' : "<<digest2<<std::endl;
	}
		
	for(int i = 1; i<argc; i++)
	{
		uint64_t digest_argv = digest(argv[i], strlen(argv[i]));
		std::cout<<"Digest for '"<<argv[i]<<"' : "<<digest_argv<<std::endl;
	}
}
