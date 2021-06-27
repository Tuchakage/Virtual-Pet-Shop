#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class hamster : public pets
{
private:
	int hampop = 0;
public:
	hamster()
	{
		type_of_animal = "Hamster";
		srand(time(NULL));
		cout << "What is the name of the Hamster?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype)
	{
		if (animaltype == "Hamster" || animaltype == "hamster")
		{
			hampop++;
			cout << "Hamsters Popularity: " << hampop << endl;
		}

	}
};

