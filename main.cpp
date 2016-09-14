#include "getAll_nominal.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<string,int> record_Nominal;
	const char delim = 0x09;
	string dest;
	getNom(record_Nominal);
	bool res = writeDocNom(record_Nominal);
	if(!res){
		cout<<"writed fail!"<<endl;
	}
	return 0;
}
