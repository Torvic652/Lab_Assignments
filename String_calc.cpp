#include <string>
#include <sstream>
#include <iostream>

using namespace std;
//Function to calculate the sum of numbers in a string separated by commas
int string_calculator(string str) {
	// check for empty string
	if (str.empty()) return 0;
	//replace semicolons with commas
	for (char& c : str) {
		if (c == ';') c = ',';
	}

	int sum = 0;
	//easily extract parts of the string using stringstream
	stringstream ss(str);
	string token;
	//loops through the string at each comma
	while (getline(ss, token, ',')) {
		// if token empty it adds to the sum
		if (!token.empty()) {
			//convert token to integer and add to the sum
			sum += stoi(token);
		}

	}
	return sum;
}

int main() {
	cout << string_calculator("") << endl;
	cout << string_calculator("0") << endl;
	cout << string_calculator("1") << endl;
	cout << string_calculator("1,2") << endl;
	cout << string_calculator("4,5,6") << endl;


}