#include "NATIONAL.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<limits>
#include "ELECTION.h"
#include"candidate.h"

using namespace std;

void NATIONAL::add_condidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";
	cout << "Enter Cnic :";
	//check 13 digit cnic
	while (true)
	{
		getline(cin, cnic);
		if (cnic.length() != 13)
			cout << "Enter 13 digit Cnic :";
		else {
			ifstream in(candidate_file);
			while (getline(in, line))
			{
				stringstream s(line);
				string col1, col2;

				getline(s, col1, ',');
				getline(s, col2, ',');
				if (col2 == cnic)
				{
					cout << "You are already candidate.\n";found = true;break;
				}
			}
			in.close();

			if (found)
				break;
			if (!found)
			{
				ifstream in(Nadra_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5;

					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');

					name = col1;
					if (col5 == cnic)
					{
						found2 = true;break;
					}
				}
				in.close();
			}

			if (!found2)
				cout << "Enter Again Correct Cnic :";
			else
				break;
		}
	}

	if (found)
		return;
	if (!check_dual_nationality(cnic))
	{
		if (check_pakistani(cnic))
		{
			if (check_age(cnic))//check age >=18
			{
				//province
				int a;
				while (true) {
					while (true)
					{
						cout << "Province :" << endl
							<< "1.PUNJAB" << endl
							<< "2.SINDH" << endl
							<< "3.KHYBER PAKHTUNKHWA" << endl
							<< "4.BALOCHISTAN" << endl
							<< "5.GILGIT-BALTISTAN" << endl
							<< "6.AZAD JAMMU & KASHMIR" << endl
							<< "7.FEDERAL CAPITAL TERRITORY" << endl;
						cout << "Enter Province: ";
						cin >> a;
						if (cin.fail() || a > 7 || a < 1)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\nEnter again 1 to 7 !!!" << endl;
						}
						else
							break;
					}
					if (a == 1)
					{
						province = "PUNJAB";break;
					}
					else if (a == 2)
					{
						province = "SINDH";break;
					}
					else if (a == 3)
					{
						province = "KHYBER PAKHTUNKHWA";break;
					}
					else if (a == 4)
					{
						province = "BALOCHISTAN";break;
					}
					else if (a == 5)
					{
						province = "GILGIT-BALTISTAN";break;
					}
					else if (a == 6)
					{
						province = "AZAD JAMMU & KASHMIR";break;
					}
					else
					{
						province = "FEDERAL CAPITAL TERRITORY";break;
					}
					break;
				}

				//district
				bool validDistrict = false;
				while (!validDistrict) {
					cout << "\nProvince" << province << " of Districts :" << endl;
					if (province == "PUNJAB") {
						for (int i = 0;i < 38;i++)
						{
							cout << i + 1 << "." << punjabDistricts[i] << endl;
						}
					}
					else if (province == "SINDH") {
						for (int i = 0;i < 31;i++)
						{
							cout << i + 1 << "." << sindhDistricts[i] << endl;
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0;i < 26;i++)
						{
							cout << i + 1 << "." << kpkDistricts[i] << endl;
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0;i < 36;i++)
						{
							cout << i + 1 << "." << balochistanDistricts[i] << endl;
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0;i < 4;i++)
						{
							cout << i + 1 << "." << gilgitBaltistanDistricts[i] << endl;
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0;i < 8;i++)
						{
							cout << i + 1 << "." << ajkDistricts[i] << endl;
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						cout << "1.Islamabad" << endl;
					}
					cout << "Enter District: ";
					getline(cin, district);

					for (int i = 0; i < district.length(); ++i) {
						if (district[i] >= 'a' && district[i] <= 'z') {
							district[i] = district[i] - 'a' + 'A';
						}
					}

					if (province == "PUNJAB") {
						for (int i = 0; i < sizeof(punjabDistricts) / sizeof(punjabDistricts[0]); ++i) {
							if (district == punjabDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "SINDH") {
						for (int i = 0; i < sizeof(sindhDistricts) / sizeof(sindhDistricts[0]); ++i) {
							if (district == sindhDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0; i < sizeof(kpkDistricts) / sizeof(kpkDistricts[0]); ++i) {
							if (district == kpkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0; i < sizeof(balochistanDistricts) / sizeof(balochistanDistricts[0]); ++i) {
							if (district == balochistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0; i < sizeof(gilgitBaltistanDistricts) / sizeof(gilgitBaltistanDistricts[0]); ++i) {
							if (district == gilgitBaltistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0; i < sizeof(ajkDistricts) / sizeof(ajkDistricts[0]); ++i) {
							if (district == ajkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						for (int i = 0; i < sizeof(islamabadDistricts) / sizeof(islamabadDistricts[0]); ++i) {
							if (district == islamabadDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}

					if (validDistrict) {
						cout << "Valid district in " << province << "!" << endl;
					}
					else {
						cout << "Invalid district for the selected province. Please try again.\n";
					}
				}

				//national
				int i = 0;
				cout << "\n\tNational seats in " << district << endl;
				//1
				ifstream in("F:\\project oop\\Data Base\\provincial election.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					if (col1 == province)
					{
						if (col2 == district)
						{
							i++;
							cout << i << ". " << col3 << endl;
						}
					}
				}
				in.close();
				
				cout << endl;

				int number;
				i = 0;
				while (true)
				{
					cout << "Enter NA # Index :";
					do {
						cin >> number;
						if (number<0 || number > i)
							cout << "Enter number between 1 and " << i << " : ";
						else if (cin.fail())
						{
							cout << "Enter number between 1 and " << i << " : ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else
							break;
					} while (true);
					
					ifstream in("F:\\project oop\\Data Base\\provincial election.txt");
					while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2, col3;
						getline(s, col1, ',');
						getline(s, col2, ',');
						getline(s, col3, ',');
						if(col1 == province)
						if (col2 == district)
						{
							i++;
							if (i == number)
								union_council = col3;
						}
					}
					in.close();
					
					break;
				}
				in.close();

				//Party of affiliation
				i = 0;
				cout << "Parties of " << province << " !!!" << endl;
				
				ifstream in2(party_file);
				while (getline(in, line))
				{
					cout << i + 1 << line << endl;i++;
				}
				in2.close();
				
				int b;
				while (true)
				{
					do {
						cout << "Enter Party Affiliation :";
						cin >> b;
						if (cin.fail() || b < 1 || b > i)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
					} while (cin.fail() || b < 1 || b > i);
					i = 0;
					ifstream in(party_file);
					while (getline(in, line))
					{
						stringstream s(line);
						string col1;
						getline(s, col1, ',');

						i++;
						if (i == b)
							party_affiliation = col1;
					}
					in.close();
				}

				vote = 0;
				ofstream out(candidate_file, ios::app);
				out << name << "," << cnic << "," << province << "," << district << "," << union_council
					<< "," << party_affiliation << "," << vote << endl;
				out.close();

				cout << "\n\tCandidate added successfully!" << endl;
			}
			else
				cout << "\tYour age is less than 25.!!!" << endl;
		}
		else
			cout << "You are not Pakistani so you are not applicable .\n";
	}
	else
		cout << "You have dual nationality so you are not applicable .\n";
}

void NATIONAL::remove_condidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";
	do {
		cout << "Enter Cnic for Remove Candidate :";
		do {
			getline(cin, cnic);
			if (cnic.length() != 13)
				cout << "Enter 13 digit Cnic :";
		} while (cnic.length() != 13);

		ifstream in(candidate_file);
		ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", ios::app);
		while (getline(in, line))
		{
			stringstream s(line);
			string col1, col2;
			getline(s, col1, ',');
			getline(s, col2, ',');
			if (col2 == cnic) { found = true; break; }
			else
				out << line << endl;
		}
		in.close();
		out.close();
		if (found)
			break;
		else
			cout << "Enter Cnic for Candidate :";
	} while (true);
	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
	cout << "\nCandidate remove successfully !!!" << endl;
}

void NATIONAL::modify_candidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	int y = localTime.tm_year + 1900;
	int m = localTime.tm_mon + 1;
	int d = localTime.tm_mday;

	bool change = false;
	if (y >= start_year && y <= end_year)
	{
		if (m >= start_month && m <= end_month)
		{
			if (d >= start_day && d <= end_day)
				change = true;
		}
	}
	if (change)
		cout << "Not Modified because Election is Start.";
	else
	{
		int z;
		cout << "Enter Cnic to Modify :";
		while (true)
		{
			getline(cin, cnic);
			if (cnic.length() != 13)
				cout << "Enter 13 digit Cnic :";
			else {
				ifstream in(candidate_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					if (col2 == cnic)
					{
						province = col3;
						found = true;
						break;
					}
				}
				in.close();
			}
			if (found)
				break;
			else
			{
				cout << "\n\tCnic not Found !!!" << endl;
				cout << "Enter Correct Cnic :";
			}
		}
		if (found)
		{
			do {
				cout << " Modify " << endl;
				cout << " 1. Party Change " << endl;
				cout << " 2. Election Area Change " << endl;
				cin >> z;
				if (cin.fail() || (z != 1 && z != 2))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nInvalid number !!!" << endl;
				}
				else
					break;
			} while (true);
			if (z == 1)
			{
				int i = 0;
				cout << "Parties of " << province << " !!!" << endl;
				ifstream in(party_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1;
					getline(s, col1, ',');

					cout << i + 1 << col1 << endl;i++;
				}
				in.close();
				int b;
				while (true)
				{
					do {
						cout << "Enter Party Affiliation :";
						cin >> b;
						if (cin.fail() || b < 1 || b > i)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
					} while (cin.fail() || b < 1 || b > i);
					int j = 0;
					ifstream in(party_file);
					while (getline(in, line))
					{
						stringstream s(line);
						string col1;
						getline(s, col1, ',');

						j++;
						if (j == b)
						{
							party_affiliation = col1;break;
						}
					}
					in.close();
				}

				ifstream in2(party_file);
				ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5, col6, col7;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');
					getline(s, col6, ',');
					getline(s, col7, ',');
					if (col2 == cnic)
						out << col1 << "," << col2 << "," << col3 << ","
						<< col4 << "," << col5 << "," << party_affiliation << "," << col7 << endl;
					else
						out << line << endl;
				}
				out.close();
				in2.close();
				remove(candidate_file.c_str());
				rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
			}
			else
			{
				//province
				int a;
				while (true) {
					while (true)
					{
						cout << "Province :" << endl
							<< "1.PUNJAB" << endl
							<< "2.SINDH" << endl
							<< "3.KHYBER PAKHTUNKHWA" << endl
							<< "4.BALOCHISTAN" << endl
							<< "5.GILGIT-BALTISTAN" << endl
							<< "6.AZAD JAMMU & KASHMIR" << endl
							<< "7.FEDERAL CAPITAL TERRITORY" << endl;
						cout << "Enter Province: ";
						cin >> a;
						if (cin.fail() || a > 7 || a < 1)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\nEnter again 1 to 7 !!!" << endl;
						}
						else
							break;
					}
					if (a == 1)
					{
						province = "PUNJAB";break;
					}
					else if (a == 2)
					{
						province = "SINDH";break;
					}
					else if (a == 3)
					{
						province = "KHYBER PAKHTUNKHWA";break;
					}
					else if (a == 4)
					{
						province = "BALOCHISTAN";break;
					}
					else if (a == 5)
					{
						province = "GILGIT-BALTISTAN";break;
					}
					else if (a == 6)
					{
						province = "AZAD JAMMU & KASHMIR";break;
					}
					else
					{
						province = "FEDERAL CAPITAL TERRITORY";break;
					}
					break;
				}

				//district
				bool validDistrict = false;
				while (!validDistrict) {
					cout << "\nProvince" << province << " of Districts :" << endl;
					if (province == "PUNJAB") {
						for (int i = 0;i < 38;i++)
						{
							cout << i + 1 << "." << punjabDistricts[i] << endl;
						}
					}
					else if (province == "SINDH") {
						for (int i = 0;i < 31;i++)
						{
							cout << i + 1 << "." << sindhDistricts[i] << endl;
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0;i < 26;i++)
						{
							cout << i + 1 << "." << kpkDistricts[i] << endl;
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0;i < 36;i++)
						{
							cout << i + 1 << "." << balochistanDistricts[i] << endl;
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0;i < 4;i++)
						{
							cout << i + 1 << "." << gilgitBaltistanDistricts[i] << endl;
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0;i < 8;i++)
						{
							cout << i + 1 << "." << ajkDistricts[i] << endl;
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						cout << "1.Islamabad" << endl;
					}
					cout << "Enter District: ";
					getline(cin, district);

					for (int i = 0; i < district.length(); ++i) {
						if (district[i] >= 'a' && district[i] <= 'z') {
							district[i] = district[i] - 'a' + 'A';
						}
					}

					if (province == "PUNJAB") {
						for (int i = 0; i < sizeof(punjabDistricts) / sizeof(punjabDistricts[0]); ++i) {
							if (district == punjabDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "SINDH") {
						for (int i = 0; i < sizeof(sindhDistricts) / sizeof(sindhDistricts[0]); ++i) {
							if (district == sindhDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0; i < sizeof(kpkDistricts) / sizeof(kpkDistricts[0]); ++i) {
							if (district == kpkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0; i < sizeof(balochistanDistricts) / sizeof(balochistanDistricts[0]); ++i) {
							if (district == balochistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0; i < sizeof(gilgitBaltistanDistricts) / sizeof(gilgitBaltistanDistricts[0]); ++i) {
							if (district == gilgitBaltistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0; i < sizeof(ajkDistricts) / sizeof(ajkDistricts[0]); ++i) {
							if (district == ajkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						for (int i = 0; i < sizeof(islamabadDistricts) / sizeof(islamabadDistricts[0]); ++i) {
							if (district == islamabadDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}

					if (validDistrict) {
						cout << "Valid district in " << province << "!" << endl;
					}
					else {
						cout << "Invalid district for the selected province. Please try again.\n";
					}
				}

				//National
				int i = 0;
				cout << "\n\tNational seats in " << district << endl;
				ifstream in("F:\\project oop\\Data Base\\provincial election.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					if (col1 == province)
					{
						if (col2 == district)
						{
							i++;
							cout << i << ". " << col3 << endl;
						}
					}
				}
				in.close();
				ifstream in3("F:\\project oop\\Data Base\\provincial election.txt");
				cout << endl;

				int number;
				i = 0;
				while (true)
				{
					cout << "Enter NA # Index :";
					do {
						cin >> number;
						if (number<0 || number > i)
							cout << "Enter number between 1 and " << i << " : ";
						else if (cin.fail())
						{
							cout << "Enter number between 1 and " << i << " : ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else
							break;
					} while (true);
					ifstream in("F:\\project oop\\Data Base\\provincial election.txt");
					while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2, col3;
						getline(s, col1, ',');
						getline(s, col2, ',');
						getline(s, col3, ',');
						if (col2 == district)
						{
							i++;
							if (i == number)
								union_council = col3;
						}
					}
					in.close();
					break;
				}
				in3.close();

				ifstream in4(party_file);
				ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5, col6, col7;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');
					getline(s, col6, ',');
					getline(s, col7, ',');
					if (col2 == cnic)
						out << col1 << "," << col2 << "," << province << ","
						<< district << "," << union_council << "," << col6 << "," << col7 << endl;
					else
						out << line << endl;
				}
				out.close();
				in4.close();
				remove(candidate_file.c_str());
				rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
			}
		}
	}
}

bool NATIONAL::check_age(string a)
{
	ifstream in(Nadra_file);
	while (getline(in, line)) {
		stringstream ss(line);
		string col1, col2, col3, col4, col5;

		getline(ss, col1, ',');
		getline(ss, col2, ',');
		getline(ss, col3, ',');
		getline(ss, col4, ',');
		getline(ss, col5, ',');

		if (col5 == a) {
			time_t currentTime = time(nullptr);
#ifdef _WIN32
			tm localTime;
			localtime_s(&localTime, &currentTime);
#else
			tm localTime;
			localtime_r(&currentTime, &localTime);
#endif
			int d = (localTime.tm_year + 1900) - stoi(col2);
			if (d >= 25)
			{
				found = true;
			}
			break;
		}
	}
	in.close();
	return found;
}

bool NATIONAL::check_dual_nationality(string a)
{
	ifstream in(Nadra_file);
	while (getline(in, line)) {
		stringstream ss(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13, col14;

		getline(ss, col1, ',');
		getline(ss, col2, ',');
		getline(ss, col3, ',');
		getline(ss, col4, ',');
		getline(ss, col5, ',');
		getline(ss, col6, ',');
		getline(ss, col7, ',');
		getline(ss, col8, ',');
		getline(ss, col9, ',');
		getline(ss, col10, ',');
		getline(ss, col11, ',');
		getline(ss, col12, ',');
		getline(ss, col13, ',');
		getline(ss, col14, ',');

		if (col5 == a) {

			int d = stoi(col14);
			if (d == 1)
			{
				found = true;
			}
			break;

		}
	}
	in.close();
	return found;
}

void NATIONAL::increment_vote(string a)
{
	string t = "F:\\project oop\\Data Base\\Election timings\\timings.txt";

	ifstream e1(t);
	while (getline(e1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		getline(s, col7, ',');
		getline(s, col8, ',');
		getline(s, col9, ',');
		getline(s, col10, ',');
		getline(s, col11, ',');
		getline(s, col12, ',');
		getline(s, col13, ',');
		if (col1 == "national")
		{
			start_year = stoi(col2);
			start_month = stoi(col3);
			start_day = stoi(col4);
			start_hour = stoi(col5);
			start_min = stoi(col6);
			start_sec = stoi(col7);
			end_year = stoi(col8);
			end_month = stoi(col9);
			end_day = stoi(col10);
			end_hour = stoi(col11);
			end_min = stoi(col12);
			end_sec = stoi(col13);
		}
	}
	e1.close();

	if (start_year == 0 || start_month == 0 || start_day == 0 ||
		end_year == 0 || end_month == 0 || end_day == 0)
	{
		cout << "Election not started yet !!!" << endl;
		return;
	}
	else
	{
		tm start_tm = {}, end_tm = {}, current_tm = {};
		start_tm.tm_year = start_year - 1900;
		start_tm.tm_mon = start_month - 1;
		start_tm.tm_mday = start_day;
		start_tm.tm_hour = start_hour;
		start_tm.tm_min = start_min;
		start_tm.tm_sec = start_sec;

		end_tm.tm_year = end_year - 1900;
		end_tm.tm_mon = end_month - 1;
		end_tm.tm_mday = end_day;
		end_tm.tm_hour = end_hour;
		end_tm.tm_min = end_min;
		end_tm.tm_sec = end_sec;

		time_t start_time = mktime(&start_tm);
		time_t end_time = mktime(&end_tm);
		time_t current_time = time(nullptr);

			if (start_time == -1 || end_time == -1) {
				cout << "Error creating time_t for start or end!" << endl;
				return;
			}

		if (current_time >= start_time && current_time <= end_time)
		{
		}
	}




	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";
	string c, uni, dis;

	ifstream p1(user_file);
	while (getline(p1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		if (col1 == a)
		{
			c = col5;
			break;
		}
	}
	p1.close();
	
	if (c == "false")
	{
		int l = 0, k = 0, cho;
		ifstream p2(Nadra_file);
		while (getline(p2, line))
		{
			stringstream s(line);
			string col1, col2, col3, col4, col5, col6, col7, col8, col9;
			getline(s, col1, ',');
			getline(s, col2, ',');
			getline(s, col3, ',');
			getline(s, col4, ',');
			getline(s, col5, ',');
			getline(s, col6, ',');
			getline(s, col7, ',');
			getline(s, col8, ',');
			getline(s, col9, ',');
			if (col5 == a)
			{
				uni = col9;
				break;
			}
		}
		p2.close();

		cout << "\nCandidate of " << uni << "\n\n";
		ifstream p3(candidate_file);
		while (getline(p3, line))
		{
			stringstream s(line);
			string col1, col2, col3, col4, col5, col6, col7;
			getline(s, col1, ',');
			getline(s, col2, ',');
			getline(s, col3, ',');
			getline(s, col4, ',');
			getline(s, col5, ',');
			getline(s, col6, ',');
			getline(s, col7, ',');
			if (col5 == uni)
			{
				l++;
				cout << l << ". " << col1 << "  Party: " << col6 << endl;
			}
		}
		p3.close();

		cout << "Enter choice :";
		while (true)
		{
			cin >> cho;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and " << l << " :";
			}
			else if (cho<0 || cho>l)
				cout << "Enter number between 1 and " << l << " :";
			else
				break;
		}

		ifstream p4(candidate_file);
		ofstream o1("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");

		while (getline(p4, line))
		{
			stringstream s(line);
			string col1, col2, col3, col4, col5, col6, col7;
			getline(s, col1, ',');
			getline(s, col2, ',');
			getline(s, col3, ',');
			getline(s, col4, ',');
			getline(s, col5, ',');
			getline(s, col6, ',');
			getline(s, col7, ',');
			if (col5 == uni)
			{
				k++;
				if (k == cho)
				{
					int d = stoi(col7);
					d++;
					o1 << col1 << "," << col2 << "," << col3 << "," << col4 << ","
						<< col5 << "," << col6 << "," << d << endl;
				}
				else
					o1 << line << endl;
			}
			else
				o1 << line << endl;
		}
		o1.close();
		p4.close();
		remove(candidate_file.c_str());
		rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());

		ifstream p5(user_file);
		ofstream o2("F:\\project oop\\Data Base\\temp.txt");
		while (getline(p5, line))
		{
			stringstream s(line);
			string col1, col2, col3, col4, col5;
			getline(s, col1, ',');
			getline(s, col2, ',');
			getline(s, col3, ',');
			getline(s, col4, ',');
			getline(s, col5, ',');
			if (col1 == a)
			{
				o2 << col1 << "," << col2 << "," << col3 << "," << col4 << "," << "true" << endl;
			}
			else
				o2 << line << endl;
		}
		o2.close();
		p5.close();
		remove(user_file.c_str());
		rename("F:\\project oop\\Data Base\\temp.txt", user_file.c_str());
	}
	else
		cout << "You are already voted in National.\n\n";
}

void NATIONAL::create_election(string a)
{
	string t = "F:\\project oop\\Data Base\\Election timings\\timings.txt";

	ifstream e1(t);
	while (getline(e1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		getline(s, col7, ',');
		getline(s, col8, ',');
		getline(s, col9, ',');
		getline(s, col10, ',');
		getline(s, col11, ',');
		getline(s, col12, ',');
		getline(s, col13, ',');
		if (col1 == "national")
		{
			start_year = stoi(col2);
			start_month = stoi(col3);
			start_day = stoi(col4);
			start_hour = stoi(col5);
			start_min = stoi(col6);
			start_sec = stoi(col7);
			end_year = stoi(col8);
			end_month = stoi(col9);
			end_day = stoi(col10);
			end_hour = stoi(col11);
			end_min = stoi(col12);
			end_sec = stoi(col13);
		}
	}
	e1.close();

	if (start_year == 0 || start_month == 0 || start_day == 0 ||
		end_year == 0 || end_month == 0 || end_day == 0)
	{
	}
	else
	{
		tm start_tm = {}, end_tm = {}, current_tm = {};
		start_tm.tm_year = start_year - 1900;
		start_tm.tm_mon = start_month - 1;
		start_tm.tm_mday = start_day;
		start_tm.tm_hour = start_hour;
		start_tm.tm_min = start_min;
		start_tm.tm_sec = start_sec;

		end_tm.tm_year = end_year - 1900;
		end_tm.tm_mon = end_month - 1;
		end_tm.tm_mday = end_day;
		end_tm.tm_hour = end_hour;
		end_tm.tm_min = end_min;
		end_tm.tm_sec = end_sec;

		time_t start_time = mktime(&start_tm);
		time_t end_time = mktime(&end_tm);
		time_t current_time = time(nullptr);

		if (start_time == 0)

			if (start_time == -1 || end_time == -1) {
				cout << "Error creating time_t for start or end!" << endl;
				return;
			}

		if (current_time >= start_time && current_time <= end_time)
		{
			cout << "Election is already started." << endl;
			return;
		}
	}

	start_election();
	end_election();

	ifstream a1(t);
	ofstream e2("F:\\project oop\\Data Base\\Election timings\\temp.txt");
	while (getline(a1, line))
	{
		stringstream s(line);
		string col1, col2;
		getline(s, col1, ',');
		getline(s, col2, ',');
		if (col1 == "national")
		{
			e2 << col1 << "," << start_year << "," << start_month << "," << start_day << ","
				<< start_hour << "," << start_min << "," << start_sec << "," << end_year << "," << end_month
				<< "," << end_day << "," << end_hour << "," << end_min << "," << end_sec << endl;
		}
		else
			e2 << line << endl;
	}
	e2.close();
	a1.close();
	remove(t.c_str());
	rename("F:\\project oop\\Data Base\\Election timings\\temp.txt", t.c_str());


	ifstream a2(user_file);
	ofstream a3("F:\\project oop\\Data Base\\temp.txt");
	while (getline(a2, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');

		a3 << col1 << "," << col2 << "," << col3 << "," << col4 << "," << "true" << "," << col6 << endl;
	}
	a2.close();
	a3.close();

	ofstream out12(user_file, ios::trunc);
	out12.close();
	ifstream p8("F:\\project oop\\Data Base\\temp.txt");
	ofstream p9(user_file);
	while (getline(p8, line))
	{
		p9 << line << endl;
	}
	p9.close();
	p8.close();
	remove("F:\\project oop\\Data Base\\temp.txt");

	ofstream out3("F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt");
	out3.close();
}

void NATIONAL::view_result(string a)
{
	string ab;int total = 0, h1 = 0;

	ifstream m1(Nadra_file);
	while (getline(m1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		getline(s, col7, ',');
		getline(s, col8, ',');
		getline(s, col9, ',');
		if (col5 == a)
		{
			ab = col9;
			break;
		}
	}
	m1.close();

	cout << "Candidate  PARTY  Votes  Percentage " << endl;
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";

	ifstream m3(candidate_file);
	while (getline(m3, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		getline(s, col7, ',');
		if (col5 == ab)
		{
			h1++;
			total += stoi(col7);
		}
	}
	m3.close();
	if (h1 != 0)
	{
		if (total != 0)
		{
			ifstream m2(candidate_file);
			while (getline(m2, line))
			{
				stringstream s(line);
				string col1, col2, col3, col4, col5, col6, col7;
				getline(s, col1, ',');
				getline(s, col2, ',');
				getline(s, col3, ',');
				getline(s, col4, ',');
				getline(s, col5, ',');
				getline(s, col6, ',');
				getline(s, col7, ',');
				if (col5 == ab)
				{
					cout << col1 << "  " << col6 << "  " << col7 << "  " << ((stoi(col7)) / total) * 100 << endl;
				}
			}
			m2.close();
		}
		else
			cout << "Not any vote to " << h1 << " candidates !!!" << endl;
	}
	else
		cout << "Not any candidate stand in the " << ab << " !!!" << endl;
}

void NATIONAL::admin_view_result()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";

	cout<<endl<<"Local View Result \n"<<endl;

    //province
	int a;
	while (true) {
		while (true)
		{
			cout << "Province :" << endl
				<< "1.PUNJAB" << endl
				<< "2.SINDH" << endl
				<< "3.KHYBER PAKHTUNKHWA" << endl
				<< "4.BALOCHISTAN" << endl
				<< "5.GILGIT-BALTISTAN" << endl
				<< "6.AZAD JAMMU & KASHMIR" << endl
				<< "7.FEDERAL CAPITAL TERRITORY" << endl;
			cout << "Enter Province: ";
			cin >> a;
			if (cin.fail() || a > 7 || a < 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nEnter again 1 to 7 !!!" << endl;
			}
			else
				break;
		}
		if (a == 1)
		{
			province = "PUNJAB";break;
		}
		else if (a == 2)
		{
			province = "SINDH";break;
		}
		else if (a == 3)
		{
			province = "KHYBER PAKHTUNKHWA";break;
		}
		else if (a == 4)
		{
			province = "BALOCHISTAN";break;
		}
		else if (a == 5)
		{
			province = "GILGIT-BALTISTAN";break;
		}
		else if (a == 6)
		{
			province = "AZAD JAMMU & KASHMIR";break;
		}
		else
		{
			province = "FEDERAL CAPITAL TERRITORY";break;
		}
		break;
	}

	//district
	bool validDistrict = false;
	while (!validDistrict) {
					cout << "\nProvince " << province << " of Districts :\n" << endl;
					if (province == "PUNJAB") {
						for (int i = 0;i < 38;i++)
						{
							cout << i + 1 << "." << punjabDistricts[i] << endl;
						}
					}
					else if (province == "SINDH") {
						for (int i = 0;i < 31;i++)
						{
							cout << i + 1 << "." << sindhDistricts[i] << endl;
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0;i < 26;i++)
						{
							cout << i + 1 << "." << kpkDistricts[i] << endl;
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0;i < 36;i++)
						{
							cout << i + 1 << "." << balochistanDistricts[i] << endl;
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0;i < 4;i++)
						{
							cout << i + 1 << "." << gilgitBaltistanDistricts[i] << endl;
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0;i < 8;i++)
						{
							cout << i + 1 << "." << ajkDistricts[i] << endl;
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						cout << "1.ISLAMABAD CAPITAL TERRITORY" << endl;
					}
					cout << "Enter District: ";
					cin.ignore(); 
					getline(cin, district); 

					for (int i = 0; i < district.length(); ++i) {
						if (district[i] >= 'a' && district[i] <= 'z') {
							district[i] = district[i] - 'a' + 'A';
						}
					}

					if (province == "PUNJAB") {
						for (int i = 0; i < sizeof(punjabDistricts) / sizeof(punjabDistricts[0]); ++i) {
							if (district == punjabDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "SINDH") {
						for (int i = 0; i < sizeof(sindhDistricts) / sizeof(sindhDistricts[0]); ++i) {
							if (district == sindhDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0; i < sizeof(kpkDistricts) / sizeof(kpkDistricts[0]); ++i) {
							if (district == kpkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0; i < sizeof(balochistanDistricts) / sizeof(balochistanDistricts[0]); ++i) {
							if (district == balochistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0; i < sizeof(gilgitBaltistanDistricts) / sizeof(gilgitBaltistanDistricts[0]); ++i) {
							if (district == gilgitBaltistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0; i < sizeof(ajkDistricts) / sizeof(ajkDistricts[0]); ++i) {
							if (district == ajkDistricts[i]) {
								validDistrict = true;
							}
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						if (district == "ISLAMABAD CAPITAL TERRITORY") {
							validDistrict = true;
						}
					}

					if ( !validDistrict) {
						cout << "Invalid district for the selected province. Please try again.\n" << endl;
					}
				}

	//union council
	int index = 1;
	cout << "\t!!! City of " << district << "!!!\n";
	if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA"
		|| province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
				{
					ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
					while (getline(in, line)) {
						stringstream ss(line);
						string col1, col2;

						getline(ss, col1, ',');
						getline(ss, col2, ',');

						if (col1 == district) {
							cout << index << ". " << col2 << endl;
							index++;
						}
					}
					in.close();
				}
	else if (province == "GILGIT-BALTISTAN") {
					ifstream i("F:\\project oop\\Data Base\\GILGIT.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << ". " << col2 << endl;index++;
					}
					i.close();
				}
	else {
					ifstream i("F:\\project oop\\Data Base\\AJK.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << col2 << endl;
					}
					i.close();
				}
	do {
					if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" || province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
					{
						cout << endl << "Enter City Name from the above list: ";
						cin >> union_council;

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else if (province == "GILGIT-BALTISTAN")
					{
						cout << endl << "Enter City Name from the above list: ";
						cin >> union_council;

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\GILGIT.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else
					{
						cout << endl << "Enter City Name from the above list: ";
						cin >> union_council;

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\AJK.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3, col4, col5, col6;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					if (!found) {
						cout << "\nUnion Council Not Found! Please try again.\n";
					}
	} while (!found);

    cout<< province <<" :"<<endl;
	ifstream y1(candidate_file);
    while(getline(y1,line))
	{
		stringstream s(line);
		string col1,col2,col3,col4,col5,col6,col7;
		getline ( s , col1 , ',');
		getline ( s , col2 , ',');
		getline ( s , col3 , ',');
		getline ( s , col4 , ',');
		getline ( s , col5 , ',');
		getline ( s , col6 , ',');
		getline ( s , col7 , ',');
		if(col3 == province)
		{
			if(col4==district)
			{
				if(col5==union_council)
                    cout<<col1<<col4<<col5<<col6<<col7<<endl;
			}
		}
	}
	y1.close();
}
