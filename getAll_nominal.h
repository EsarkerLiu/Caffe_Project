#ifndef GETALL_NOMINAL_H
#define GETALL_NOMINAL_H
#include "MyProC.h"
#include <string>
#include <map>

using namespace std;


void split(const string& src, const char &delim , string& dest);


void getNom(map<string,int>& record_Nominal);

bool writeDocNom(map<string , int >& record_Nominal);

#endif
