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

	bool checkBalance(int *array, int *size) {
		int lsum = 0;
		int rsum;
		int i = 0;
		do {
			lsum += *(array + i);
			rsum = 0;
			for (int j = i + 1; j < *size; j++) 
				rsum += *(array + j);
			i++;
		} while (lsum != rsum && i < *size);
		return (lsum == rsum);
	}

	void shiftArray(int *array, int *size, int *offset) {
		if (*offset == 0)
			return;

		if (*offset > 0) {
			int i = *size;
			int tmp = *(array + --i);
			while (i) {
				*(array + i) = *(array + (i - 1));
				i--;
			}
			*array = tmp;
			--(*offset);
			shiftArray(array, size, offset);
		} else {
			int i = 0;
			int tmp = *(array);
			while (i < *size) {
				*(array + i) = *(array + (i + 1));
				i++;
			}
			*(array + *size - 1) = tmp;
			++(*offset);
			shiftArray(array, size, offset);
		}
	}
}
