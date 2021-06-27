#pragma once
#include "pets.h"

#include <string>
#include <iostream>

using namespace std;
class dog : public pets
{
private:
	int dogpop = 0;
public:
	dog() 
	{
		type_of_animal = "Dog";
		srand(time(NULL));
		cout << "What is the name of the Dog?" << endl;
		cin >> petname;
	}

	void setPopularity(string animaltype) 
	{
		if (animaltype == "Dog" || animaltype == "dog") 
		{
			dogpop++;
			cout << "Dogs Popularity: " << dogpop << endl;
		}
		
	}


};

