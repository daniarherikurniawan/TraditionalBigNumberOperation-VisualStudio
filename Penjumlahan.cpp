#include <cstdlib>
#include <iostream>
#include <sstream>
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
		bool Ada = false;
		string H1,H2,H3;
		string S1L1 = S1.substr(0,L1);
		string S1L2 = S1.substr(L1,L2);
		string S2L1 = S2.substr(0,L1);
		string S2L2 = S2.substr(L1,L2);

		
		T1 = Penjumlahan(S1L1,S2L1);
		//cout<<"T1 = "<<T1.Str<<endl;
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
		//cout<<"T2 = "<<T2.Str<<endl;
		T.Str = T1.Str + T2.Str;
		return T;
	}
}




int main(){
	string S1,S2,S3,S1rev,S2rev;
	TypeStr T;
	int L1,L2;

	cout<<"Masukkan angka pertama : ";
	cin>>S1;
	
	//cout<<S1<<endl;

	cout<<"Masukkan angka kedua : ";
	cin>>S2;

	L1 = S1.length();
	L2 = S2.length();
	S1rev = reverse(S1);
	S2rev = reverse(S2);

	SamakanDigit(&S1rev,&S2rev);

	T = Penjumlahan(S1rev,S2rev);

	S3 = reverse(T.Str);

	cout<<"Hasil penjumlahan "<<S1<<" + "<<S2<<" = "<<S3<<endl;

    return 0;    
}

