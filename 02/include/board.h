#define SIZE 3
// Board size is a square of SIZE

enum t_square{E, X, O};
// Square content: 0(Empty), 1(X) or 2(O)

typedef struct s_square {
	t_square content;
} Square;
