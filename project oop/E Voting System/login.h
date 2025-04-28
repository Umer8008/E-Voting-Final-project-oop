#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
#include"VOTER.h"
#include"ADMINISTRATOR.h"
using namespace std;

class login:public ADMINISTRATOR,public VOTER
{
private:
    string username, password, dist;
    bool vote;
    void signup();
    string file1 = "F:\\project oop\\Data Base\\nadra_database.txt";
    string file2 = "F:\\project oop\\Data Base\\login.txt";
public:
    void log();
};