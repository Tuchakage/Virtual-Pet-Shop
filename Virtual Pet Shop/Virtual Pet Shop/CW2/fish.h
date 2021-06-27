#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class fish : public pets
{
private:
	int fishpop = 0;
public:
	fish()
	{
		type_of_animal = "Fish";
		srand(time(NULL));
		cout << "What is the name of the Fish?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype)
	{
		if (animaltype == "Fish" || animaltype == "fish")
		{
			fishpop++;
			cout << "Fish Popularity: " << fishpop << endl;
		}

	}
};
