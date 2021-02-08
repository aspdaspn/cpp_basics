// External libraries file
#include "main.h"

namespace MyLib {
	void printArray(int *array, int *size) {
		for (int i = 0; i < *size; i++)
			std::cout << *(array + i) << " ";
		std::cout << std::endl;
	 }
	
	void reverseArray(int *array, int *size) {
		std::cout << "Initial array: " << std::endl;
		printArray(array, size);
		for (int i = 0; i < *size; i++) 
			if (*(array + i) == 1)
				*(array + i) = 0;
			else 
				*(array + i) = 1;
		std::cout << "Reversed array: " << std::endl;
		printArray(array, size);
	}

	void changeArray(int *array, int *size) {
		for(int i = 0; i < *size; i++)
			*(array + i) = i * 3 + 1;
		printArray(array, size);
	}
}
