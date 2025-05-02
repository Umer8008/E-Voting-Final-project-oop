#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

class ELECTION
{
protected:
	int start_month, start_year, start_day, start_hour, start_min, start_sec;
	int end_year, end_month, end_day, end_hour, end_min, end_sec;
public:
	ELECTION(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0):
		start_day(a),start_month(b),start_year(c),end_day(d),end_month(e),end_year(f){ }
    ~ELECTION() {}
	
	virtual void add_condidate() = 0;
	virtual void remove_condidate() = 0;
	virtual void modify_candidate() = 0;
	virtual void increment_vote(string a) = 0;
	void start_election();
	void end_election();
	virtual void create_election(string a) = 0;
	virtual void view_result(string a) = 0;
	virtual void admin_view_result() = 0;
};