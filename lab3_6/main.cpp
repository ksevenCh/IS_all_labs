#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Поворот правой грани против часовой
int*** rightAntiClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[4][0][1] = cube[4][1][0];
	temp[4][1][0] = cube[4][2][1];
	temp[4][2][1] = cube[4][1][2];
	temp[4][1][2] = cube[4][0][1];

	temp[4][0][0] = cube[4][2][0];
	temp[4][2][0] = cube[4][2][2];
	temp[4][2][2] = cube[4][0][2];
	temp[4][0][2] = cube[4][0][0];

	temp[0][0][2] = cube[3][0][2];
	temp[0][1][2] = cube[3][1][2];
	temp[0][2][2] = cube[3][2][2];

	temp[3][0][2] = cube[5][0][2];
	temp[3][1][2] = cube[5][1][2];
	temp[3][2][2] = cube[5][2][2];

	temp[5][0][2] = cube[1][0][2];
	temp[5][1][2] = cube[1][1][2];
	temp[5][2][2] = cube[1][2][2];

	temp[1][0][2] = cube[0][0][2];
	temp[1][1][2] = cube[0][1][2];
	temp[1][2][2] = cube[0][2][2];

	return temp;
}

// Поворот правой грани по часовой
int*** rightClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[4][0][1] = cube[4][1][2];
	temp[4][1][0] = cube[4][0][1];
	temp[4][2][1] = cube[4][1][0];
	temp[4][1][2] = cube[4][2][1];

	temp[4][0][0] = cube[4][0][2];
	temp[4][2][0] = cube[4][0][0];
	temp[4][2][2] = cube[4][2][0];
	temp[4][0][2] = cube[4][2][2];

	temp[0][0][2] = cube[1][0][2];
	temp[0][1][2] = cube[1][1][2];
	temp[0][2][2] = cube[1][2][2];

	temp[3][0][2] = cube[0][0][2];
	temp[3][1][2] = cube[0][1][2];
	temp[3][2][2] = cube[0][2][2];

	temp[5][0][2] = cube[3][0][2];
	temp[5][1][2] = cube[3][1][2];
	temp[5][2][2] = cube[3][2][2];

	temp[1][0][2] = cube[5][0][2];
	temp[1][1][2] = cube[5][1][2];
	temp[1][2][2] = cube[5][2][2];

	return temp;
}

int*** upClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[0][0][1] = cube[0][1][2];
	temp[0][1][0] = cube[0][0][1];
	temp[0][2][1] = cube[0][1][0];
	temp[0][1][2] = cube[0][2][1];

	temp[0][0][0] = cube[0][0][2];
	temp[0][2][0] = cube[0][0][0];
	temp[0][2][2] = cube[0][2][0];
	temp[0][0][2] = cube[0][2][2];

	temp[2][0][0] = cube[1][0][0];
	temp[2][1][0] = cube[1][1][0];
	temp[2][2][0] = cube[1][2][0];

	temp[3][0][0] = cube[2][0][0];
	temp[3][1][0] = cube[2][1][0];
	temp[3][2][0] = cube[2][2][0];

	temp[4][0][0] = cube[3][0][0];
	temp[4][1][0] = cube[3][1][0];
	temp[4][2][0] = cube[3][2][0];

	temp[1][0][0] = cube[4][0][0];
	temp[1][1][0] = cube[4][1][0];
	temp[1][2][0] = cube[4][2][0];

	return temp;
}

int*** upAntiClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[0][0][1] = cube[0][1][0];
	temp[0][1][0] = cube[0][2][1];
	temp[0][2][1] = cube[0][1][2];
	temp[0][1][2] = cube[0][0][1];

	temp[0][0][0] = cube[0][2][0];
	temp[0][2][0] = cube[0][2][2];
	temp[0][2][2] = cube[0][0][2];
	temp[0][0][2] = cube[0][0][0];

	temp[2][0][0] = cube[3][0][0];
	temp[2][1][0] = cube[3][1][0];
	temp[2][2][0] = cube[3][2][0];

	temp[3][0][0] = cube[4][0][0];
	temp[3][1][0] = cube[4][1][0];
	temp[3][2][0] = cube[4][2][0];

	temp[4][0][0] = cube[1][0][0];
	temp[4][1][0] = cube[1][1][0];
	temp[4][2][0] = cube[1][2][0];

	temp[1][0][0] = cube[2][0][0];
	temp[1][1][0] = cube[2][1][0];
	temp[1][2][0] = cube[2][2][0];

	return temp;
}

int*** leftClock(int*** cube)
{
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}




	temp[2][0][1] = cube[2][1][0];
	temp[2][1][0] = cube[2][2][1];
	temp[2][2][1] = cube[2][1][2];
	temp[2][1][2] = cube[2][0][1];

	temp[2][0][0] = cube[2][2][0];
	temp[2][2][0] = cube[2][2][2];
	temp[2][2][2] = cube[2][0][2];
	temp[2][0][2] = cube[2][0][0];

	temp[0][0][0] = cube[3][0][0];
	temp[0][1][0] = cube[3][1][0];
	temp[0][2][0] = cube[3][2][0];

	temp[3][0][0] = cube[5][0][0];
	temp[3][1][0] = cube[5][1][0];
	temp[3][2][0] = cube[5][2][0];

	temp[5][0][0] = cube[1][0][0];
	temp[5][1][0] = cube[1][1][0];
	temp[5][2][0] = cube[1][2][0];

	temp[1][0][0] = cube[0][0][0];
	temp[1][1][0] = cube[0][1][0];
	temp[1][2][0] = cube[0][2][0];

	return temp;
}

int*** leftAntiClock(int*** cube)
{
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[2][0][1] = cube[2][1][2];
	temp[2][1][0] = cube[2][0][1];
	temp[2][2][1] = cube[2][1][0];
	temp[2][1][2] = cube[2][2][1];

	temp[2][0][0] = cube[2][0][2];
	temp[2][2][0] = cube[2][0][0];
	temp[2][2][2] = cube[2][2][0];
	temp[2][0][2] = cube[2][2][2];

	temp[0][0][0] = cube[1][0][0];
	temp[0][1][0] = cube[1][1][0];
	temp[0][2][0] = cube[1][2][0];

	temp[3][0][0] = cube[0][0][0];
	temp[3][1][0] = cube[0][1][0];
	temp[3][2][0] = cube[0][2][0];

	temp[5][0][0] = cube[3][0][0];
	temp[5][1][0] = cube[3][1][0];
	temp[5][2][0] = cube[3][2][0];

	temp[1][0][0] = cube[5][0][0];
	temp[1][1][0] = cube[5][1][0];
	temp[1][2][0] = cube[5][2][0];

	return temp;
}

int*** downClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[5][0][1] = cube[5][1][0];
	temp[5][1][0] = cube[5][2][1];
	temp[5][2][1] = cube[5][1][2];
	temp[5][1][2] = cube[5][0][1];

	temp[5][0][0] = cube[5][2][0];
	temp[5][2][0] = cube[5][2][2];
	temp[5][2][2] = cube[5][0][2];
	temp[5][0][2] = cube[5][0][0];

	temp[2][0][2] = cube[3][0][2];
	temp[2][1][2] = cube[3][1][2];
	temp[2][2][2] = cube[3][2][2];

	temp[3][0][2] = cube[4][0][2];
	temp[3][1][2] = cube[4][1][2];
	temp[3][2][2] = cube[4][2][2];

	temp[4][0][2] = cube[1][0][2];
	temp[4][1][2] = cube[1][1][2];
	temp[4][2][2] = cube[1][2][2];

	temp[1][0][2] = cube[2][0][2];
	temp[1][1][2] = cube[2][1][2];
	temp[1][2][2] = cube[2][2][2];

	return temp;
}

int*** downAntiClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[5][0][1] = cube[5][1][2];
	temp[5][1][0] = cube[5][0][1];
	temp[5][2][1] = cube[5][1][0];
	temp[5][1][2] = cube[5][2][1];

	temp[5][0][0] = cube[5][0][2];
	temp[5][2][0] = cube[5][0][0];
	temp[5][2][2] = cube[5][2][0];
	temp[5][0][2] = cube[5][2][2];

	temp[2][0][2] = cube[1][0][2];
	temp[2][1][2] = cube[1][1][2];
	temp[2][2][2] = cube[1][2][2];

	temp[3][0][2] = cube[2][0][2];
	temp[3][1][2] = cube[2][1][2];
	temp[3][2][2] = cube[2][2][2];

	temp[4][0][2] = cube[3][0][2];
	temp[4][1][2] = cube[3][1][2];
	temp[4][2][2] = cube[3][2][2];

	temp[1][0][2] = cube[4][0][2];
	temp[1][1][2] = cube[4][1][2];
	temp[1][2][2] = cube[4][2][2];

	return temp;
}

int*** frontClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[1][0][1] = cube[1][1][2];
	temp[1][1][0] = cube[1][0][1];
	temp[1][2][1] = cube[1][1][0];
	temp[1][1][2] = cube[1][2][1];

	temp[1][0][0] = cube[1][0][2];
	temp[1][2][0] = cube[1][0][0];
	temp[1][2][2] = cube[1][2][0];
	temp[1][0][2] = cube[1][2][2];

	temp[0][0][2] = cube[2][0][2];
	temp[0][1][2] = cube[2][1][2];
	temp[0][2][2] = cube[2][2][2];

	temp[4][0][2] = cube[0][0][2];
	temp[4][1][2] = cube[0][1][2];
	temp[4][2][2] = cube[0][2][2];

	temp[5][0][2] = cube[4][0][2];
	temp[5][1][2] = cube[4][1][2];
	temp[5][2][2] = cube[4][2][2];

	temp[2][0][2] = cube[5][0][2];
	temp[2][1][2] = cube[5][1][2];
	temp[2][2][2] = cube[5][2][2];

	return temp;
}

int*** frontAntiClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[1][0][1] = cube[1][1][0];
	temp[1][1][0] = cube[1][2][1];
	temp[1][2][1] = cube[1][1][2];
	temp[1][1][2] = cube[1][0][1];

	temp[1][0][0] = cube[1][2][0];
	temp[1][2][0] = cube[1][2][2];
	temp[1][2][2] = cube[1][0][2];
	temp[1][0][2] = cube[1][0][0];

	temp[5][0][2] = cube[2][0][2];
	temp[5][1][2] = cube[2][1][2];
	temp[5][2][2] = cube[2][2][2];

	temp[2][0][2] = cube[0][0][2];
	temp[2][1][2] = cube[0][1][2];
	temp[2][2][2] = cube[0][2][2];

	temp[0][0][2] = cube[4][0][2];
	temp[0][1][2] = cube[4][1][2];
	temp[0][2][2] = cube[4][2][2];

	temp[4][0][2] = cube[5][0][2];
	temp[4][1][2] = cube[5][1][2];
	temp[4][2][2] = cube[5][2][2];

	return temp;
}

int*** backClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[3][0][1] = cube[3][1][0];
	temp[3][1][0] = cube[3][2][1];
	temp[3][2][1] = cube[3][1][2];
	temp[3][1][2] = cube[3][0][1];

	temp[3][0][0] = cube[3][2][0];
	temp[3][2][0] = cube[3][2][2];
	temp[3][2][2] = cube[3][0][2];
	temp[3][0][2] = cube[3][0][0];

	temp[5][0][0] = cube[2][0][0];
	temp[5][1][0] = cube[2][1][0];
	temp[5][2][0] = cube[2][2][0];

	temp[2][0][0] = cube[0][0][0];
	temp[2][1][0] = cube[0][1][0];
	temp[2][2][0] = cube[0][2][0];

	temp[0][0][0] = cube[4][0][0];
	temp[0][1][0] = cube[4][1][0];
	temp[0][2][0] = cube[4][2][0];

	temp[4][0][0] = cube[5][0][0];
	temp[4][1][0] = cube[5][1][0];
	temp[4][2][0] = cube[5][2][0];

	return temp;
}

int*** backAntiClock(int*** cube) {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[3][0][1] = cube[3][1][2];
	temp[3][1][0] = cube[3][0][1];
	temp[3][2][1] = cube[3][1][0];
	temp[3][1][2] = cube[3][2][1];

	temp[3][0][0] = cube[3][0][2];
	temp[3][2][0] = cube[3][0][0];
	temp[3][2][2] = cube[3][2][0];
	temp[3][0][2] = cube[3][2][2];

	temp[0][0][0] = cube[2][0][0];
	temp[0][1][0] = cube[2][1][0];
	temp[0][2][0] = cube[2][2][0];

	temp[4][0][0] = cube[0][0][0];
	temp[4][1][0] = cube[0][1][0];
	temp[4][2][0] = cube[0][2][0];

	temp[5][0][0] = cube[4][0][0];
	temp[5][1][0] = cube[4][1][0];
	temp[5][2][0] = cube[4][2][0];

	temp[2][0][0] = cube[5][0][0];
	temp[2][1][0] = cube[5][1][0];
	temp[2][2][0] = cube[5][2][0];

	return temp;
}

int*** getCube() {
	int*** temp;
	temp = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}
	return temp;
}

class node {
public:
	int*** curr;
	int prevMove;
	int depthLevel;
	int est_cost;
	node* parent;
	vector<node*> children;

	node() {
		prevMove = 0;
		depthLevel = 0;
		parent = nullptr;
		curr = getCube();
	}

	void setCurrState(int*** c) {
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					curr[i][j][k] = c[i][j][k];
				}
			}
		}
	}

	int*** getCurrState() {
		return this->curr;
	}

	void setprevMove(int move) {
		this->prevMove = move;
	}

	int getprevMove() {
		return this->prevMove;
	}

	void setdepthLevel(int depth) {
		this->depthLevel = depth;
	}

	int getdepthLevel() {
		return this->depthLevel;
	}

	void setParent(node* p) {
		this->parent = p;
	}

	node* getParent() {
		this->parent;
	}

	void addChild(node* c)
	{
		this->children.push_back(c);
	}

};

struct prioritize
{
	bool operator()(const node* p1, const node* p2) const
	{
		return (p1->depthLevel + p1->est_cost) > (p2->est_cost + p2->depthLevel);
	}
};

// Эвристика 1: количество неправильных элементов
int heuristic1(int*** cube) {
	int incorrect = 0;
	for (int i = 0; i < 6; i++) {
		int color = cube[i][0][0];
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (cube[i][j][k] != color) {
					incorrect++;
				}
			}
		}
	}
	return incorrect;
}

enum Colors { U = 0, F = 1, L = 2, B = 3, R = 4, D = 5 };

int correctCorners[8][3] = {
	{U, L, F}, {U, F, R}, {U, R, B}, {U, B, L}, // Верхние углы
	{D, L, B}, {D, B, R}, {D, R, F}, {D, F, L}  // Нижние углы
};

int correctEdges[12][2] = {
	{U, F}, {U, L}, {U, R}, {U, B}, // Верхние рёбра
	{D, F}, {D, L}, {D, R}, {D, B}, // Нижние рёбра
	{F, L}, {F, R}, {B, L}, {B, R}  // Боковые рёбра
};

int heuristic2(int*** cube) {
	int misorientedCorners = 0;
	int misorientedEdges = 0;

	// Проверка углов
	for (int i = 0; i < 8; ++i) {
		int x, y, z;

		if (i < 4) { // Верхние углы
			x = 0;
			y = (i == 0 || i == 3) ? 0 : 2;
			z = (i == 0 || i == 1) ? 0 : 2;
		}
		else { // Нижние углы
			x = 2;
			y = (i == 4 || i == 7) ? 0 : 2;
			z = (i == 4 || i == 5) ? 0 : 2;
		}

		// Проверка, правильно ли ориентирован угловой кубик
		if (!(cube[correctCorners[i][0]][x][y] == correctCorners[i][0] &&
			cube[correctCorners[i][1]][x][z] == correctCorners[i][1] &&
			cube[correctCorners[i][2]][y][z] == correctCorners[i][2])) {
			misorientedCorners++;
		}
	}

	// Проверка рёбер
	for (int i = 0; i < 12; ++i) {
		int face1 = correctEdges[i][0];
		int face2 = correctEdges[i][1];
		int x1, y1, x2, y2;

		if (i < 4) { // Верхние рёбра
			x1 = (i == 1 || i == 2) ? 1 : 0;
			y1 = (i == 0 || i == 3) ? 1 : 2;
			x2 = (i == 0 || i == 3) ? 1 : 2;
			y2 = (i == 1 || i == 2) ? 1 : 0;
		}
		else if (i < 8) { // Нижние рёбра
			x1 = 2;
			y1 = (i == 4 || i == 7) ? 1 : 0;
			x2 = (i == 5 || i == 6) ? 2 : 1;
			y2 = (i == 5 || i == 6) ? 1 : 2;
		}
		else { // Боковые рёбра
			x1 = 0;
			y1 = 1;
			x2 = (i == 8 || i == 9) ? 0 : 2;
			y2 = 1;
		}

		// Проверка правильной ориентации ребра
		if (!(cube[face1][x1][y1] == correctEdges[i][0] &&
			cube[face2][x2][y2] == correctEdges[i][1])) {
			misorientedEdges++;
		}
	}

	return misorientedCorners + misorientedEdges; // Возвращаем количество неправильно ориентированных кубиков
}

void addChildren(node* p, priority_queue<node*, std::vector<node*>, prioritize>& s, int (*heuristic)(int***))
{
	// leftClock         1
	// leftAntiClock     2
	// rightClock        3
	// rightAntiClock    4
	// upClock           5
	// upAntiClock       6
	// downClock         7
	// downAntiClock     8
	// frontClock        9
	// frontAntiClock    10
	// backClock         11
	// backAntiClock     12

	node* temp1 = new node[1];
	temp1->curr = leftClock(p->curr);
	temp1->depthLevel = p->depthLevel + 1;
	temp1->parent = p;
	temp1->est_cost = heuristic(temp1->curr);
	temp1->prevMove = 1;
	p->addChild(temp1);
	s.push(temp1);

	node* temp4 = new node[1];
	temp4->curr = rightAntiClock(p->curr);
	temp4->depthLevel = p->depthLevel + 1;
	temp4->parent = p;
	temp4->est_cost = heuristic(temp4->curr);
	temp4->prevMove = 4;
	p->addChild(temp4);
	s.push(temp4);

	node* temp3 = new node[1];
	temp3->curr = rightClock(p->curr);
	temp3->depthLevel = p->depthLevel + 1;
	temp3->parent = p;
	temp3->est_cost = heuristic(temp3->curr);
	temp3->prevMove = 3;
	p->addChild(temp3);
	s.push(temp3);

	node* temp7 = new node[1];
	temp7->curr = downClock(p->curr);
	temp7->depthLevel = p->depthLevel + 1;
	temp7->parent = p;
	temp7->est_cost = heuristic(temp7->curr);
	temp7->prevMove = 7;
	p->addChild(temp7);
	s.push(temp7);

	node* temp10 = new node[1];
	temp10->curr = frontAntiClock(p->curr);
	temp10->depthLevel = p->depthLevel + 1;
	temp10->parent = p;
	temp10->est_cost = heuristic(temp10->curr);
	temp10->prevMove = 10;
	p->addChild(temp10);
	s.push(temp10);

	node* temp5 = new node[1];
	temp5->curr = upClock(p->curr);
	temp5->depthLevel = p->depthLevel + 1;
	temp5->parent = p;
	temp5->est_cost = heuristic(temp5->curr);
	temp5->prevMove = 5;
	p->addChild(temp5);
	s.push(temp5);

	node* temp2 = new node[1];
	temp2->curr = leftAntiClock(p->curr);
	temp2->depthLevel = p->depthLevel + 1;
	temp2->parent = p;
	temp2->est_cost = heuristic(temp2->curr);
	temp2->prevMove = 2;
	p->addChild(temp2);
	s.push(temp2);

	node* temp8 = new node[1];
	temp8->curr = downAntiClock(p->curr);
	temp8->depthLevel = p->depthLevel + 1;
	temp8->parent = p;
	temp8->est_cost = heuristic(temp8->curr);
	temp8->prevMove = 8;
	p->addChild(temp8);
	s.push(temp8);

	node* temp12 = new node[1];
	temp12->curr = backAntiClock(p->curr);
	temp12->depthLevel = p->depthLevel + 1;
	temp12->parent = p;
	temp12->est_cost = heuristic(temp12->curr);
	temp12->prevMove = 12;
	p->addChild(temp12);
	s.push(temp12);

	node* temp9 = new node[1];
	temp9->curr = frontClock(p->curr);
	temp9->depthLevel = p->depthLevel + 1;
	temp9->parent = p;
	temp9->est_cost = heuristic(temp9->curr);
	temp9->prevMove = 9;
	p->addChild(temp9);
	s.push(temp9);

	node* temp6 = new node[1];
	temp6->curr = upAntiClock(p->curr);
	temp6->depthLevel = p->depthLevel + 1;
	temp6->parent = p;
	temp6->est_cost = heuristic(temp6->curr);
	temp6->prevMove = 6;
	p->addChild(temp6);
	s.push(temp6);

	node* temp11 = new node[1];
	temp11->curr = backClock(p->curr);
	temp11->depthLevel = p->depthLevel + 1;
	temp11->parent = p;
	temp11->est_cost = heuristic(temp11->curr);
	temp11->prevMove = 11;
	p->addChild(temp11);
	s.push(temp11);
}

void printStackWithMoves(stack<int> s) {
	// leftClock         1
	// leftAntiClock     2
	// rightClock        3
	// rightAntiClock    4
	// upClock           5
	// upAntiClock       6
	// downClock         7
	// downAntiClock     8
	// frontClock        9
	// frontAntiClock    10
	// backClock         11
	// backAntiClock     12
	while (!s.empty())
	{
		int p = s.top();
		if (p == 1) {
			cout << "Поверните левую грань по часовой" << endl;
		}
		else if (p == 2) {
			cout << "Поверните левую грань против часовой" << endl;
		}
		else if (p == 3) {
			cout << "Поверните правую грань по часовой" << endl;
		}
		else if (p == 4) {
			cout << "Поверните правую грань против часовой" << endl;
		}
		else if (p == 5) {
			cout << "Поверните верхнюю грань по часовой" << endl;
		}
		else if (p == 6) {
			cout << "Поверните верхнюю грань против часовой" << endl;
		}
		else if (p == 7) {
			cout << "Поверните нижнюю грань по часовой" << endl;
		}
		else if (p == 8) {
			cout << "Поверните нижнюю грань против часовой" << endl;
		}
		else if (p == 9) {
			cout << "Поверните переднюю грань по часовой" << endl;
		}
		else if (p == 10) {
			cout << "Поверните переднюю грань против часовой" << endl;
		}
		else if (p == 11) {
			cout << "Поверните заднюю грань по часовой" << endl;
		}
		else if (p == 12) {
			cout << "Поверните заднюю грань против часовой" << endl;
		}
		s.pop();
	}
	cout << endl;
}

// Заполнение начального и конечного состояний
void takeInput(int*** finalState) {

	ifstream file("input.txt");

	if (file.is_open()) {

		int value = 0;

		while (!file.eof()) {

			//чтение начального
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						file >> value;
						finalState[i][j][k] = value;
					}
				}
			}
		}

	}
	else cout << "Cannot open file" << endl;
}

int main()
{
	setlocale(LC_ALL, "");

	// Конечное состояние
	int*** finalState;
	finalState = new int** [6];
	for (int i = 0; i < 6; i++)
	{
		finalState[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			finalState[i][j] = new int[3];
		}
	}

	takeInput(finalState);
	
	// A*
	priority_queue<node*, std::vector<node*>, prioritize> pq;
	node* root = new node();
	root->setCurrState(finalState);
	root->curr = leftAntiClock(root->curr);
	root->curr = rightAntiClock(root->curr);
	root->curr = upClock(root->curr);
	root->curr = downClock(root->curr);
	root->curr = rightAntiClock(root->curr); //h1
	root->curr = backAntiClock(root->curr); 
	root->curr = frontClock(root->curr);
	root->curr = downAntiClock(root->curr);
	root->curr = leftClock(root->curr);
	root->curr = upAntiClock(root->curr);


	root->est_cost = heuristic2(root->curr);
	pq.push(root);

	while (!pq.empty())
	{
		node* cur = pq.top();
		pq.pop();

		if (cur->est_cost == 0)
		{
			int depth = cur->depthLevel;
			stack<int> path;
			while (cur->parent != nullptr)
			{
				path.push(cur->prevMove);
				cur = cur->parent;
			}
			cout << "Необходимо поворотов: " << depth << endl;
			printStackWithMoves(path);
			break;
		}
		else
		{
			if (cur->depthLevel < 30)
			{
				addChildren(cur, pq, heuristic2);
			}
		}
	}
}