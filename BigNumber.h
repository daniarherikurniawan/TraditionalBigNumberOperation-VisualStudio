#pragma once

#include <iostream>
#include <cstdio>
#include <string>

class BigNumber{
	private :
	std::string number;
	
	public :
	BigNumber();
	BigNumber(std::string _number);
	BigNumber(const BigNumber& bigN);
	~BigNumber();

	std::string getNumber();
	void setNumber(std::string _number);
	std::string operator-(BigNumber bN);
	std::string& operator/(BigNumber bN);
	std::string& operator%(BigNumber bN);
	friend std::ofstream& operator<<(std::ofstream& cout,BigNumber bN);
	std::string kurang(std::string bN1, std::string bN2, bool flag);
	std::string bagi1(std::string bN1, std::string bN2);
	std::string bagi2(std::string bN1, std::string bN2);
	std::string mod(std::string bN1, std::string bN2);
	bool isLebihBesarSama(std::string bN1, std::string bN2);
	void makeEqual(std::string& bN1, std::string& bN2);
};