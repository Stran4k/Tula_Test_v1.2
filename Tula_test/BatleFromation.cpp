#include "BatleFromation.h"


void Armored_Car::AddCoordinates(const double& count_x, const double& count_y, const double& count_z)
{
	Coordinate_X = count_x;
	Coordinate_Y = count_y;
	Coordinate_Z = count_z;
}


void CreateBatlleMap::distribution(const int n)
{
	if (param_frequency == true) //литеры 1 2 3 
	{
		if (n <= 3)
		{
			for (size_t i = 0; i < n; i++)
			{
				ArmCar[i].leteral_frequency = i + 1;
				std::cout << "\nБМ №" << i + 1 << " присвается литера - " << ArmCar[i].leteral_frequency << '\n';
			}
		}
		if (n >= 4 && n <= 6)
		{
			int carOne,
				carTwo,
				carThree;
			//находим 2 бм близжайшие к друг к другу 
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n - 1; j++)
				{
					if (BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)
					{
						carOne = i;
						carTwo = j;
					}
				}
			}

			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n - 1; j++)
				{
					if ((BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo] && BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne])
						&& (BatForm[i].betweenTheseCars[j] == BatForm[carOne].betweenTheseCars[j] || BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne])
						&& (BatForm[i].betweenTheseCars[j] == BatForm[carTwo].betweenTheseCars[j] || BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo])
						&& (BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1))
					{
						if (i != carOne && i != carTwo)
							carThree = i;
					}
				}

			}

			//присваиваем 3 основные литеры
			ArmCar[carOne].leteral_frequency = 1;
			std::cout << "\nБМ № 1" << " присвается литера - " << ArmCar[carOne].leteral_frequency;
			ArmCar[carTwo].leteral_frequency = 2;
			std::cout << "\nБМ № 2" << " присвается литера - " << ArmCar[carTwo].leteral_frequency;
			ArmCar[carThree].leteral_frequency = 3;
			std::cout << "\nБМ № 3" << " присвается литера - " << ArmCar[carThree].leteral_frequency;

			//ищем 4 бм
			//находим самую далекую от одной из бм	
				//присаиваем ей литеру бм от которой она самая далекая
			int сarFour, cargroupfirst;
			int litLeaderCarFirstGroup;

			for (size_t i = 0; i < n; i++)
			{
				if (i != carOne && i != carTwo && i != carThree)
				{
					for (size_t j = 0; j < n - 1; j++)
					{

						{
							if ((BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)// не диагональ и наименьший
								&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carThree]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carThree]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carOne]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carTwo])// никто из основной тройки
							{
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carOne])
								{
									cargroupfirst = carOne;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carOne].leteral_frequency;
								}
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carTwo])
								{
									cargroupfirst = carTwo;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carTwo].leteral_frequency;
								}
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carThree]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carThree])
								{
									cargroupfirst = carThree;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carThree].leteral_frequency;
								}
							}
						}


					}

				}
			}


			ArmCar[сarFour].leteral_frequency = litLeaderCarFirstGroup;
			std::cout << "\nБМ № 4" << " присвается литера - " << ArmCar[сarFour].leteral_frequency;

			if (n >= 5) // ищем 5 бм
			{
				int carFive, cargroupsecond;
				int litLeaderCarSecondGroup;

				for (size_t i = 0; i < n; i++)
				{
					if (i != carOne && i != carTwo && i != carThree && i != сarFour)
					{
						for (size_t j = 0; j < n - 1; j++)
						{
							if (j != сarFour && j != cargroupfirst)
							{
								if ((BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)// не диагональ и наименьший
									&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carThree]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carThree]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carOne]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carTwo])// никто из основной троицы
								{
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carOne])
									{
										cargroupsecond = carOne;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carOne].leteral_frequency;
									}
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carTwo]) {
										cargroupsecond = carTwo;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carTwo].leteral_frequency;
									}
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carThree]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carThree])
									{
										cargroupsecond = carThree;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carThree].leteral_frequency;
									}
								}
							}
						}
					}

				}

				ArmCar[carFive].leteral_frequency = litLeaderCarSecondGroup;
				std::cout << "\nБМ №5 " << " присвается литера - " << ArmCar[carFive].leteral_frequency;


				if (n == 6)// ищем 6 бм
				{
					int carSix;
					int lastLetersForSix;
					//double compareDistance;
					for (size_t i = 0; i < n; i++)
					{
						if (i != carOne && i != carTwo && i != carThree && i != сarFour && i != carFive)
						{
							carSix = i;

							if (BatForm[carSix].distaceBetweenCars[carOne] > BatForm[carSix].distaceBetweenCars[сarFour] && BatForm[carSix].distaceBetweenCars[carOne] > BatForm[carSix].distaceBetweenCars[carFive])
							{
								lastLetersForSix = ArmCar[carOne].leteral_frequency;
							}

							if (BatForm[carSix].distaceBetweenCars[сarFour] > BatForm[carSix].distaceBetweenCars[carFive] && BatForm[carSix].distaceBetweenCars[сarFour] > BatForm[carSix].distaceBetweenCars[carOne])
							{
								lastLetersForSix = ArmCar[сarFour].leteral_frequency;
							}

							if (BatForm[carSix].distaceBetweenCars[carFive] > BatForm[carSix].distaceBetweenCars[сarFour] && BatForm[carSix].distaceBetweenCars[carFive] > BatForm[carSix].distaceBetweenCars[carOne])
							{
								lastLetersForSix = ArmCar[carFive].leteral_frequency;
							}
						}
					}


					ArmCar[carSix].leteral_frequency = lastLetersForSix;
					std::cout << "\nБМ № 6" << " присвается литера - " << ArmCar[carSix].leteral_frequency;
				}
			}
		}
	}
	else // литеры 4 5 6
	{
		if (n <= 3)
		{
			for (size_t i = 0; i < n; i++)
			{
				ArmCar[i].leteral_frequency = i + 1;
				std::cout << "\nБМ №" << i + 1 << " присвается литера - " << ArmCar[i].leteral_frequency << '\n';
			}
		}
		if (n >= 4 && n <= 6)
		{
			int carOne,
				carTwo,
				carThree;
			//находим 2 бм близжайшие к друг к другу 
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n - 1; j++)
				{
					if (BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)
					{
						carOne = i;
						carTwo = j;
					}
				}
			}

			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n - 1; j++)
				{
					if ((BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo] && BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne])
						&& (BatForm[i].betweenTheseCars[j] == BatForm[carOne].betweenTheseCars[j] || BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne])
						&& (BatForm[i].betweenTheseCars[j] == BatForm[carTwo].betweenTheseCars[j] || BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo])
						&& (BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1))
					{
						if (i != carOne && i != carTwo)
							carThree = i;
					}
				}

			}

			//присваиваем 3 основные литеры
			ArmCar[carOne].leteral_frequency = 4;
			std::cout << "\nБМ № 1" << " присвается литера - " << ArmCar[carOne].leteral_frequency;
			ArmCar[carTwo].leteral_frequency = 5;
			std::cout << "\nБМ № 2" << " присвается литера - " << ArmCar[carTwo].leteral_frequency;
			ArmCar[carThree].leteral_frequency = 6;
			std::cout << "\nБМ № 3" << " присвается литера - " << ArmCar[carThree].leteral_frequency;

			//ищем 4 бм
			//находим самую далекую от одной из бм	
				//присаиваем ей литеру бм от которой она самая далекая
			int сarFour, cargroupfirst;
			int litLeaderCarFirstGroup;

			for (size_t i = 0; i < n; i++)
			{
				if (i != carOne && i != carTwo && i != carThree)
				{
					for (size_t j = 0; j < n - 1; j++)
					{

						{
							if ((BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)// не диагональ и наименьший
								&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carThree]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carThree]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carOne]
								&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carTwo])// никто из основной тройки
							{
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carOne])
								{
									cargroupfirst = carOne;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carOne].leteral_frequency;
								}
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carTwo])
								{
									cargroupfirst = carTwo;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carTwo].leteral_frequency;
								}
								if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carThree]
									&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carThree])
								{
									cargroupfirst = carThree;
									сarFour = i;
									litLeaderCarFirstGroup = ArmCar[carThree].leteral_frequency;
								}
							}
						}


					}

				}
			}


			ArmCar[сarFour].leteral_frequency = litLeaderCarFirstGroup;
			std::cout << "\nБМ № 4" << " присвается литера - " << ArmCar[сarFour].leteral_frequency;

			if (n >= 5) // ищем 5 бм
			{
				int carFive, cargroupsecond;
				int litLeaderCarSecondGroup;

				for (size_t i = 0; i < n; i++)
				{
					if (i != carOne && i != carTwo && i != carThree && i != сarFour)
					{
						for (size_t j = 0; j < n - 1; j++)
						{
							if (j != сarFour && j != cargroupfirst)
							{
								if ((BatForm[i].distaceBetweenCars[j] < BatForm[i].distaceBetweenCars[j + 1] && (int)BatForm[i].distaceBetweenCars[j] != -1)// не диагональ и наименьший
									&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carTwo]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carOne].betweenTheseCars[carThree]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carOne]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carTwo].betweenTheseCars[carThree]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carOne]
									&& BatForm[i].betweenTheseCars[j] != BatForm[carThree].betweenTheseCars[carTwo])// никто из основной троицы
								{
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carOne]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carOne])
									{
										cargroupsecond = carOne;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carOne].leteral_frequency;
									}
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carTwo]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carTwo]) {
										cargroupsecond = carTwo;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carTwo].leteral_frequency;
									}
									if (BatForm[i].betweenTheseCars[j] == BatForm[i].betweenTheseCars[carThree]
										&& BatForm[i].distaceBetweenCars[j] >= BatForm[i].distaceBetweenCars[carThree])
									{
										cargroupsecond = carThree;
										carFive = i;
										litLeaderCarSecondGroup = ArmCar[carThree].leteral_frequency;
									}
								}
							}
						}
					}

				}

				ArmCar[carFive].leteral_frequency = litLeaderCarSecondGroup;
				std::cout << "\nБМ №5 " << " присвается литера - " << ArmCar[carFive].leteral_frequency;


				if (n == 6)// ищем 6 бм
				{
					int carSix;
					int lastLetersForSix;
	
					for (size_t i = 0; i < n; i++)
					{
						if (i != carOne && i != carTwo && i != carThree && i != сarFour && i != carFive)
						{
							carSix = i;
		
							if (BatForm[carSix].distaceBetweenCars[carOne] > BatForm[carSix].distaceBetweenCars[сarFour] && BatForm[carSix].distaceBetweenCars[carOne] > BatForm[carSix].distaceBetweenCars[carFive])
							{
								lastLetersForSix = ArmCar[carOne].leteral_frequency;
							}

							if (BatForm[carSix].distaceBetweenCars[сarFour] > BatForm[carSix].distaceBetweenCars[carFive] && BatForm[carSix].distaceBetweenCars[сarFour] > BatForm[carSix].distaceBetweenCars[carOne])
							{
								lastLetersForSix = ArmCar[сarFour].leteral_frequency;
							}

							if (BatForm[carSix].distaceBetweenCars[carFive] > BatForm[carSix].distaceBetweenCars[сarFour] && BatForm[carSix].distaceBetweenCars[carFive] > BatForm[carSix].distaceBetweenCars[carOne])
							{
								lastLetersForSix = ArmCar[carFive].leteral_frequency;
							}
						}
					}


					ArmCar[carSix].leteral_frequency = lastLetersForSix;
					std::cout << "\nБМ № 6" << " присвается литера - " << ArmCar[carSix].leteral_frequency;
				}
			}
		}
	}
}

void CreateBatlleMap::CommandCenter(const int n)
{
	//заполнение векторов
	for (size_t i = 0; i < n; i++)
	{

		for (size_t j = 0; j < n; j++)
		{
			BatForm[i].betweenTheseCars.push_back(j);
			if (i != j) {
				BatForm[i].distaceBetweenCars.push_back(Distace_AC(i, j));
			}
			else
				BatForm[i].distaceBetweenCars.push_back(-1);
		}

	}


	distribution(n);
}

CreateBatlleMap::CreateBatlleMap(const int n)
{
	ArmCar = new Armored_Car[n];
	BatForm = new Batle_Fromation[n];		

	std::cout << "\n Для каждой бронемашин введите координаты x, y, z : ";
	for (size_t i = 0; i < n; i++) {
		double count_x, count_y, count_z;
		std::cin >> count_x >> count_y >> count_z;
		ArmCar[i].AddCoordinates(count_x, count_y, count_z);
	}

	std::cout << "\n Выберите исполнение литерных частот (0 или 1): ";
	std::cin >> param_frequency;


	CommandCenter(n);
}





double CreateBatlleMap::Distace_AC(const int numbBM_1, const int numbBM_2)
{
	return 	 sqrt((ArmCar[numbBM_1].Coordinate_X - ArmCar[numbBM_2].Coordinate_X) * (ArmCar[numbBM_1].Coordinate_X - ArmCar[numbBM_2].Coordinate_X) +
		(ArmCar[numbBM_1].Coordinate_Y - ArmCar[numbBM_2].Coordinate_Y) * (ArmCar[numbBM_1].Coordinate_Y - ArmCar[numbBM_2].Coordinate_Y) +
		(ArmCar[numbBM_1].Coordinate_Z - ArmCar[numbBM_2].Coordinate_Z) * (ArmCar[numbBM_1].Coordinate_Z - ArmCar[numbBM_2].Coordinate_Z));
};

CreateBatlleMap::~CreateBatlleMap()
{
	delete[]ArmCar;
	delete[]BatForm;
}


