#include <vector>
#include <iostream>
#pragma once

class Game
{
public:
	Game(const int mapSize);
	Game(const int mapRow, const int mapColumn);
	Game(const int mapSize, const double cellProbability);
	Game(const int mapRow, const int mapColumn, const double cellProbability);
	Game(const int height, const int width, const int top, const int left, std::vector<std::vector<int>>& vector);

	void Play();
	void NextRound();
	double Probability() const;
	friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
	int mRow;
	int mColumn;
	std::vector<std::vector<int>> mField;
	int mCellNum = 0;
};