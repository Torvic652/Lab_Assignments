#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Returns "Fizz" if x divisible by 3, "Buzz" if divisible by 5, "FizzBuzz" if divisible by both, else the number as string
string FizzBuzz(int x) {
    if (x % 15 == 0 && x != 0) {
        return "FizzBuzz";
    }
    else if (x % 3 == 0 && x != 0) {
        return "Fizz";
    }
    else if (x % 5 == 0 && x != 0) {
        return "Buzz";
    }
    else {
        return to_string(x);
    }
}

int main() {
    // Test for Fizz
    assert(FizzBuzz(3) == "Fizz");
    assert(FizzBuzz(6) == "Fizz");
    assert(FizzBuzz(9) == "Fizz");
    assert(FizzBuzz(-3) == "Fizz");

    for (int i = -12; i <= 12; i += 3) {
        if (i != 0 && i % 15 != 0) {
            assert(FizzBuzz(i) == "Fizz");
        }
    }

    // Test for Buzz
    assert(FizzBuzz(5) == "Buzz");
    assert(FizzBuzz(10) == "Buzz");
    assert(FizzBuzz(-5) == "Buzz");

    for (int i = -10; i <= 10; i += 5) {
        if (i != 0 && i % 15 != 0) {
            assert(FizzBuzz(i) == "Buzz");
        }
    }

    // Test for FizzBuzz
    assert(FizzBuzz(15) == "FizzBuzz");
    assert(FizzBuzz(-15) == "FizzBuzz");

    // Test for numbers not divisible by 3 or 5
    assert(FizzBuzz(1) == "1");
    assert(FizzBuzz(2) == "2");
    assert(FizzBuzz(4) == "4");

    // Optional: Test for zero
    assert(FizzBuzz(0) == "0");

    cout << "All tests passed!" << endl;
    return 0;
}