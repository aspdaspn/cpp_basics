#include <main.h>

#define CHECK_DOT(X, Z) (((X) >= 0) && ((X) < (Z)))
#define POINT_ITEM(a, r, c) (*(*((a) + (r)) + (c)))

enum PLAYER {HUMAN = 'X', AI = 'O', EMPTY = '_'};

typedef struct {
	int szX;
	int szY;
	PLAYER **map;
	int toWin;
} Field;

char getVal(PLAYER **array, const int row, const int col) {
	return POINT_ITEM(array, row, col);
}

void setVal(PLAYER **array, const int row, const int col, PLAYER value) {
	POINT_ITEM(array, row, col) = value;
}

void init(Field &field) {
	int s = 0;
	int n = 0;
	do {
		std::cout << "Enter field size: ";
		scanf("%d", &s);
		std::cout << "Enter the number of symbols in line to win: ";
		scanf("%d", &n);
	} while (n > s);
	field.toWin = n;
	field.szX = s;
	field.szY = s;
	field.map = (PLAYER **) calloc(field.szX, sizeof(PLAYER *));
	for (int y = 0; y < field.szY; y++) {
		*(field.map + y) = (PLAYER *) calloc(field.szX, sizeof(PLAYER));
		for (int x = 0; x < field.szX; x++)
			setVal(field.map, y, x, EMPTY);
	}
	std::cin.ignore();
}

void print(Field &field) {
	std::system("clear");
	for (int i = 0; i < field.szX; i++)
		std::cout << "-" << i + 1;
	std::cout << "-\n";
	for (int y = 0; y < field.szY; y++) {
		std::cout << (y + 1);
		for (int x = 0; x < field.szX; x++)
			std::cout << getVal(field.map, y, x) << "|";
		std::cout << std::endl;
	}
}

bool isEmpty(Field &field, int x, int y) {
	return getVal(field.map, y, x) == EMPTY;
}

bool isValid(Field &field, int x, int y) {
	return CHECK_DOT(x, field.szX) && CHECK_DOT(y, field.szY);
}

void humanTurn(Field &field) {
	int x;
	int y;
	std::string input;
	bool isError = false;
	std::regex r("(\\d).*(\\d)");
	do {
		if (isError)
			std::cout << "Incorrect input!\n";
		std::cout << "Enter coordinates X and Y, divided by space: \n";
		std::getline(std::cin, input);
		std::smatch sm;
		std::regex_match(input, sm, r);
		x = std::atoi(sm[1].str().c_str());
		y = std::atoi(sm[2].str().c_str());
		x--; y--;
		isError = true;
	} while(!isValid(field, x, y) || !isEmpty(field, x, y));
	setVal(field.map, y, x, HUMAN);
}

bool isDraw(Field &field) {
	for (int y = 0; y < field.szY; y++)
		for (int x = 0; x < field.szX; x++)
			if (isEmpty(field, x, y))
				return false;
	return true;
}

bool checkLine(Field &field, int y, int x, int vx, int vy, int len, PLAYER c) {
	const int endX = x + (len - 1) * vx;
	const int endY = y + (len - 1) * vy;
	if (!isValid(field, endX, endY))
		return false;
	for (int i = 0; i < len; i++) {
		if (getVal(field.map, (y + i * vy), (x + i * vx)) != c) 
			return false;
	}
	return true;
}

bool checkWin(Field &field, PLAYER c) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (getVal(field.map, y, x) == EMPTY)
				continue;
			if (checkLine(field, y, x, 1, 0, field.toWin, c)) return true;
			if (checkLine(field, y, x, 1, 1, field.toWin, c)) return true;
			if (checkLine(field, y, x, 0, 1, field.toWin, c)) return true;
			if (checkLine(field, y, x, 1, -1, field.toWin, c)) return true;
		}
	}
	return false;
}

bool aiWinCheck(Field &field) {
	for (int y = 0; y < field.szY; y++) 
		for (int x = 0; x < field.szX; x++)
			if (isEmpty(field, x, y)) {
				setVal(field.map, y, x, AI);
				if (checkWin(field, AI))
					return true;
				setVal(field.map, y, x, EMPTY);
			}
	return false;
}

bool humanWinCheck(Field &field) {
	for (int y = 0; y < field.szY; y++) 
		for (int x = 0; x < field.szX; x++)
			if (isEmpty(field, x, y)) {
				setVal(field.map, y, x, HUMAN);
				if (checkWin(field, HUMAN)) {
					setVal(field.map, y, x, AI);
					return true;
				}
				setVal(field.map, y, x, EMPTY);
			}
	return false;
}

bool desireToWin(Field &field) {
	int nx;
	int ny;
	for (int y = 0; y < field.szY; y++)
		for (int x = 0; x < field.szX; x++)
			if (getVal(field.map, y, x) == AI)
				while (true) {
					nx = rand() % (field.toWin * 2) - field.toWin;
					ny = rand() % (field.toWin * 2) - field.toWin;
					if (isValid(field, x + nx, y + ny) && isEmpty(field, x + nx, y + ny)) {
						setVal(field.map, x + nx, y + ny, AI);
						return true;
					}
				}
	return false;
}

void aiTurn(Field &field) {
	if (aiWinCheck(field)) return;
	if (humanWinCheck(field)) return;
	if (desireToWin(field)) return;
	int x;
	int y;
	do {
		x = rand() % (field.szX);
		y = rand() % (field.szY);
	} while (!isEmpty(field, x, y));
	setVal(field.map, y, x, AI);
}

bool gameCheck(Field &field, PLAYER c, const std::string &winString) {
	print(field);
	if (checkWin(field, c)) {
		std::cout << winString << "\n";
		return true;
	}
	if (isDraw(field)) {
		std::cout << "Draw!\n";
		return true;
	}
	return false;
}

int main(int argc, char** args) {
	srand(time(NULL));
	Field field;
	init(field);
	print(field);
	while (true) {
		humanTurn(field);
		if (gameCheck(field, HUMAN, "Human wins!"))
			break;
		aiTurn(field);
		if (gameCheck(field, AI, "Computer wins!"))
			break;
	}
	return SUCCESS;
}
