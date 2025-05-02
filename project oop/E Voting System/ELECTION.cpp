#include "ELECTION.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<limits>

using namespace std;

void ELECTION::start_election()
{
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	bool a = false;
	//year
	cout << "Enter Start Year of Election:";
	do {
		cin >> start_year;
		if (cin.fail())
		{
			cout << "Enter any correct year :";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (start_year< localTime.tm_year + 1900 || start_year>localTime.tm_year + 1900 + 1)
			cout << "Enter correct year between " << localTime.tm_year + 1900 << " and " << localTime.tm_year + 1900 + 1 << " :";
		else
			a = true;
	} while (!a);
	//month
	while (true) {
		cout << "Enter Month of Election (1-12): ";
		cin >> start_month;
		if (cin.fail() || start_month < 1 || start_month > 12) {
			cout << "Invalid input! Month must be between 1 and 12.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (start_year == localTime.tm_year + 1900 && start_month < localTime.tm_mon + 1)
		{
			cout << "Month cannot be LESS than the current month for this year.\n";
		}
		else {
			break;
		}
	}
	//day
	bool isLeapYear = (start_year % 4 == 0 && (start_year % 100 != 0 || start_year % 400 == 0));
	while (true) {
		cout << "Enter Day of Election: ";
		cin >> start_day;

		if (cin.fail() || start_day < 1 || start_day > 31) {
			cout << "Invalid input! Day must be between 1 and 31.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		bool validDay = true;
		if (start_month == 2) { 
			if (isLeapYear && start_day > 29) validDay = false;
			if (!isLeapYear && start_day > 28) validDay = false;
		}
		else if (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11) {
			if (start_day > 30) validDay = false;
		}

		if (!validDay) {
			cout << "Invalid day for the given month!\n";
		}
		else {
			break;
		}
	}
	//hour
	while (true)
	{
		cout << "Enter Hours between :";
		cin >> start_hour;
		start_hour--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (start_hour < 0 || start_hour > 23)
		{
			cout << "\n\tInvalid hour! Must be between 1 and 24.\n";
		}
		else if (start_hour < localTime.tm_hour && start_day == localTime.tm_mday &&
			start_month == localTime.tm_mon + 1 && start_year == localTime.tm_year + 1900)
			cout << "\nElection Start Timing is Greater than Current Timing !" << endl;
		else
			break;
	}
	//min
	while (true)
	{
		cout << "Enter Minutes (1 to 60):";
		cin >> start_min;
		start_min--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (start_min < 0 || start_min > 59) {
			cout << "\n\tInvalid minutes! Must be between 1 and 60.\n";
		}
		else if (start_min < localTime.tm_min && start_min < start_hour == localTime.tm_hour && start_day == localTime.tm_mday &&
			start_month == localTime.tm_mon + 1 && start_year == localTime.tm_year + 1900)
			cout << "\nElection Start Timing is Greater than Current Timing !" << endl;
		else
			break;
	}
	//sec
	while (true)
	{
		cout << "Enter Second (1 to 60):";
		cin >> start_sec;
		start_sec--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (start_sec < 0 || start_sec > 59) {
			cout << "\n\tInvalid second! Must be between 1 and 60.\n";
		}
		else if (start_sec < localTime.tm_sec && start_min == localTime.tm_min && start_min < start_hour == localTime.tm_hour && start_day == localTime.tm_mday &&
			start_month == localTime.tm_mon + 1 && start_year == localTime.tm_year + 1900)
			cout << "\nElection Start Timing is Greater than Current Timing !" << endl;
		else
			break;
	}
}

void ELECTION::end_election()
{
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;
	localtime_s(&localTime, &currentTime);
#else
	tm localTime;
	localtime_r(&currentTime, &localTime);
#endif

	bool isLeapYear;
	int max_day;
	//year
	while (true) {
		cout << "Enter End Year: ";
		cin >> end_year;
		if (cin.fail() || end_year < start_year) {
			cout << "Invalid year! End year must be same or after start year.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	//month
	while (true) {
		cout << "Enter End Month (1-12): ";
		cin >> end_month;
		if (cin.fail() || end_month < 1 || end_month > 12 ||
			(end_year == start_year && end_month < start_month)) {
			cout << "Invalid month! End month must be after start month for the same year.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	isLeapYear = (end_year % 4 == 0 && (end_year % 100 != 0 || end_year % 400 == 0));
	switch (end_month) {
	case 2:
		max_day = isLeapYear ? 29 : 28;
		break;
	case 4: case 6: case 9: case 11:
		max_day = 30;
		break;
	default:
		max_day = 31;
	}
	//day
	while (true) {
		cout << "Enter End Day (1-" << max_day << "): ";
		cin >> end_day;
		if (cin.fail() || end_day < 1 || end_day > max_day ||
			(end_year == start_year && end_month == start_month && end_day <= start_day)) {
			cout << "Invalid day! End day must be after start day for the same month.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	//hour
	while (true)
	{
		cout << "Enter Hours between :";
		cin >> end_hour;
		end_hour--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (start_hour < 0 || start_hour > 23)
		{
			cout << "\n\tInvalid hour! Must be between 1 and 24.\n";
		}
		else
			break;
	}
	//min
	while (true)
	{
		cout << "Enter Minutes (1 to 60):";
		cin >> end_min;
		end_min--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (end_min < 0 || end_min > 59) {
			cout << "\n\tInvalid minutes! Must be between 1 and 60.\n";
		}
		else
			break;
	}
	//sec
	while (true)
	{
		cout << "Enter Second (1 to 60):";
		cin >> end_sec;
		end_sec--;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\tIncorrect" << endl;
		}
		else if (end_sec < 0 || end_sec > 59) {
			cout << "\n\tInvalid second! Must be between 1 and 60.\n";
		}
		else
			break;
	}
}