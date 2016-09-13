#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstddef>

using namespace std;

void split(const string& src , const string& delim , string& dest)
{
	string str = src;
	size_t start = 0 , index , end;
	cout<<str<<endl;
	int len = str.length();
	cout<<len<<endl;
	bool f = false;
	for(int i = 0;i<len;i++){
		if(str[i]==0x20)
		{
			f = true;
			cout<<"spaceblack"<<endl;
		}
	}
	if(f)cout<<"no found spaceblack"<<endl;
}

void writeDocNom(){
	ifstream fin;
	fin.open("CoreNatureDictionary.txt",ios::in|ios::binary);
	if(!fin.is_open()){
		cout<<"Error opening file!"<<endl;
		return;
	}
	string delim(" ");
	string str;
	string results;
	//char str[LINE_LENGTH];
	map<char,int> record_Nominal;
	int num = 0;//////////////////////////////
	cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	if(fin.good())
	{
		while(!fin.fail()){
			getline(fin,str);
			str[str.length()-1] = '\0';
			split(str,delim,results);
		if(num++ >20) break;
		}
/*	
		for(int i = 0; i<k;i++){
			cout<<temp_str[i]<<"|";
			if(record_Nominal.count(temp_str[i]) <= 0){
				record_Nominal.insert(pair<char,int>(temp_str[i],1));
			}
			else
				record_Nominal[temp_str[i]] = record_Nominal.find(temp_str[i])->second + 1;
		}
		*/
	}
	fin.close();
	cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>11>>>>>>>>>>>>>>>>>>>>>\n";
        cout<<results<<endl;  
	cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>22>>>>>>>>>>>>>>>>>>>>>>\n";
	map<char,int>::iterator it = record_Nominal.begin();
	for(;it!=record_Nominal.end();++it){
		cout<<it->first << "=> " << it->second <<endl;
	}
}

int main()
{
	writeDocNom();
	return 0;
}
