#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>

using namespace std;

class NEWS
{
protected:
	int start_month, start_year, start_day, start_hour, start_min, start_sec;
	int end_year, end_month, end_day, end_hour, end_min, end_sec;
	string timingss = "F:\\project oop\\Data Base\\Election timings\\timings.txt", line;
public:
	NEWS();
	void punjab_local_time();
	void sindh_local_time();
	void balochistan_local_time();
	void kpk_local_time();
	void AJK_local_time();
	void gilgit_local_time();
	void isl_local_time();
	void PROVINCIAL_time();
	void NATIONAL_time();
};

