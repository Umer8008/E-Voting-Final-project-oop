#include "login.h"
#include "candidate.h"
#include "ELECTION.h"

int main()
{
	cout << "\033[41m";
	cout << "\t\t\t\t\t\t                         " << endl;
	cout << "\t\t\t\t\t\t     E Voting System     \n";
	cout << "\t\t\t\t\t\t                         \n" << endl;
	cout << "\033[0m";
	login user;
	user.log();
	return 0;
}