#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
class pets
{
protected:
	
	string petname;
	string petdesc;
	int petprice;
	bool freetrial;
	int hungerlevel;
	int energylevel;
	int petmoodlevel;
	int friendliness;
	bool owned;
	string type_of_animal;
	string freetrialanswer;
	
public:
	pets() 
	{
		owned = false;
		srand(time(NULL));

		clock_t startTime = clock();
		double secondsgone = 0;
		double seconds_action = rand() % 30 + 1;
	
		cout << "Can you describe the pet?" << endl;
		cin >> petdesc;

		
		cout << "Is the Pet Availabe for free trial" << endl;
		cin >> freetrialanswer;
		if (freetrialanswer == "No" || freetrialanswer == "no")
		{
			freetrial = false;
		}
		if (freetrialanswer == "Yes" || freetrialanswer == "yes")
		{
			freetrial = true;
		}


		cout << "How much is this Pet Worth?" << endl;
		cin >> petprice;

		cout << "How friendly is this pet? (In one word)" << endl;
		friendliness = rand() % 10 + 1;
		if (friendliness <= 4) 
		{
			cout << "Not very friendly" << endl;
		}
		else if (friendliness >= 6) 
		{
			cout << "Very Friendly!" << endl;
		}
		else if (friendliness == 5) 
		{
			cout << "Neutral" << endl;
		}

		energylevel = rand() % 50 + 50 + 1;
		hungerlevel = rand() % 50 + 50 + 1;

		petmoodlevel = rand() % 10 + 1;

		cout << "Energy Level: " << energylevel << endl;
		cout << "Hunger Level: " << hungerlevel << endl;
		cout << "Mood Level: " << petmoodlevel << endl;


	


		if (energylevel < 50)
		{
			cout << "His energy is low" << endl;
		}
		if (energylevel >= 50)
		{
			cout << "His energy is high" << endl;
		}


		
		if (hungerlevel < 50)
		{
			cout << "His hunger is low" << endl;
		}
		if (hungerlevel >= 50)
		{
			cout << "His hunger is high" << endl;
		}


		

	}

	void getPetDetails(int count) 
	{
		cout << "Pet Number " << count << ":" << " " << petname << " " << "Type Of Animal: " << type_of_animal << endl;
	}

	int getPrice() 
	{
		return petprice;
	}
	
	bool setOwnedStatus(int o) 
	{
		owned = o;
		return owned;
	}

	bool getOwnedStatus() 
	{
		return owned;
	}

	bool getEligibility() 
	{
		return freetrial;
	}

	string getAnimalType() 
	{
		return type_of_animal;
	}

	int getEnergyLevel() 
	{
		return energylevel;
	}

	int getHungerLevel() 
	{
		return hungerlevel;
	}

	int setHungerLevel(int h) 
	{
		hungerlevel = h;
		return hungerlevel;
	}

	int setEnergyLevel(int e)
	{
		energylevel = e;
		return energylevel;
	}
	string getPetName() 
	{
		return petname;
	}

	virtual void setPopularity(string animaltype) = 0;
	




};

