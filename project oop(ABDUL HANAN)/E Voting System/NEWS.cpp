#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<fstream>
#include "NEWS.h"

NEWS::NEWS()
{
	start_year = 0,
	start_month = 0,
	start_day = 0,
	start_hour = 0,
	start_min = 0,
	start_sec = 0,
	end_year = 0,
	end_month = 0,
	end_day = 0,
	end_hour = 0,
	end_min = 0,
	end_sec = 0;
}

void NEWS::punjab_local_time()
{
	cout << "Punjab :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "PUNJAB")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour 
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":" 
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::sindh_local_time()
{
	cout << "Sindh :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "SINDH")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::balochistan_local_time()
{
	cout << "Punjab :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "BALOCHISTAN")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::kpk_local_time()
{
	cout << "Kpk :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "KHYBER PAKHTUNKHWA")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::AJK_local_time()
{
	cout << "AJK :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "AZAD JAMMU & KASHMIR")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::gilgit_local_time()
{
	cout << "Gilgit :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
			if (col2 == "GILGIT-BALTISTAN")
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


		if (current_time < start_time)
		{
			cout << "Election has not started yet." << endl;
			return;
		}
		else if (current_time > end_time)
		{
			cout << "Election has ended." << endl;
			return;
		}
		else
		{
			cout << "Election is ongoing." << endl;
		}

	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
	return;
}

void NEWS::isl_local_time()
{
	cout << "Federal :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime; localtime_s(&localTime, &currentTime);
#else
	tm localTime; localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
		if (col1 == "local" && col2 == "FEDERAL CAPITAL TERRITORY")
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
	e1.close();

	if (start_year == 0 || start_month == 0 || start_day == 0 ||
		end_year == 0 || end_month == 0 || end_day == 0)
	{
		cout << "Election not started yet .!!!" << endl;
		return;
	}

	tm start_tm = {}, end_tm = {};
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

	if (start_time == -1 || end_time == -1) {
		cout << "Error creating time_t for start or end!" << endl;
		return;
	}

	if (currentTime < start_time)
	{
		cout << "Election is not started yet." << endl;
		return;
	}
	else if (currentTime > end_time)
	{
		cout << "Election has ended." << endl;
		return;
	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
}

void NEWS::PROVINCIAL_time()
{
	cout << "Provincial :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime; localtime_s(&localTime, &currentTime);
#else
	tm localTime; localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
		if (col1 == "provincial")
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
		cout << "Election not started yet .!!!" << endl;
		return;
	}

	tm start_tm = {}, end_tm = {};
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

	if (start_time == -1 || end_time == -1) {
		cout << "Error creating time_t for start or end!" << endl;
		return;
	}

	if (currentTime < start_time)
	{
		cout << "Election is not started yet." << endl;
		return;
	}
	else if (currentTime > end_time)
	{
		cout << "Election has ended." << endl;
		return;
	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
}

void NEWS::NATIONAL_time()
{
	cout << "National :" << endl;
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime; localtime_s(&localTime, &currentTime);
#else
	tm localTime; localtime_r(&currentTime, &localTime);
#endif

	ifstream e1(timingss);
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
		cout << "Election not started yet .!!!" << endl;
		return;
	}

	tm start_tm = {}, end_tm = {};
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

	if (start_time == -1 || end_time == -1) {
		cout << "Error creating time_t for start or end!" << endl;
		return;
	}

	if (currentTime < start_time)
	{
		cout << "Election is not started yet." << endl;
		return;
	}
	else if (currentTime > end_time)
	{
		cout << "Election has ended." << endl;
		return;
	}

	cout << "Start time :" << start_day << "-" << start_month << "-" << start_year << " " << start_hour
		<< ":" << start_min << ":" << start_sec << endl;
	cout << "End time :" << end_day << "-" << end_month << "-" << end_year << " " << end_hour << ":"
		<< end_min << ":" << end_sec << endl;
}

