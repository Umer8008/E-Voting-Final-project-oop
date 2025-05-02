#include "LOCAL.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include <cstddef>
#include "ELECTION.h"
#include"candidate.h"

using namespace std;

void LOCAL::add_condidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\LOCAL PARTIES.txt";
	cout << "Enter Cnic :";
	//check 13 digit cnic
	while (true)
	{
		cin >> cnic;
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
					cout << "You are already candidate.\n";in.close();return;
				}
				else
					found = false;
			}
			in.close();
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
					else
						found2 = false;
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

	if (check_pakistani(cnic))
	{
		if (check_age(cnic))//check age >=18
		{
			if (check_study(cnic))//check study is matric
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

				//Party of affiliation
				int i = 0;
				cout << "Parties of " << province << " !!!" << endl;
				ifstream in(party_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2;
					getline(s, col1, ',');
					getline(s, col2, ',');

					if (col1 == province)
					{
						cout << i + 1 << ". " << col2 << endl;i++;
					}
				}
				in.close();
				int b;
				while (true)
				{
					while (true) {
						cout << "Enter Party Affiliation :";
						cin >> b;
						if (cin.fail() || (b < 1 || b > i))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
						else
							break;
					}
					i = 0;
					ifstream in(party_file);
					while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');

						if (col1 == province)
						{
							i++;
							if (i == b)
								party_affiliation = col2;
						}
					}
					in.close();
					break;
				}

				vote = 0;
				ofstream out(candidate_file, ios::app);
				out << name << "," << cnic << "," << province << "," << district << "," << union_council
					<< "," << party_affiliation << "," << vote << endl;
				out.close();

				cout << "\n\tCandidate added successfully!\n" << endl;
			}
			else
			{
				cout << "In Local Govt. Study is minimum is matric !!!\n" << endl;return;
			}
		}
		else
		{
			cout << "\tYour age is less than 18.!!!\n" << endl;return;
		}
	}
	else
	{
		cout << "You are not Pakistani so you are not applicable .\n\n";return;
    }
}

void LOCAL::remove_condidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\LOCAL PARTIES.txt";
	cout << "Enter Cnic for Remove Candidate :";
	while (true)
	{
		do {
			cin >> cnic;
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
			cout << "Enter Correct Cnic for Candidate :";
	}
	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
	cout << "\nCandidate remove successfully !!!" << endl;
}

void LOCAL::modify_candidate()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\LOCAL PARTIES.txt";
		int z;
		cout << "Enter Cnic to Modify :";
		while (true)
		{
			cin >> cnic;
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
				ifstream in21(party_file);
				while (getline(in21, line))
				{
					stringstream s(line);
					string col1, col2;
					getline(s, col1, ',');
					getline(s, col2, ',');

					if (col1 == province)
					{
						cout << i + 1 <<". " << col2 << endl;i++;
					}
				}
				in21.close();
				int b;
				while(true){
					cout << "Enter Party Affiliation :";
					cin >> b;
					if (cin.fail() || b < 1 || b > i)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
					else
						break;
					}
				int j = 0;
				ifstream in(party_file);
				while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');

						if (col1 == province)
						{
							j++;
							if (j == b)
							{
								party_affiliation = col2;break;
						    }
						}
					}
				in.close();

				ifstream in1(candidate_file);
				ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt",ios::app);
				while (getline(in1, line))
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
				in1.close();
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

					if (!validDistrict) {
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

				ifstream in(candidate_file);
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
				in.close();
				remove(candidate_file.c_str());
				rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
			}
		}
}

bool LOCAL::check_age(string a)
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
			if (d >= 18)
				found = true;
			else
				found = false;
			break;
		}
	}
	in.close();
	return found;
}

bool LOCAL::check_study(string a)
{
	ifstream in(Nadra_file);

	while (getline(in,line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13, col14, col15, col16;
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
		getline(s, col14, ',');
		getline(s, col15, ',');
		getline(s, col16, ',');
		if (col5 == a)
		{
			int d = stoi(col16);
			if (d >= 10)
				found = true;
			else
				found = false;
			break;
		}
	}
	in.close();
	return found;
}

void LOCAL::increment_vote(string a)
{
	ifstream in23(Nadra_file);
	while (getline(in23, line))
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
		if (col5 == a)
		{
			a = col7;break;
		}
	}
	in23.close();


	string t = "F:\\project oop\\Data Base\\Election timings\\timings.txt";
	ifstream e1(t);
	while (getline(e1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13, col14;
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
		getline(s, col14, ',');
		if (col1 == "local")
		{
			if (col2 == a)
			{
				start_year = stoi(col3);
				start_month = stoi(col4);
				start_day = stoi(col5);
				start_hour = stoi(col6);
				start_min = stoi(col7);
				start_sec = stoi(col8);
				end_year = stoi(col9);
				end_month = stoi(col10);
				end_day = stoi(col11);
				end_hour = stoi(col12);
				end_min = stoi(col13);
				end_sec = stoi(col14);
			}
		}
	}
	e1.close();

	if (start_year == 0 || start_month == 0 || start_day == 0 ||
		end_year == 0 || end_month == 0 || end_day == 0)
	{
		cout << "Election not started yet .!!!" << endl;
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
		{}
	}


	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\LOCAL PARTIES.txt";
	user_file = "F:\\project oop\\Data Base\\login.txt";
	string c,uni,dis,pro;
	ifstream p1(user_file);
	while (getline(p1,line))
	{
		stringstream s(line);
		string col1, col2, col3;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		if (col1 == a)
		{
			c = col3;
			break;
		}
	}
	p1.close();
	if (c == "false")
	{
		int l = 0, k = 0,cho;
		ifstream p2(Nadra_file);
		while (getline(p2, line))
		{
			stringstream s(line);
			string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11;
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
			if (col5 == a)
			{
				pro = col7;
				dis = col8;
				uni = col11;
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
			if (col3==pro && col4== dis && col5==uni)
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
			if (col3 == pro && col4 == dis && col5 == uni)
			{
				k++;
				if (k == cho)
				{
					int d = stoi(col7);
					d++;
					o1 << col1 <<"," << col2 << "," << col3 << "," << col4 << "," 
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
			string col1, col2, col3, col4, col5, col6;
			getline(s, col1, ',');
			getline(s, col2, ',');
			getline(s, col3, ',');
			getline(s, col4, ',');
			getline(s, col5, ',');
			getline(s, col6, ',');
			if (col1 == a)
			{
				o2 << col1 << "," << col2 << "," << "true" << "," << col4 << "," << col5 << "," << col6 << endl;
			}
			else
				o2 << line << endl;
		}
		o2.close();
		p5.close();

		ofstream out12(user_file, ios::trunc);
		out12.close();

		ifstream p6("F:\\project oop\\Data Base\\temp.txt");
		ofstream p7(user_file);
		while (getline(p6, line))
		{
			p7 << line << endl;
		}
		p7.close();
		p6.close();
		remove("F:\\project oop\\Data Base\\temp.txt");
	}
	else
		cout << "You are already voted in Local.\n\n";
}

void LOCAL::create_election(string a)
{
	string t = "F:\\project oop\\Data Base\\Election timings\\timings.txt";
	
	ifstream e1(t);
	while (getline(e1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13, col14;
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
		getline(s, col14, ',');
		if (col1 == "local")
		{
			if (col2 == a)
			{
				start_year = stoi(col3);
				start_month = stoi(col4);
				start_day = stoi(col5);
				start_hour = stoi(col6);
				start_min = stoi(col7);
				start_sec = stoi(col8);
				end_year = stoi(col9);
				end_month = stoi(col10);
				end_day = stoi(col11);
				end_hour = stoi(col12);
				end_min = stoi(col13);
				end_sec = stoi(col14);
			}
		}
	}
	e1.close();

	if (start_year == 0 || start_month == 0 || start_day == 0 ||
		end_year == 0 || end_month == 0 || end_day == 0)
	{}
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
		if (col2 == a)
		{
			e2 << col1 << "," << col2 << "," << start_year << "," << start_month << "," << start_day << "," 
				<< start_hour << ","<< start_min << "," << start_sec << "," << end_year << "," << end_month 
				<< "," << end_day << "," << end_hour << "," << end_min << "," << end_sec << endl;
		}
		else
			e2 << line << endl;
	}
	e2.close();
	a1.close();
	remove(t.c_str());
	rename("F:\\project oop\\Data Base\\Election timings\\temp.txt", t.c_str());

	//voter false

	ifstream a2(user_file);
	ofstream a3("F:\\project oop\\Data Base\\temp.txt");
	while (getline(a2,line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		if (col6 == a)
			a3 << col1 << "," << col2 << "," << "false" << "," << col4 << "," << col5 << "," << col6 << endl;
		else
			a3 << line << endl;
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

	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	ifstream a7(candidate_file);
	ofstream a8("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");
	while (getline(a7, line))
	{
		stringstream s(line);
		string col1, col2, col3;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		if (col3 != a)
			a8 << line << endl;
	}
	a7.close();
	a8.close();

	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
}

void LOCAL::inter()
{
	int a;
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
			province = "PUNJAB";
		}
		else if (a == 2)
		{
			province = "SINDH";
		}
		else if (a == 3)
		{
			province = "KHYBER PAKHTUNKHWA";
		}
		else if (a == 4)
		{
			province = "BALOCHISTAN";
		}
		else if (a == 5)
		{
			province = "GILGIT-BALTISTAN";
		}
		else if (a == 6)
		{
			province = "AZAD JAMMU & KASHMIR";
		}
		else
		{
			province = "FEDERAL CAPITAL TERRITORY";
		}
		create_election(province);
		return;
}

void LOCAL::view_result(string a)
{
	string ab1, ab2, ab3;int total = 0, h1 = 0;
	
	ifstream m1(Nadra_file);
	while (getline(m1, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11;
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
		if (col5 == a)
		{
			ab1 = col7;
			ab2 = col8;
			ab3 = col11;
			break;
		}
	}
	m1.close();
	
	cout << "Candidate  PARTY  Votes  Percentage " << endl;
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";

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
		if (col3 == ab1 && col4 == ab2 && col5 == ab3)
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
				if (col3 == ab1 && col4 == ab2 && col5 == ab3)
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
		cout << "Not any candidate stand in the" << ab3 << " !!!" << endl;
}

void LOCAL::admin_view_result()
{
	candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\local candidate database.txt";
	party_file = "F:\\project oop\\Data Base\\PARTY\\LOCAL PARTIES.txt";

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










