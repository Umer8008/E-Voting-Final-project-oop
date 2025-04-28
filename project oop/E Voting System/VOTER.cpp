#include "VOTER.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<fstream>
#include"NATIONAL.h"
#include"LOCAL.h"
#include"PROVINCIAL.h"

using namespace std;

void VOTER::interfaces(string a)
{
	while (true)
	{
		cout << "\n\tVoter\n\n" << endl;
		cout << "1.Cast Vote " << endl;
		cout << "2. View Update " << endl;
		cout << "3. Exit " << endl;
		cout << "Enter Choice :";

		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 3 :";
			}
			else if (choice > 3 || choice < 1)
				cout << "Enter number between 1 and 3 :";
			else
				break;
		}
		
		switch (choice)
		{
		case 1:
			cast_vote(a);
			break;
		case 2:
			view_update(a);
			break;
		case 3:
			cout << "\n\tThanks for coming in E Voting Website";
			exit(0);
		}
	}
}

void VOTER::cast_vote(string a)
{
	while (true) {
		cout << "\tElection\n";
		cout << "1. Local Election\n";
		cout << "2. Provincial Election\n";
		cout << "3. National Election\n";
		cout << "4. Exit\n";
		cout << "Enter Choice :";
		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 4 :";
			}
			else if (choice > 4 || choice < 1)
				cout << "Enter number between 1 and 4 :";
			else
				break;
		}

		ELECTION* e;
		if (choice == 1)
		{
			LOCAL l;
			e = &l;
			e->increment_vote(a);
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->increment_vote(a);
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->increment_vote(a);
		}
		else
			return;
	}
}

void VOTER::view_update(string a)
{
	while (true) {
		cout << "\tView Result\n";
		cout << "1. Local Election\n";
		cout << "2. Provincial Election\n";
		cout << "3. National Election\n";
		cout << "4. Exit\n";
		cout << "Enter Choice :";
		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 4 :";
			}
			else if (choice > 4 || choice < 1)
				cout << "Enter number between 1 and 4 :";
			else
				break;
		}

		ELECTION* e;
		if (choice == 1)
		{
			LOCAL l;
			e = &l;
			e->view_result(a);
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->view_result(a);
		}
		else if (choice == 3)
		{
			NATIONAL y;
			e = &y;
			e->view_result(a);
		}
		else
			return;
	}
}