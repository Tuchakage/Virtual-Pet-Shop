#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class lizard : public pets
{
private:
	int lizardpop = 0;
public:
	lizard()
	{
		type_of_animal = "Lizard";
		srand(time(NULL));
		cout << "What is the name of the Lizard?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype)
	{
		if (animaltype == "Lizard" || animaltype == "lizard")
		{
			lizardpop++;
			cout << "Dogs Popularity: " << lizardpop << endl;
		}

	}
};

