#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstddef>
#include <stdio.h>
#include "MTSNodeID.h"

using namespace std;

void split(const string& src, const char &delim , string& dest)
{
	string str;
	str  = src;
//	cout<<str<<endl;
	int len = str.length();
//	cout<<len<<endl;
	bool f1 = false, f2 = false,f3 = false;
	int k = 0,start = 0 ,end = 0;
	for(int i = 0;i<len;i++){
		if(str[i] != delim){
			if(f1 && !f3){
				f3 = true;
				if(i>0){
					start = i;
				}
			}
		}
		else
		{
			if(false == f2&& f3 && f1){
				f2 = true;
				end = i;
				break;
			}
			if(false == f1) {
				f1 = true;
			}
		}
	}
	k = start ;
	int i;
	char res[10];
//	cout<<"start:"<<start<<","<<"end:"<<end<<",size:"<<end-start<<endl;
	for(i = 0;i<end - start ;i++){
		dest[i] = str[k];	
		res[i] = str[k];
		k++;
	}
	res[i] = '\0';
	dest = res;
//	cout<<"fun:<<"<<res<<">>"<<endl;
}

void getNom(map<string,int>& record_Nominal){
	ifstream fin;
	fin.open("CoreNatureDictionary.txt",ios::in|ios::binary);
	if(!fin.is_open()){
		cout<<"Error opening file!"<<endl;
		return;
	}
	char delim = 0x09;
	string str;
	string results;
	//char str[LINE_LENGTH];
	int num = 0;//////////////////////////////
	if(fin.good())
	{
		while(!fin.fail()){
			getline(fin,str);
			str[str.length()-1] = '\0';
			split(str,delim,results);
		
			if((65 <= results[0]&& results[0] <=90)||(97 <=results[0]&&results[0]<=122)){
				if(record_Nominal.count(results) <= 0){
					record_Nominal.insert(pair<string,int>(results,1));
				}
				else
					record_Nominal[results] = record_Nominal.find(results)->second + 1;
			}
		}
		
	}
	fin.close();
	ofstream out("nomiTable.txt");
	if(!out){
		cout<<"Error opening file!"<<endl;
		return;
	}
	map<string,int>::iterator it = record_Nominal.begin();
	for(;it!=record_Nominal.end();it++){
		out<<it->first<<endl;	
		//cout<<it->first<<" "<<it->second<<endl;
	}
	out.close();
}

bool writeDocNom(map<string , int >& record_Nominal){
	ofstream out("nomiID.txt");
	if(!out){
		cout<<"Error opening file!"<<endl;
		return false;
	}
	int size = record_Nominal.size();
	map<string,int>::iterator it = record_Nominal.begin();
	cout<<size<<"-------"<<endl;
	for(;it!=record_Nominal.end();it++){
		galaxy_eye_tools::MTSNodeID newNomId;
		string ab_str = "AB";//set nominal of word 
		string getNewABId;
		int res = newNomId.getid(ab_str,getNewABId);
//		cout<<ab_str<<" ";
		out<<it->first<<" ";
		if(-1 == res){
			//	return false;
//			cout<<"failed get id!"<<endl;
			out<<"failed get id!"<<endl;
			continue;
		}
	//		cout<<getNewABId<<endl;
			out<<getNewABId<<endl;
	}	
	out.close();
	return true;
}
