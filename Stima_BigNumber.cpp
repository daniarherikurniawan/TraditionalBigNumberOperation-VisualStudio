// Stima_BigNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigNumber.h"


int _tmain(int argc, _TCHAR* argv[])
{
	BigNumber a("379873982479387420938578437582378457839749857348759834852378457298758374857398475834958495");
	BigNumber b("279384283787584785983784753843834793480325475873458934837495384758937857384573495837586332");
	std::cout<<a.getNumber()<<std::endl;
	std::cout<<b.getNumber()<<std::endl;
	std::string s1=a.getNumber();
	std::string s2=b.getNumber();
	std::cout<<a.kurang(s1,s2,false)<<std::endl;
	std::cout<<a.bagi1(s1,s2)<<std::endl;
	std::cout<<a.mod(s1,s2)<<std::endl;
	system("pause");
	return 0;
}

