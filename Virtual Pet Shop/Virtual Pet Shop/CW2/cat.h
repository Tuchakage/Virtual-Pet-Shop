#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class cat : public pets
{
private:
	int catpop = 0;
public:
	cat()
	{
		type_of_animal = "Cat";
		srand(time(NULL));
		cout << "What is the name of the Cat?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype)
	{
		if (animaltype == "Cat" || animaltype == "cat")
		{
			catpop++;
			cout << "Cats Popularity: " << catpop << endl;
		}

	}
};

