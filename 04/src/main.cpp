#include <main.h>
using namespace std;

const int val1 = 10;
const int val2 = 5;

bool is_summ_valid(int* p_a, int* p_b) {
	// Return true if a + b is in range from 10 to 20 inclusive
	int sum;
	sum = *p_a + *p_b;
	return (sum >= 10 && sum <= 20);
}

bool is_number_prime(int* p_a) {
	if (*p_a == 2 || *p_a == 3 || *p_a == 5 || *p_a == 7 || *p_a == 11)
		return true;
	if (*p_a % 2 == 0 || *p_a % 3 == 0 || *p_a % 5 == 0 || *p_a % 7 == 0 || *p_a % 11 == 0)
		return false;
	for (int i = 2; i < *p_a; i++)
		if (*p_a % i == 0)
			return false;
	return true;
}

int main(int argc, char** args) {
	// 1. Check that the sum of two digits is in range from [10 ... 20]
	int a, b;
	cout << "Check that the sum of two digits is in range from 10 to 20" << endl;
	do {
		cout << "Enter the first number in range from 1 to 20: ";
		cin >> a;
	} while (a < 1 || a > 20);

	do {
		cout << "Enter the second number in range from 1 to 20: ";
		cin >> b;
	} while (b < 1 || b > 20);
	is_summ_valid(&a, &b) ? cout << "The summ is in range" : cout << "The sum is out of range";
	cout << endl << endl;
	
	// 2. Check that the entered number is a prime
	a = 0;
	cout << "Check that the entered number is a prime" << endl;
	do {
		cout << "Enter the number in range from 1 to 1000: ";
		cin >> a;
	} while (a < 1 || a > 1000);
	is_number_prime(&a) 
		? cout << "The number is a prime" 
		: cout << "The number is not a prime";
	cout << endl <<endl;

	// 3. Print "True" if one of the constants or their sum are equal to 10
	cout << "Defined constants are: " << val1 << " " << val2 << endl;
	(val1 == 10 || val2 == 10 || val1 + val2 == 10) 
		? cout << "Either one of the constants or the sum is equal to 10" 
		: cout << "Neither constants nor their sum are equal to 10";
	cout << endl;

	// Check that the entered year is a leap year
	cout << "Check that entered year is a leap year" << endl;
	int year;
	do {
		cout << "Enter the year from 0 to 3000 AD: "; 
		cin >> year;
	} while (year < 0 || year > 3000);
	((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	 	? cout << "This is the leap year"
		: cout << "This year is not leap";
	cout << endl;
	return SUCCESS;
}
