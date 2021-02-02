#include <main.h>

using namespace std;
extern const int a, b, c, d;
float r;

int main(int argc, char** args) {
	r = (float) (a * (b + (c / d)));
	printf("%i * (%i + (%i / %i)) = %.2f\n", a, b, c, d, r);
	
	int value = 24;
	printf("Your value = %i, result: %i\n", value, (value > 21) ? (value - 21)*2 : (21 - value));
	value = 13;
	printf("Your value = %i, result: %i\n", value, (value > 21) ? (value - 21)*2 : (21 - value));
	return SUCCESS;
}

