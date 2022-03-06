#include "game.h"
#include <random>
#include <stdexcept>

Game::Game(const int mapSize)
	: mRow(mapSize), mColumn(mapSize)
{
	if (mapSize > 0)
	{
		for (int i = 0; i < mRow; ++i)
		{
			std::vector<int> v;
			for (int j = 0; j < mColumn; ++j)
			{
				double p = Probability();
				if (p <= 10)
				{
					++mCellNum;
					v.push_back(1);
				}
				else
				{
					v.push_back(0);
				}
			}
			mField.push_back(v);
		}
	}
	else
		throw std::invalid_argument("Invalid parameter given!");
}

Game::Game(const int mapRow, const int mapColumn)
	: mRow(mapRow), mColumn(mapColumn)
{
	if (mapRow > 0 && mapColumn > 0)
	{
		for (int i = 0; i < mRow; ++i)
		{
			std::vector<int> v;
			for (int j = 0; j < mColumn; ++j)
			{
				double p = Probability();
				if (p <= 10)
				{
					++mCellNum;
					v.push_back(1);
				}
				else
				{
					v.push_back(0);
				}
			}
			mField.push_back(v);
		}
	}
	else
		throw std::invalid_argument("Invalid parameter given!");
}

Game::Game(const int mapSize, const double cellProbability) : mRow(mapSize), mColumn(mapSize)
{
	if (mapSize > 0 && cellProbability >= 0)
	{
		for (int i = 0; i < mRow; ++i)
		{
			std::vector<int> v;
			for (int j = 0; j < mColumn; ++j)
			{
				double p = Probability();
				if (p <= cellProbability)
				{
					++mCellNum;
					v.push_back(1);
				}
				else
				{
					v.push_back(0);
				}
			}
			mField.push_back(v);
		}
	}
	else
		throw std::invalid_argument("Invalid parameter given!");
}

Game::Game(const int mapRow, const int mapColumn, const double cellProbability)
	: mRow(mapRow), mColumn(mapColumn)
{
	if (mapRow > 0 && mapColumn > 0 && cellProbability >= 0)
	{
		for (int i = 0; i < mRow; ++i)
		{
			std::vector<int> v;
			for (int j = 0; j < mColumn; ++j)
			{
				double p = Probability();
				if (p <= cellProbability)
				{
					++mCellNum;
					v.push_back(1);
				}
				else
				{
					v.push_back(0);
				}
			}
			mField.push_back(v);
		}
	}
	else
		throw std::invalid_argument("Invalid parameter given!");
}

Game::Game(const int height, const int width, const int top, const int left, std::vector<std::vector<int>>& vector)
	: mRow(height), mColumn(width)
{
	if (height > 0 && width > 0 && top > 0 && left > 0)
	{
		for (int i = 0; i < mRow; ++i)
		{
			std::vector<int> v;
			for (int j = 0; j < mColumn; ++j)
			{
				v.push_back(0);
			}
			mField.push_back(v);
		}

		for (int i = 0; i < vector.size(); ++i)
		{
			for (int j = 0; j < vector[i].size(); ++j)
			{
				if (vector[i][j] == 1 && i + top < mRow && j + left < mColumn)
				{
					++mCellNum;
					mField[i + top][j + left] = 1;
				}
				else
					throw std::invalid_argument("Vector pattern outside of field bounds!");
			}
		}
	}
	else
		std::cout << "Invalid parameter given!" << std::endl;
}

void Game::Play()
{
	int round = 0;
	std::cout << *this;
	while (round != 100 && mCellNum != 0)
	{
		++round;
		if (std::cin.get() == '\n')
		{
			system("cls"); // clears console, command depends on OS. try "clear" on Linux!
			NextRound();
		}
	}
	std::cout << std::endl << "Game over!";
}

void Game::NextRound()
{
	std::vector<std::vector<int>> field = mField;
	int neighbours = 0;

	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; j < mField[i].size(); ++j)
		{
			if (i < mField.size() - 1 && i > 0 && j < mField[i].size() - 1 && j > 0)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i < mField.size() - 1 && i > 0 && j < mField[i].size() - 1)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i < mField.size() - 1 && i > 0 && j > 0)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i < mField.size() - 1 && j < mField[i].size() - 1 && j > 0)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i > 0 && j < mField[i].size() - 1 && j > 0)
			{
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i == 0 && j == 0)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i == mField.size() - 1 && j == 0)
			{
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j + 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j + 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i == 0 && j == mField[i].size() - 1)
			{
				if (mField[i + 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i + 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}
			else if (i == mField.size() - 1 && j == mField[i].size() - 1)
			{
				if (mField[i - 1][j] == 1)
				{
					++neighbours;
				}
				if (mField[i - 1][j - 1] == 1)
				{
					++neighbours;
				}
				if (mField[i][j - 1] == 1)
				{
					++neighbours;
				}
			}

			if (mField[i][j] == 1 && neighbours != 2 && neighbours != 3)
			{
				--mCellNum;
				field[i][j] = 0;
			}
			else if (neighbours == 3 && mField[i][j] == 0)
			{
				++mCellNum;
				field[i][j] = 1;
			}
			neighbours = 0;
		}
	}
	mField = field;

	std::cout << *this;
}

double Game::Probability() const
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_real_distribution<double> uniform_dist(1, 100);

	return uniform_dist(engine);
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
	for (int i = 0; i < game.mField.size(); ++i)
	{
		for (int j = 0; j < game.mField[i].size(); ++j)
		{
			os << game.mField[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}
