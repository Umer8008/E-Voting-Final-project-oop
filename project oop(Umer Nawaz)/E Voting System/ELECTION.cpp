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
    while (true) {
        time_t currenttime = time(nullptr);
        tm localtime;
        localtime_s(&localtime, &currenttime);

        // year
        cout << "Enter Start Year of Election :";
        while (true) {
            cin >> start_year;
            start_year -= 1900;
            if (cin.fail() || start_year < localtime.tm_year || start_year > localtime.tm_year + 1) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Year of Election :";
            }
            else
                break;
        }

        // month
        cout << "Enter Start Month of Election :";
        while (true) {
            cin >> start_month;
            start_month -= 1;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Month of Election :";
            }
            else if (start_month < 0 || start_month > 11) {
                cout << "Month must be between 1 and 12.\n";
            }
            else
                break;
        }

        // day
        int max;
        bool isLeap = ((start_year + 1900) % 4 == 0 && ((start_year + 1900) % 100 != 0 || (start_year + 1900) % 400 == 0));
        cout << "Enter Start Day of Election :";
        while (true) {
            cin >> start_day;
            if (start_month == 1) {
                max = isLeap ? 29 : 28;
            }
            else if (start_month == 3 || start_month == 5 || start_month == 8 || start_month == 10) {
                max = 30;
            }
            else {
                max = 31;
            }

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Day of Election :";
            }
            else if (start_day < 1 || start_day > max) {
                cout << "Day must be between 1 and " << max << ".\n";
            }
            else
                break;
        }

        // hour
        cout << "Enter Start Hour of Election (0-23): ";
        while (true) {
            cin >> start_hour;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Hour of Election : ";
            }
            else if (start_hour < 0 || start_hour > 23) {
                cout << "Hour must be between 0 and 23.\n";
            }
            else
                break;
        }

        // minute
        cout << "Enter Start Minute of Election (0-59): ";
        while (true) {
            cin >> start_min;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Minute of Election : ";
            }
            else if (start_min < 0 || start_min > 59) {
                cout << "Minutes must be between 0 and 59.\n";
            }
            else
                break;
        }

        // second
        cout << "Enter Start Second of Election (0-59): ";
        while (true) {
            cin >> start_sec;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid Start Second of Election : ";
            }
            else if (start_sec < 0 || start_sec > 59) {
                cout << "Second must be between 0 and 59.\n";
            }
            else
                break;
        }


        tm enter = {};
        enter.tm_year = start_year;
        enter.tm_mon = start_month;
        enter.tm_mday = start_day;
        enter.tm_hour = start_hour;
        enter.tm_min = start_min;
        enter.tm_sec = start_sec;

        time_t enteredTimeT = mktime(&enter);
        if (enteredTimeT == -1) {
            cout << "Invalid entered date/time.\n";
            continue;
        }

        double diffSeconds = difftime(enteredTimeT, currenttime);
        if (diffSeconds < 0) {
            cout << "Election start time is in the past! Please enter a future time.\n";
        }
        else if (diffSeconds <= 14 * 24 * 60 * 60) {
            cout << "Election start time successfully entered.\n";
            break;
        }
        else {
            cout << "Start time must be within the next 2 weeks.\n";
        }
    }
}

void ELECTION::end_election()
{
    while (true)
    {
        time_t currenttime = time(nullptr);
        tm localtime;
        localtime_s(&localtime, &currenttime);

        // year
        cout << "Enter End Year of Election :";
        while (true) {
            cin >> end_year;
            end_year -= 1900;
            if (cin.fail() || end_year < start_year) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Year of Election :";
            }
            else
                break;
        }

        // month
        cout << "Enter End Month of Election :";
        while (true) {
            cin >> end_month;
            end_month -= 1;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Month of Election :";
            }
            else if (end_month < 0 || end_month > 11) {
                cout << "Month must be between 1 and 12.\n";
            }
            else
                break;
        }

        // day
        int max_end;
        bool isLeapEnd = ((end_year + 1900) % 4 == 0 && ((end_year + 1900) % 100 != 0 || (end_year + 1900) % 400 == 0));
        cout << "Enter End Day of Election :";
        while (true) {
            cin >> end_day;
            if (end_month == 1) {
                max_end = isLeapEnd ? 29 : 28;
            }
            else if (end_month == 3 || end_month == 5 || end_month == 8 || end_month == 10) {
                max_end = 30;
            }
            else {
                max_end = 31;
            }

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Day of Election :";
            }
            else if (end_day < 1 || end_day > max_end) {
                cout << "Day must be between 1 and " << max_end << ".\n";
            }
            else
                break;
        }

        // hour
        cout << "Enter End Hour of Election :";
        while (true) {
            cin >> end_hour;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Hour of Election :";
            }
            else if (end_hour < 0 || end_hour > 23) {
                cout << "Hour must be between 1 and 24.\n";
            }
            else
                break;
        }

        // minute
        cout << "Enter End Minute of Election :";
        while (true) {
            cin >> end_min;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Minute of Election :";
            }
            else if (end_min < 0 || end_min > 59) {
                cout << "Minutes must be between 1 and 60.\n";
            }
            else
                break;
        }

        // second
        cout << "Enter End Second of Election :";
        while (true) {
            cin >> end_sec;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter Valid End Second of Election :";
            }
            else if (end_sec < 0 || end_sec > 59) {
                cout << "Second must be between 1 and 60.\n";
            }
            else
                break;
        }

        tm start_tm = {};
        start_tm.tm_year = start_year;
        start_tm.tm_mon = start_month;
        start_tm.tm_mday = start_day;
        start_tm.tm_hour = start_hour;
        start_tm.tm_min = start_min;
        start_tm.tm_sec = start_sec;

        time_t start_time = mktime(&start_tm);
        if (start_time == -1) {
            cout << "Invalid start date/time.\n";
            continue;
        }

        tm end_tm = {};
        end_tm.tm_year = end_year;
        end_tm.tm_mon = end_month;
        end_tm.tm_mday = end_day;
        end_tm.tm_hour = end_hour;
        end_tm.tm_min = end_min;
        end_tm.tm_sec = end_sec;

        time_t end_time = mktime(&end_tm);
        if (end_time == -1) {
            cout << "Invalid end date/time.\n";
            continue;
        }

        double diffSeconds = difftime(end_time, start_time);

        if (diffSeconds <= 0) {
            cout << "End time must be after start time.\n";
        }
        else if (diffSeconds >= 24 * 60 * 60 && diffSeconds <= 25 * 60 * 60) {
            cout << "End time successfully entered.\n";
            break;
        }
        else {
            cout << "End time must not be more than 1 day after start time.\n";
        }
    }
}
