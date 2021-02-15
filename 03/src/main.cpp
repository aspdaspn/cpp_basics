#include <main.h>

using namespace std;
extern const int a, b, c, d;
float r;

void pointer_to_array() {
	int ar[3][3][3], *p_ar;
	p_ar = &ar[1][1][1];
	int c = 0;
	printf("Address of an element: %p\n", p_ar);
	printf("Content of an element: %i\n", *p_ar);
	for (int l = 0; l < 3; l++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				ar[l][y][x] = ++c;
	printf("New address of an element: %p\n", p_ar);
	printf("New content of an element: %i\n", *p_ar);
	// added array output with dereferencing 
	cout << "With dereferencing, element is: " << *(*(*(ar + 1) + 1) + 1) << endl;
	cout << "With dereferencing, address is: " << &*(*(*(ar + 1) + 1) + 1) << endl;
	return;
}

int main(int argc, char** args) {
	// 1
	r = a * (b + ((float) c / d));
	printf("%i * (%i + (%i / %i)) = %.2f\n", a, b, c, d, r);
	
	// 2
	int value = 24;
	printf("Your value = %i, result: %i\n", value, (value > 21) ? (value - 21)*2 : (21 - value));
	value = 13;
	printf("Your value = %i, result: %i\n", value, (value > 21) ? (value - 21)*2 : (21 - value));
	
	// 3
	pointer_to_array();
	return SUCCESS;
}

