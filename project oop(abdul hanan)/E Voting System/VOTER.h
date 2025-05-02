#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
#include"NATIONAL.h"
#include"LOCAL.h"
#include"PROVINCIAL.h"
#include"NEWS.h"
using namespace std;

class VOTER
{
private:
	NEWS* n = new NEWS();
protected:
	int choice;
public:
	void interfaces(string a);
	void cast_vote(string a);
	void view_update(string a);
	void voter_news();
};

