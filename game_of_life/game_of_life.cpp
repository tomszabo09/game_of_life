#include "game.h"

int main()
{
	std::cout << "Game of Life was created by John Conway, mathematician of Cambridge University." << std::endl << std::endl;
	std::cout << "Each cell can only survive if they have 2 or 3 neighbours. Dead cells can be revived with exactly 3 neighbours." << std::endl;
	std::cout << "Game lasts 100 rounds or until there are no cells left. Press ENTER to play or to progress to next round!" << std::endl << std::endl;

	//std::vector<std::vector<int>> v;
	//for (int i = 0; i < 5; ++i)
	//{
	//	std::vector<int> v1;
	//	for (int j = 0; j < 7; ++j)
	//	{
	//		v1.push_back(1);
	//	}
	//	v.push_back(v1);
	//}
	//for (int i = 0; i < v.size(); ++i)
	//{
	//	for (int j = 0; j < v[i].size(); ++j)
	//	{
	//		std::cout << v[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	try
	{
		Game g(10);
		g.Play();

		//Game g1(10, 15);
		//g1.Play();

		//Game g2(10, 97.4651);
		//g2.Play();

		//Game g3(10, 15, 54.65489165);
		//g3.Play();

		//Game g4(10, 15, 2, 3, v);
		//g4.Play();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
}