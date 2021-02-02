#include "main.h"
#include "board.h"

using namespace std;

Square board[SIZE][SIZE] = {E};
// Init board with empty Values

void print_board() {
	for(int r = 0; r < SIZE; r++) {
		for(int c = 0; c < SIZE; c++)
			cout << board[r][c].content;
		cout << endl;
	}
}

void evaluate_union() {
	typedef union example_U {
		int i;
		char c;
		float f;
	} Example_U;

	typedef struct my_struct {
		Example_U var;
		int is_int		: 1;
		int is_char		: 1;
		int is_float	: 1;
	} My_struct;

	My_struct testVar;
	testVar.var.i = 10;
	testVar.is_int = 1;
	cout << "Var is Int: " << testVar.var.i << endl;

	testVar.var.c = 'A';
	testVar.is_char = 1;
	cout << "Var is Char: " << testVar.var.c << endl;

	testVar.var.f = 9.999; 
	testVar.is_float = 1;
	cout << "Var is Float: " << testVar.var.f << endl;
}


int main(int argc, char** args) {
	print_board();
	evaluate_union();
	return SUCCESS;
}
