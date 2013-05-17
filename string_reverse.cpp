// interviewprog.cpp : Defines the entry point for the console application.
//
#include <iostream>

using namespace std;

void string_reverse1(char *string) 
{ 
	//Find length.  Assuming can't include string.h and utilizing strlen()
	char ch = *string;
	int sLen=0;
	while(ch)
	{
		sLen+=1;
		ch = *(++string);
	}

	//If length is not zero, reverse string
	if(sLen)
	{
		int iBeg=0;
		int iEnd=sLen-1;
		while(iBeg < iEnd)
		{
			ch = string[iEnd];
			string[iEnd] = string[iBeg];
			string[iBeg] = ch;
			iBeg++;
			iEnd--;
		}
	}
}

int main()
{
	char test1[] = "";
	char test2[] = "a";
	char test3[] = "abc";
	char test4[] = "abcdef";
	string_reverse1(test1);
	string_reverse1(test2);
	string_reverse1(test3);
	string_reverse1(test4);
	
	cout << "test1: " << test1 << endl;
	cout << "test2: " << test2 << endl;
	cout << "test3: " << test3 << endl;
	cout << "test4: " << test4 << endl;

	return 0;
}


