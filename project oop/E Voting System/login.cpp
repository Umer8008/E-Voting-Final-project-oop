#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include "login.h"
#include"VOTER.h"
#include"ADMINISTRATOR.h"

using namespace std;

void login::log() {
    while (true) {
        cout << "\nLogin\n" << endl;
        ifstream in(file2);
        bool found = false, sig = false;
        string line;
        char check;

        if (!in.is_open())
        {
            ofstream out(file2);
            out.close();
            in.open(file2);
        }

        cout << "Enter CNIC (13 digits): ";
        do {
            sig = false;
            cin >> username;

            if (username.length() != 13) {
                cout << "Invalid CNIC length. Please enter 13 digits: ";
                continue;
            }

            if (username == "3520231292443")
            {
                do {
                    cout << "Enter password :";
                    cin >> password;
                    if (password == "abc")
                        interface();
                } while (true);
            }
            in.clear();
            in.seekg(0);
            found = false;
            while (getline(in, line)) {
                stringstream ss(line);
                string stored_cnic;
                getline(ss, stored_cnic, ',');
                if (stored_cnic == username) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nCNIC not found!\n";
                cout << "Press Y to sign up or any other key to re-enter CNIC: ";
                cin >> check;
                if (toupper(check) == 'Y') {
                    signup();
                }
                else {
                    cout << "Please enter CNIC again: ";
                }
            }
        } while (!found);

        cout << "Enter password: ";
        do {
            cin >> password;
            in.clear();
            in.seekg(0);
            found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string stored_cnic, stored_pass;
                getline(ss, stored_cnic, ',');
                getline(ss, stored_pass, ',');

                if (stored_cnic == username && stored_pass == password) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Incorrect password!\n";
                cout << "Press Y to change password or any other key to re-enter: ";
                cin >> check;
                if (toupper(check) == 'Y') {
                    signup();
                    break;
                }
                else {
                    cout << "Please enter password again: ";
                }
            }
            else {
                cout << "Login successful!\n";

                interfaces(username);
            }
        } while (!found);

        in.close();
    }
}

void login::signup() {
    cout << "\nSign Up\n" << endl;
    ifstream in(file1);
    ifstream in2(file2);
    string line;
    bool found1 = true, found2 = true, check = false;

    cout << "Enter CNIC: ";
    do {
        cin >> username;
        in2.clear();
        in2.seekg(0);
        found1 = true;

        while (getline(in2, line)) {
            stringstream ss(line);
            string a;
            getline(ss, a, ',');
            if (a == username) {
                found1 = false;
                break;
            }
        }

        in.clear();
        in.seekg(0);
        found2 = true;
        while (getline(in, line)) {
            stringstream ss(line);
            string col1, col2, col3, col4, col5, col6, col7;
              
            getline(ss, col1, ',');
            getline(ss, col2, ',');
            getline(ss, col3, ',');
            getline(ss, col4, ',');
            getline(ss, col5, ',');
            getline(ss, col6, ',');
            getline(ss, col7, ',');

            if (col5 == username) {
                found2 = false;
                dist = col7;
                break;
            }
        }

        if (found2) {
            cout << "CNIC not found in records!\n";
            cout << "Enter again CNIC: ";
        }
    } while (found2);

    in2.close();

    if (!found1) {
        cout << "Enter new password (min 8 chars): ";
        do {
            cin >> password;
            if (password.length() >= 8) {
                check = true;
            }
            else {
                cout << "Password must be at least 8 characters. Try again: ";
            }
        } while (!check);

        ifstream in3(file2);
        if (!in3) {
            cerr << "Error: Cannot open login file\n";
            return;
        }

        stringstream updated_content;
        bool user_found = false;

        while (getline(in3, line)) {
            stringstream ss(line);
            string a, b, c, d, e, col1, col2;
            getline(ss, a, ',');
            getline(ss, b, ',');
            getline(ss, c, ',');
            getline(ss, d, ',');
            getline(ss, e, ',');
            getline(ss, col1, ',');

            if (a == username) {
                updated_content << a << "," << password << "," << c << "," << d << "," << e << "," << col1 << "\n";
                user_found = true;
            }
            else {
                updated_content << line << "\n";
            }
        }
        in3.close();

        if (!user_found) {
            cout << "Username not found.\n";
            return;
        }

        ofstream out(file2, ios::trunc);  
        if (!out) {
            cerr << "Error: Cannot update login file (Permission denied?)\n";
            return;
        }
        out << updated_content.str();
        out.close();

        cout << "Password updated successfully.\n";
    }

    if (found1 && !found2) {
        ofstream out(file2, ios::app);
        cout << "Enter password (min 8 chars): ";
        do {
            cin >> password;
            if (password.length() >= 8) {
                check = true;
            }
            else {
                cout << "Password must be at least 8 characters. Try again: ";
            }
        } while (!check);

        out << username << "," << password << "," << "false" << "," << "false" << "," << "false" << "," << dist << endl;
        out.close();
        cout << "Account created successfully.\n";
    }

    in.close();
}