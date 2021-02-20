#include <main.h>

// Task 1
#define INRANGE(a, b) (((a) >= 0) && ((a) < (b)))

// Task 2
#define ARRAYACCESS(a, x, y) (**(a + x) + (y))

// Task 3
#define ARRAYQUANTITY(a, type) (sizeof(a) / sizeof(type))

int main(int argc, char** args) {
	// Task 1
	std::cout << INRANGE(23, 3) << std::endl;
	
	// Task 2
	int array[2][3] = {{1, 2, 3},
										 {4, 5, 6}};
	std::cout << ARRAYACCESS(array, 1, 2) << std::endl;
	// Task 3
	std::cout << ARRAYQUANTITY(array, int) << std::endl;

	return SUCCESS;
}
