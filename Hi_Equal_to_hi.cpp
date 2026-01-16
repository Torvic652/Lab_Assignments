#include <iostream>
#include <cctype>
#include <string>
using namespace std;
//function and variables 
int strcmp_case_intensitive(const string& s1, const string& s2) {
    //i used as a loop to iterate throughout the characters
    size_t i = 0;
    //while loop to compare s1 and s2 to i after converting them to lowercase
    while (i < s1.length() && i < s2.length()) {
        //ensure is always a non negative number
        char c1 = tolower(static_cast<unsigned char>(s1[i]));
        char c2 = tolower(static_cast<unsigned char>(s2[i]));
        if (c1 != c2) {

            return (c1 < c2) ? -1 : 1;
        }
        ++i;
    }
    if (s1.length() == s2.length()) return 0;
    return (s1.length() < s2.length()) ? -1 : 1;
}
//Testing function
void test(const string& s1, const string s2, int expected) {

    //expected outcome from first function
    int result = strcmp_case_intensitive(s1, s2);
    cout << "Comparing \"" << s1 << "\" and \"" << s2 << "\" =>" << result << "\n";
    if (result == expected) {

        cout << "[PASS]\n";
    }
    else {
        cout << "[FAIL] (Expected) : " << expected << ")";

    }
    cout << endl;
}


int main() {
    // Identical strings
    test("Hello", "Hello", 0);
    // Different case, same letters
    test("Hello", "hello", 0);
    // s1 < s2
    test("abc", "abd", -1);
    // s1 > s2
    test("abd", "abc", 1);
    // s1 shorter, prefix
    test("abc", "abcd", -1);
    // s2 shorter, prefix
    test("abcd", "abc", 1);
    // Empty strings
    test("", "", 0);
    test("", "a", -1);
    test("a", "", 1);
    // Special characters
    test("Hello!", "hello!", 0);
    test("Hello!", "hello?", -1);
    
    return 0;
}