#include "main.h"
#include "lib.cpp"
using namespace MyLib;

int main(int argc, char **args) {
	// Task 1
	int arsize = 10;
	int array[arsize] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
	std::cout << "Task 5, reverce the array" << std::endl;
	reverseArray(array, &arsize);
	
	// Task 2
	arsize = 8;
	int emptyarray[arsize] = {0};
	std::cout << "Array from Task 2:" << std::endl;
	changeArray(emptyarray, &arsize);

	// Task 3 + 6
	arsize = 10;
	int balancearray[arsize] = {10, 0, 1, 0, 2, 0, 3, 0, 4, 0};
	bool (*p_cB) (int*, int*);
	p_cB = checkBalance;
	std::cout << "Task 3, check if array is balanced" << std::endl;
	printArray(balancearray, &arsize);
	(*p_cB)(balancearray, &arsize) ? std::cout << "The array is balanced" << std::endl : std::cout << "The arryy is not balanced" << std::endl;

	// Task 4
	arsize = 10;
	int offset = -3;
	int cyclearray[arsize] = {3, 2, 1, 4, 7, 6, 5, 9, 0, 8};
	std::cout << "Task 4, move values inside the array" << std::endl;
	printArray(cyclearray, &arsize);
	shiftArray(cyclearray, &arsize, &offset);
	printArray(cyclearray, &arsize);

	// Task 5
	reverseArguments(5, 1, 1, 0, 0, 1); 
	return SUCCESS;
}
