#include <iostream>
#include <chrono>

using namespace std;

// **** function prototype ****
long fibonacci0(long number);
long fibonacci(long number);


// **** memoization ****
long memo[50]{ 0 };


/*
*
*/
int main() {

    // **** start timer ****
    auto start = std::chrono::steady_clock::now();

    // **** calculate the fibonacci values of 0 through 10 ****
    for (int counter{ 0 }; counter <= 10; ++counter)
        cout << "main <<< fibonacci0(" << counter << "): " << fibonacci0(counter) << endl;
    cout << endl;

    // **** display higher fibonacci values **** 
    cout << "main <<< fibonacci0(20): " << fibonacci0(20) << endl;
    cout << "main <<< fibonacci0(25): " << fibonacci0(25) << endl;
    cout << "main <<< fibonacci0(30): " << fibonacci0(30) << endl;
    cout << "main <<< fibonacci0(35): " << fibonacci0(35) << endl;
    cout << "main <<< fibonacci0(40): " << fibonacci0(40) << endl;
    cout << "main <<< fibonacci0(45): " << fibonacci0(45) << endl;

    // **** end timer ****
    auto end = std::chrono::steady_clock::now();

    // **** compute and display elapsed time in seconds ****
    chrono::duration<double> elapsed = end - start;
    cout << "main <<< elapsed: " << elapsed << endl << endl;

    // **** initialize memoization array ****
    memset(memo, 0, sizeof(memo) / sizeof(long));

    // **** start timer ****
    start = std::chrono::steady_clock::now();

    // **** calculate the fibonacci values of 0 through 10 ****
    for (int counter{ 0 }; counter <= 10; ++counter)
        cout << "main <<< fibonacci(" << counter << "): " << fibonacci(counter) << endl;
    cout << endl;

    // **** display higher fibonacci values **** 
    cout << "main <<< fibonacci(20): " << fibonacci(20) << endl;
    cout << "main <<< fibonacci(25): " << fibonacci(25) << endl;
    cout << "main <<< fibonacci(30): " << fibonacci(30) << endl;
    cout << "main <<< fibonacci(35): " << fibonacci(35) << endl;
    cout << "main <<< fibonacci(40): " << fibonacci(40) << endl;
    cout << "main <<< fibonacci(45): " << fibonacci(45) << endl;

    // **** end timer ****
    end = std::chrono::steady_clock::now();

    // **** compute and display elapsed time in seconds ****
    elapsed = end - start;
    cout << "main <<< elapsed: " << elapsed << endl;
}


/*
* Recursive function finonacci NOT using memoization.
*/
long fibonacci0(long number) {

    // **** base case ****
    if ((number == 0) || (number == 1))
        return number;

    // **** return fibonacci number ****
    return fibonacci0(number - 2) + fibonacci0(number - 1);
}


/*
* Recursive function fibonacci using memoization.
*/
long fibonacci(long number) {

    // **** base case ****
    if ((number == 0) || (number == 1)) {
        memo[number] = number;
        return number;
    }

    // **** initialization ****
    long fib = 0;

    // **** recursive step for number - 2 ****
    if (memo[number - 2] != 0)
        fib = memo[number - 2];
    else {
        memo[number - 2] = fibonacci(number - 2);
        fib = memo[number - 2];
    }

    // **** recursive step for number - 1 ****
    if (memo[number - 1] != 0)
        fib += memo[number - 1];
    else {
        memo[number - 1] = fibonacci(number - 1);
        fib += memo[number - 1];
    }

    // **** return fibonacci number ****
    return fib;
}