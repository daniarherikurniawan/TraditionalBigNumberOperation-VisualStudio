/*
	created by Daniar Heri Kurniawan (13512064)
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
//#include "stdafx.h"
//#include "BigNumber.cpp"
using namespace std;


typedef struct {
	string Str;
} TypeStr;

void SamakanDigit(string * S1,string * S2){
	int L1 = S1->length();
	int L2 = S2->length();
	/*Menyamakan jumlah digit*/
	if(L1 > L2){
		for(int a = L2 ; a < L1; a++){
			*S2 += "0";
		}
	}else{
		for(int a = L1 ; a < L2; a++){
			*S1 += "0";
		}
	}
}


string reverse(string S){
	int L =S.length();
	for(int a = 0; a < L/2 ; a++){
		int temp = S[a];
		S[a] = S[L-a-1] ;
		S[L-a-1] = temp;
	}
	return S;
}


void SamakanDigitTerbalik(string * a,string * b){// Perkalian
	string S1 = *a;
	string S2 = *b;
	S1 = reverse (S1);
	S2 = reverse (S2);
	int L1 = S1.length();
	int L2 = S2.length();
	/*Menyamakan jumlah digit*/
	if(L1 > L2){
		for(int a = L2 ; a < L1; a++){
			S2 += "0";
		}
	}else{
		for(int a = L1 ; a < L2; a++){
			S1 += "0";
		}
	}
	(*a) = reverse (S1);
	(*b) = reverse (S2);
}



TypeStr Penjumlahan(string S1, string S2){
	int L = S1.length();
	TypeStr T;

	if(L == 1 ){
		int a = atoi(S1.c_str());
		int b = atoi(S2.c_str());
		int x = a + b;

		stringstream convert;   // stream used for the conversion
		convert << x;
		T.Str = convert.str();
		T.Str = reverse(T.Str);
		return T;
	}else{
		int L1 = L/2;
		int L2 = L - L1;
		TypeStr T1,T2;
		string H1,H2,H3;
		string S1L1 = S1.substr(0,L1);
		string S1L2 = S1.substr(L1,L2);
		string S2L1 = S2.substr(0,L1);
		string S2L2 = S2.substr(L1,L2);

		
		T1 = Penjumlahan(S1L1,S2L1);
		H1 = T1.Str;
		int LH1 = H1.length();
		if(LH1 > L1){
			H1 = T1.Str.substr(0,LH1-1);
			T1.Str = H1;
			string S1L2a = S1L2.substr(0,1);
			int Simpan = atoi(S1L2a.c_str());
			Simpan++;
			if(Simpan < 10){
				stringstream convert;
				convert << Simpan;
				S1L2a = convert.str();
				S1L2[0] = S1L2a[0];
			}else{
				TypeStr TTemp;
				string b = S1L2.substr(1,L2-1);
				string c = "1";
				SamakanDigit(&b,&c);
				TTemp = Penjumlahan(b,c);
				S1L2 = "0" + TTemp.Str;
			}	

		}
		SamakanDigit(&S1L2,&S2L2);
		T2 = Penjumlahan(S1L2,S2L2);
		T.Str = T1.Str + T2.Str;
		return T;
	}
}

TypeStr PenjumlahanTerbalik(string a, string b){
	TypeStr T;
	a = reverse(a);
	b = reverse(b);
	T = Penjumlahan(a,b);
	T.Str = reverse(T.Str);
	return T;
}

int PalingKecil(int a, int b){
	if(a < b){
		return a;
	}else{
		return b;
	}
}


TypeStr Perkalian(string S1, string S2){
	TypeStr T;
	int L = S1.length();
	if(L == 1 ){
		int a = atoi(S1.c_str());
		int b = atoi(S2.c_str());
		int x = a * b;

		stringstream convert;   // stream used for the conversion
		convert << x;
		T.Str = convert.str();
		T.Str = reverse(T.Str);
		return T;
	}else{
		int L1 = L/2;
		int L2 = L - L1;
		TypeStr T1,T2, M1, M2, M;
		string H1,H2,H3;
		string S1L1 = S1.substr(0,L1);
		string S1L2 = S1.substr(L1,L2);
		string S2L1 = S2.substr(0,L1);
		string S2L2 = S2.substr(L1,L2);

		SamakanDigit(&S1L1,&S2L2);
		M1 = Perkalian(S1L1,S2L2);
		string SM1 = M1.Str;
		SamakanDigit(&S1L2,&S2L1);
		M2 = Perkalian(S1L2,S2L1);
		string SM2 = M2.Str;
		SamakanDigit(&SM1,&SM2);
		M = Penjumlahan(SM1,SM2);
		
		T1 = Perkalian(S1L1,S2L1);
		H1 = T1.Str;
		int LH1 = H1.length();
		if(LH1 > L1){
			H1 = T1.Str.substr(L1,LH1-L1);
			T1.Str = T1.Str.substr(0,L1);
		}else{
			H1 = "0";
		}
		int LM = L1;
		string Temp = M.Str;

		SamakanDigit(&H1,&Temp);
		M = Penjumlahan(H1,Temp);
		H2 = M.Str;
		int LH2 = H2.length();
		if(LH2 > L1){
			M.Str = H2.substr(0,L1);
			H2 = H2.substr(L1,LH2 - L1);	
		}else{
			H2 = "0";
		}
		SamakanDigit(&S1L2,&S2L2);
		T2 = Perkalian(S1L2,S2L2);
		H3 = T2.Str;
		SamakanDigit(&H3,&H2);
		T2 = Penjumlahan(H3,H2);

		T.Str = T1.Str + M.Str + T2.Str;
		return T;
	}
}

string Pengurangan(string S1,string S2){
	int L = S1.length();
	int a = atoi(S1.c_str());
	int b = atoi(S2.c_str());
	int x = a - b;

	stringstream convert;   // stream used for the conversion
	convert << x;
	string Str = convert.str();
	if(Str.length() != L){
		int beda = L - Str.length();
		for (int a = 1; a<= beda ; a++){
			Str = "0" + Str;
		}
	}
	return Str;

}


bool LebihBesarSama(string S1, string S2){
	int a = atoi(S1.c_str());
	int b = atoi(S2.c_str());
	return (a>=b);
}

TypeStr Pengurangan2(string S1, string S2){// tidak terbalik
	int L = S1.length();
	TypeStr T;

	if(L == 2 || L==1){
		cout<<"S1l = "<<S1<<endl;
		cout<<"S2l = "<<S2<<endl;
		S1 = reverse(S1);
		S2 = reverse(S2);
		int a = atoi(S1.c_str());
		int b = atoi(S2.c_str());
		int x = a - b;

		stringstream convert;   // stream used for the conversion
		convert << x;
		T.Str = convert.str();
		if(L==2 && x == 0){
			T.Str += "0";
		}
		T.Str = reverse(T.Str);
		return T;
	}else{
		cout<<"S1 = "<<S1<<endl;
		cout<<"S2 = "<<S2<<endl;
		int L1 = L/2;
		int L2 = L - L1;
		TypeStr T1,T2, Tx;
		string H1,H2,H3;
		string S1L1 = S1.substr(0,L1);
		string S1L2 = S1.substr(L1,L2);
		string S2L1 = S2.substr(0,L1);
		string S2L2 = S2.substr(L1,L2);

		if(LebihBesarSama (S1L1,S2L1)){
			T1 = Pengurangan2(S1L1,S2L1);
		}else{
			cout<<"masuk"<<endl;
			S1L1 = S1L1 + "1";
			SamakanDigit(&S1L1,&S2L2);
			T1 = Pengurangan2(S1L1,S2L1);
			Tx = Pengurangan2(S1L2,"1");
			S1L2 = Tx.Str;

		cout<<"Tx = "<<Tx.Str<<endl;
		}
		
		T2 = Pengurangan2(S1L2,S2L2);
		cout<<"T1 = "<<T1.Str<<endl;
		cout<<"T2 = "<<T2.Str<<endl;
		T.Str = T1.Str + T2.Str;
		return T;
	}
}


TypeStr Kali3(string S1, string S2){
	int L = S1.length();
	TypeStr T;
	if(L == 1){
		int a = atoi(S1.c_str());
		int b = atoi(S2.c_str());
		int x = a * b;

		stringstream convert;   // stream used for the conversion
		convert << x;
		T.Str = convert.str();
		if(L==2 && x == 0){
			T.Str += "0";
		}
		return T;
	}else{
		TypeStr Tp,Tq, Tr , TP1,TP2, Tx,Ty;

		int s = L/2;

		string a = S1.substr(0,s) ;
		string b = S1.substr(s,L-s) ;
		string c = S2.substr(0,s) ;
		string d = S2.substr(s,L-s) ;

		SamakanDigitTerbalik(&a,&c);
		Tp = Kali3(a, c);
		SamakanDigitTerbalik(&b,&d);
		Tq = Kali3(b, d);		

		SamakanDigitTerbalik(&c,&d);
		TP1 = PenjumlahanTerbalik(c,d);
		SamakanDigitTerbalik(&a,&b);
		TP2 = PenjumlahanTerbalik(a,b);

		SamakanDigitTerbalik(&TP1.Str,&TP2.Str);
		Tr = Kali3(TP1.Str,TP2.Str);		
		string r = Pengurangan(Tr.Str,Tp.Str);
		r = Pengurangan(r,Tq.Str);

		if(Tq.Str.length()>L-s){
			//menyimpan
			int Lq = Tq.Str.length();
			int Lsave = Lq-(L-s);
			string save = Tq.Str.substr(0,Lsave);
			SamakanDigitTerbalik(&r,&save);
			Tx = PenjumlahanTerbalik(r,save);
			Tq.Str =  Tq.Str.substr(Lsave,Lq);
			r = Tx.Str;
		}

		if(r.length()>L-s){// berpotensi salah
			//menyimpan
			int Lr = r.length();
			int Lsave = Lr - (L-s);
			string save = r.substr(0,Lsave);
			SamakanDigitTerbalik(&Tp.Str,&save);
			Tp = PenjumlahanTerbalik(Tp.Str,save);
			r =  r.substr(Lsave,Lr);
		}
		T.Str = Tp.Str + r + Tq.Str;
		return T;
	}
}


string HilangkanNoldiAwal(string S3){
	bool stop = false;
	int L = S3.length();
	int aa = 0;
	do{
		if(S3[aa]=='0' && L>1){
			aa++;
			L--;
		}else{
			stop = true;
		}
	}while( L> 1 && !stop);
	S3 = S3.substr(aa,L+1);
	return S3;
}


int main(){
	string S1,S2,S3,S1rev,S2rev;
	TypeStr T,T2,T3;
	int L1,L2;
	//system("cls");
	cout<<"=======PERKALIAN=======\n"<<endl;
	cout<<"Masukkan angka pertama : ";
	cin>>S1;
	cout<<"Masukkan angka kedua   : ";
	cin>>S2;

	L1 = S1.length();
	L2 = S2.length();
	S1rev = reverse(S1);
	S2rev = reverse(S2);

	SamakanDigit(&S1rev,&S2rev);

	T = Perkalian(S1rev,S2rev);
	S3 = reverse(T.Str);
	S3 = HilangkanNoldiAwal(S3);
	cout<<"\nMenggunakan algoritma konvensional"<<endl;
	cout<<"Hasil perkalian "<<S1<<" x "<<S2<<" = "<<S3<<endl;

	SamakanDigitTerbalik(&S1,&S2);
	T2 = Kali3(S1,S2);
	S3 = T2.Str;

	S1 = HilangkanNoldiAwal(S1);
	S2 = HilangkanNoldiAwal(S2);
	S3 = HilangkanNoldiAwal(S3);
	cout<<"\nMenggunakan algoritma A. A. Karatsuba"<<endl;
	cout<<"Hasil perkalian "<<S1<<" x "<<S2<<" = "<<S3<<endl;

    return 0;    
}

