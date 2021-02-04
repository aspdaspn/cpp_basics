#include <main.h>
using namespace std;

bool is_summ_valid(int* p_a, int* p_b) {
	// Return true if a + b is in range from 10 to 20 inclusive
	int sum;
	sum = *p_a + *p_b;
	return (sum >= 10 & sum <= 20);
}

bool is_number_prime(int* p_a) {
	if (*p_a % 2 == 0)
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
		cout << "Enter the first number in range from 1 to 10: ";
		cin >> a;
	} while (a < 1 || a > 10);

	do {
		cout << "Enter the second number in range from 1 to 10: ";
		cin >> b;
	} while (b < 1 || b > 10);
	is_summ_valid(&a, &b) ? cout << "The summ is in range" : cout << "The sum is out of range";
	cout << endl << endl;
	
	// 2. Check that the entered number is a prime
	a = 0;
	cout << "Check that the entered number is a prime" << endl;
	do {
		cout << "Enter the number in range from 1 to 1000: ";
		cin >> a;
	} while (a < 1 || a > 1000);
	is_number_prime(&a) ? cout << "The number is a prime" : cout << "The number is not a prime";
	cout << endl <<endl;
	return SUCCESS;
}
