#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class parrot : public pets
{
private:
	int parpop = 0;
public:
	parrot()
	{
		type_of_animal = "Parrot";
		srand(time(NULL));
		cout << "What is the name of the Parrot?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype)
	{
		if (animaltype == "Parrot" || animaltype == "parrot")
		{
			parpop++;
			cout << "Parrpt Popularity: " << parpop << endl;
		}

	}
};

