#define SIZE 3
// Board size is a square of SIZE

enum t_square{O, X, E};
// Square content: 0(O), 1(X) or 2(Empty)

typedef struct s_square {
	t_square content;
} Square;
