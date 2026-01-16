#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;
//function that passes string to the password variable and checks if at least 8 characters long.
void validatePassword(const string& password) {
	assert(password.length() >= 8 && "Password must be at least 8 characters long.");
	//create variables 
	int digitcount = 0;
	int capitalcount =  0;
	int specialcount = 0;
	//loop through each character in the password for requirements
	for (char ch : password) {
		if (isdigit(ch)) {
			digitcount++;
		}
		else if (isupper(ch)) {
			capitalcount++;
		}
		else if (!isalnum(ch)) {
			specialcount++;
		}
	}
	//check to meet requirements if not message will show
	assert(digitcount >= 2 && "Password must contain at least 2 digits.");
	assert(capitalcount >= 1 && "Password must contain at least 1 uppercase letter.");
	assert(specialcount >= 1 && "Password must contain at least 1 special character.");
}

int main() {
	string password;
	cout << "Enter a password to validate: ";
	getline(cin, password);
	//call function to validate password
	validatePassword(password);
	cout << "Password is valid." << endl;
	return 0;

}
