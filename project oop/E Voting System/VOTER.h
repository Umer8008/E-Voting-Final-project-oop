#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
#include"NATIONAL.h"
#include"LOCAL.h"
#include"PROVINCIAL.h"
using namespace std;

class VOTER
{
protected:
	int choice;
public:
	void interfaces(string a);
	void cast_vote(string a);
	void view_update(string a);
};

