#include "main.h"
#include "lib.cpp"
using namespace MyLib;

int main(int argc, char **args) {
	// Task 5
	int arsize = 10;
	int array[arsize] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
	reverseArray(array, &arsize);
	
	// Task 2
	arsize = 8;
	int emptyarray[arsize] = {0};
	changeArray(emptyarray, &arsize);
	
	return SUCCESS;
}
