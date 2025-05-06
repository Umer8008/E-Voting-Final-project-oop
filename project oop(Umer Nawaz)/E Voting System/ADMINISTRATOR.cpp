#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include"LOCAL.h"
#include"PROVINCIAL.h"
#include"NATIONAL.h"
#include "ADMINISTRATOR.h"
#include <cstdlib>

using namespace std;

void ADMINISTRATOR::interface()
{
	while (true)
	{
		cout << "\n\n\t----Adminstrator----\n\n";
		cout << "1. Add Candidate\n";
		cout << "2. Remove Candidate\n";
		cout << "3. Modify Candidate\n";
		cout << "4. View Results\n";
		cout << "5. Create Election\n";
		cout << "6. Exit\n";
		cout << "Enter Choice :";

		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 6 :";
			}
			else if (choice > 6 || choice < 1)
				cout << "Enter number between 1 and 6 :";
			else
				break;
		}

		switch (choice)
		{
		case 1:
			add_candidate();
			break;
		case 2:
			remove_candidate();
			break;
		case 3:
			modify_candidate();
			break;
		case 4:
			view_results();
			break;
		case 5:
			create_election();
			break;
		case 6:
			cout << "\n\tThanks for coming in E Voting Website";
			exit(0);
		}
	}
}

void ADMINISTRATOR::add_candidate()
{
	while (true) {
		cout << "\tAdd Candidate\n";
		cout << "1. Local Candidate\n";
		cout << "2. Provincial Candidate\n";
		cout << "3. National Candidate\n";
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
			e->add_condidate();
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->add_condidate();
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->add_condidate();
		}
		else 
			return;
	}
}

void ADMINISTRATOR::remove_candidate()
{
	while (true) {
		cout << "\tRemove Candidate\n";
		cout << "1. Local Candidate\n";
		cout << "2. Provincial Candidate\n";
		cout << "3. National Candidate\n";
		cout << "4. Exit\n";
		cout << "Enter Choice :";
		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 3 :";
			}
			else if (choice > 4 || choice < 1)
				cout << "Enter number between 1 and 3 :";
			else
				break;
		}

		ELECTION* e;
		if (choice == 1)
		{
			LOCAL l;
			e = &l;
			e->remove_condidate();
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->remove_condidate();
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->remove_condidate();
		}
		else
			return;
	}
}

void ADMINISTRATOR::modify_candidate()
{
	while (true) {
		cout << "\tModify Candidate\n";
		cout << "1. Local Candidate\n";
		cout << "2. Provincial Candidate\n";
		cout << "3. National Candidate\n";
		cout << "4. Exit\n";
		cout << "Enter Choice :";
		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 3 :";
			}
			else if (choice > 4 || choice < 1)
				cout << "Enter number between 1 and 3 :";
			else
				break;
		}

		ELECTION* e;
		if (choice == 1)
		{
			LOCAL l;
			e = &l;
			e->modify_candidate();
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->modify_candidate();
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->modify_candidate();
		}
		else
			return;
	}
}

void ADMINISTRATOR::view_results()
{
	while (true) {
		cout << "\tView Result\n";
		cout << "1. Local Candidate\n";
		cout << "2. Provincial Candidate\n";
		cout << "3. National Candidate\n";
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
			e->admin_view_result();
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->admin_view_result();
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->admin_view_result();
		}
		else
			return;
	}
}

void ADMINISTRATOR::create_election()
{
	while (true) {
		cout << "\tCreate Election\n";
		cout << "1. Local Candidate\n";
		cout << "2. Provincial Candidate\n";
		cout << "3. National Candidate\n";
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
			l.inter();
		}
		else if (choice == 2)
		{
			PROVINCIAL l;
			e = &l;
			e->create_election("abc");
		}
		else if (choice == 3)
		{
			NATIONAL l;
			e = &l;
			e->create_election("abc");
		}
		else
			return;
	}
}