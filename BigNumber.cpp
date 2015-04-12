#include "stdafx.h"

BigNumber::BigNumber(){
	number="";
}

BigNumber::BigNumber(std::string _number){
	number=_number;
}

BigNumber::BigNumber(const BigNumber& bigN){
	number=bigN.number;
}

BigNumber::~BigNumber(){

}

std::string BigNumber::getNumber(){
	return number;
}

void BigNumber::setNumber(std::string _number){
	number=_number;
}

 /* std::ofstream& operator<<(std::ofstream& icout, BigNumber bN){
	 icout << bN.getNumber();
	return icout;
} */
std::string BigNumber::operator-(BigNumber bN){
	std::string s1,s2;
	s1 = number;
	s2 = bN.getNumber();
	
	
	if(number.length()>=bN.getNumber().length()){
			return kurang(s1,s2,false);
	}
	else{
		return kurang(s2,s1,false);
	}
}

std::string BigNumber::kurang(std::string bN1, std::string bN2, bool flag){
	int N1,N2,Nhsl;
	std::string hsl;
	std::string s1;
	std::string s2;
	makeEqual(bN1,bN2);
	if(isLebihBesarSama(bN1,bN2)){
	
	//panjang operand 1 >= operand 2
	if(bN2.length()>1){
		s1 = bN1.substr(bN1.length()-1,bN1.length());
		s2 = bN2.substr(bN2.length()-1,bN2.length());
		
		N1 = std::stoi(s1);
		N2 = std::stoi(s2);

		if(flag){
			N1--;
		}
		
		if(N1<N2){
			flag=true;
			Nhsl=(10+N1)-N2;
		}
		else{
			flag=false;
			Nhsl=N1-N2;
		}
		
	std::string dummy;
	s1 = bN1.substr(0,bN1.length()-1);
	s2 = bN2.substr(0,bN2.length()-1);
	dummy = kurang(s1,s2,flag);
	hsl = dummy+std::to_string(Nhsl);
	
	
	}
	else{
		s1 = bN1.substr(0,bN1.length());
		s2 = bN2.substr(0,bN2.length());
		
		N1 = std::stoi(s1);
		N2 = std::stoi(s2);

		if(flag){
			N1--;
		}
		
		if(N1<N2){
			flag=true;
			Nhsl=(10+N1)-N2;
		}
		else{
			flag=false;
			Nhsl=N1-N2;
		}
		
		hsl = std::to_string(Nhsl);
	}

	return hsl;
	}
	else{
		s1=bN2;
		s2=bN1;
		hsl="-"+kurang(s1,s2,false);
		return hsl;
	}
	
}

std::string BigNumber::bagi1(std::string s1, std::string s2){
		if(!isLebihBesarSama(s1,s2)){
			return std::to_string(0);
		}
		else{
			return std::to_string(1+std::stoi(bagi1(kurang(s1,s2,false),s2)));
		}
}

std::string BigNumber::bagi2(std::string bN1, std::string bN2){
	return "haha";
}
std::string BigNumber::mod(std::string bN1, std::string bN2){
	if(!isLebihBesarSama(bN1,bN2)){
		return bN1;
	}
	else{
		return kurang(bN1,bN2,false);
	}
}

bool BigNumber::isLebihBesarSama(std::string bN1, std::string bN2){
	if(bN1.length()<bN2.length()){
		return false;
	}
	else if(bN1.length()>bN2.length()){
		return true;
	}
	else{
		std::string s1;
		std::string s2;
		s1=bN1.substr(0,1);
		s2=bN2.substr(0,1);
		int N1,N2;
		N1 = std::stoi(s1);
		N2 = std::stoi(s2);

		if(N1==N2){
			if(bN1.length()>1){
			s1 = bN1.substr(1,s1.length());
			s2 = bN2.substr(1,s2.length());
			return isLebihBesarSama(s1,s2);
			}
			else{
				return true;
			}
		}
		else{
			return N1>N2;
		}
	}
}

void BigNumber::makeEqual(std::string& bN1, std::string& bN2){
	if(bN1.length()==bN2.length()){
		//do nothing
	}
	else{
		if(bN2.length()>bN1.length()){
			makeEqual(bN2,bN1);
		}
		else{
			bN2 = '0'+bN2;
			makeEqual(bN1,bN2);
		}
	}
}