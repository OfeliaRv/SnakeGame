#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver = false;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1;i++) cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0;j < width;j++) {
			if (j == 0 || j == width - 1) cout << "#";
			if (i == y && j == x) cout << "0";
			else if (i == fruitY && j == fruitX) cout << "F";
			else cout << " ";
		}

		cout << endl;
	}

	for (int i = 0; i < width + 1;i++) cout << "#";
	cout << endl;
}

void Logic() {

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
}

void Input() {
	if (_kbhit) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
			break;

		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}


int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Logic();
		Input();
	}
	return 0;
}

