#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

class ELECTION
{
public:
	int start_month, start_year, start_day, start_hour, start_min, start_sec;
	int end_year, end_month, end_day, end_hour, end_min, end_sec;
	ELECTION(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0,
		int g=0,int h=0,int i=0,int j=0,int k=0,int l=0):
		start_day(a),start_month(b),start_year(c),end_day(d),end_month(e),end_year(f)
	    ,start_hour(g),start_min(h),start_sec(i),end_hour(j),end_min(k),end_sec(l)
	{ }
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