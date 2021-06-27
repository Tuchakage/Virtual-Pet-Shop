#pragma once
#include "customer.h"
#include <iostream>
#include "pets.h"
#include "dog.h"
#include "underage.h"
#include "adult.h"
#include "pensioner.h"
#include "parrot.h"
#include "cat.h"
#include "hamster.h"
#include "fish.h"
#include "lizard.h"

#include <time.h> 
#include <stdlib.h>

using namespace std;
class company
{
private:
	customer* account[50];
	pets* animals[50];
	int numofaccounts;
	int pet_list;
	int pets_ava;
	int account_list;
	int account_number;
	int pet_number;
	int age;
	string type;
public:
	company() 
	{
		for (int i = 0; i < 51; i++) 
		{
			animals[i] = NULL;
		}

		for (int i = 0; i < 51; i++)
		{
			account[i] = NULL;
		}
		pet_list = 0;
		pets_ava = 0;
		numofaccounts = 0;
		account_list = 0;
		
		addPet();
		CreateAccount();

		/*while (animals[pet_list] != NULL && animals[pet_list]->getOwnedStatus() == true)
		{
			Timer();
		}*/
		
		


	}

	void CreateAccount() 
	{

		numofaccounts++;
		account_list++;
		cout << "How Old are you?" << endl;
		cin >> age;

		if (age <= 14) 
		{
			account[account_list] = new underage;
			account[account_list]->setAge(age);
		}
		else if (age > 14 || age <= 70)
		{
			account[account_list] = new adult;
			account[account_list]->setAge(age);
		}
		else if (age > 70)
		{
			account[account_list] = new pensioner;
			account[account_list]->setAge(age);
		}
		
		account[account_list]->getAccountDetails();
	}

	void addPet()
	{
		pets_ava++;
		pet_list++;

		cout << "What Animal do you want to add to the store?" << endl;
		cin >> type;
		if (type == "Dog" || type == "dog") 
		{
			
			animals[pet_list] = new dog;
			
		}
		else if (type == "cat" || type == "Cat")
		{
			animals[pet_list] = new cat;
		}
		else if (type == "parrot" || type == "Parrot")
		{
			animals[pet_list] = new parrot;
		}
		else if (type == "hamster" || type == "Hamster") 
		{
			animals[pet_list] = new hamster;
		}
		else if (type == "fish" || type == "Fish")
		{
			animals[pet_list] = new fish;
		}
		else if (type == "lizard" || type == "Lizard")
		{
			animals[pet_list] = new lizard;
		}
		else 
		{
			cout << "That is not an Animal we currently have availabe" << endl;
		}
		
	}

	void listAllAccounts()
	{
		for (int i = 1; i < account_list + 1; i++)

		{
			account[i]->getAccountName(i);
		}
	}

	void listAllPets() 
	{
		for (int i = 1; i <pet_list + 1; i++)

		{
			animals[i]->getPetDetails(i);
		}
	}

	void searchAccount() 
	{
		cout << "What Account Number do you want to search for?" << endl;
		cin >> account_number;
		if (account_number != NULL) 
		{
			account[account_number]->getAccountName(account_number);
			
		}
		else 
		{
			cout << "There is no account with this number" << endl;
		}
		
	}

	void checkPetStats()
	{
		cout << "What Account Number do you want to search for?" << endl;
		cin >> pet_number;

		animals[pet_number]->getPetDetails(pet_number);
	}
	int getNumberOfAccountsCreated()
	{
		return numofaccounts;
	}

	void buyPet() 
	{
		listAllPets();
		cout << "What Pet do you want to buy?" << endl;
		cin >> pet_number;
		if (animals[pet_number] != NULL) 
		{
			if (animals[pet_number]->getOwnedStatus() != true && animals[pet_number] != NULL && account[account_list]->getPetOwned() < account[account_list]->getMaxPet())
			{
				account[account_list]->buyPet(animals[pet_number]->getPrice(), animals[pet_number]->getEligibility());
				animals[pet_number]->setOwnedStatus(true);
				animals[pet_number]->setPopularity(animals[pet_number]->getAnimalType());
				//pet_list--;
				pets_ava--;

			}

			else if (animals[pet_number]->getOwnedStatus() != true && animals[pet_number] != NULL && account[account_list]->getPetOwned() >= account[account_list]->getMaxPet()) 
			{
				cout << "You can no longer by anymore pets" << endl;
			}

			else
			{
				cout << "This Pet has already been bought....." << endl;
			}

		}
		else 
		{
			cout << "This Pet doesnt exist" << endl;
		}
		
	}

	void showBoughtPets() 
	{
		for (int i = 0; i < 50; i++)
		{
			if (animals[i] != NULL) 
			{
				if (animals[i]->getOwnedStatus() == true) 
				{
					animals[i]->getPetDetails(i);	
				}

				else
				{
					cout << "Pet Number "<< i<< " Hasnt been bought yet" << endl;
				}
			}
		}

		
	}

	void Feed() 
	{
		string input;

		cout << "Would you like to feed a pet? Yes Or No" << endl;
		cin >> input;

		if (input == "Yes" || input == "yes")
		{
			listAllPets();
			cout << "What Pet would you like to feed?" << endl;
			cin >> pet_number; 

			if (animals[pet_number]->getHungerLevel() < 30)
			{
				animals[pet_number]->setHungerLevel(animals[pet_number]->getHungerLevel() + rand() % 50 + 1);
				cout << "Hunger Level: " << animals[pet_number]->getHungerLevel();
			}
			
			else if (animals[pet_number]->getHungerLevel() >= 30 && animals[pet_number]->getHungerLevel() <= 80)
			{
				animals[pet_number]->setHungerLevel(animals[pet_number]->getHungerLevel() + rand() % 15 + 1);
				cout << "Hunger Level: " << animals[pet_number]->getHungerLevel() << endl;
			}
			else if (animals[pet_number]->getHungerLevel() > 80)
			{
				cout << "You cannot feed the Pet anymore, as you are making it unhealthy" << endl;
			}
		}
		
		
	}

	void getPetStats() 
	{
		listAllPets();
		cout << "Which Pets stats do you want to check?" << endl;
		cin >> pet_number;

		cout << animals[pet_number]->getPetName() << " Stats:" << endl;
		cout << "Energy Level: " << animals[pet_number]->getEnergyLevel() << endl;
		cout << "Hunger Level: " <<  animals[pet_number]->getHungerLevel() << endl;
	}

	//Tryed it but couldn't get it to fully work the way we wanted it to
	void Timer() 
	{
		srand(time(NULL));

		clock_t startTime = clock();
		double secondsgone = 0;
		double seconds_action = rand() % 30 + 1;

		

		secondsgone = (clock() - startTime) / CLOCKS_PER_SEC;
		cout << "\b" << seconds_action - secondsgone << "\b";


		if (secondsgone >= seconds_action)
		{
			animals[pet_list]->setEnergyLevel(animals[pet_list]->getEnergyLevel() - 1);
			cout << "Pet Has Lost Energy" << endl;
			animals[pet_list]->setHungerLevel(animals[pet_list]->getHungerLevel() - 1);
			cout << "Pet Has Lost Hunger" << endl;


			cout << "Energy Level: " << animals[pet_list]->getEnergyLevel() << endl;
			cout << "Hunger Level: " << animals[pet_list]->getHungerLevel() << endl;

			startTime = clock();
			secondsgone = clock();
			seconds_action = rand() % 30 + 1;

		}
	}

	void decreaseLevel() 
	{

		for (int i = 0; i < 50; i++)
		{
			if (animals[i] != NULL)
			{
				
				animals[i]->setEnergyLevel(animals[i]->getEnergyLevel() - rand() % 5 - 1);
				//cout << "Pet Has Lost Energy" << endl;
				animals[i]->setHungerLevel(animals[i]->getHungerLevel() - rand() % 5 - 1);
				//cout << "Pet Has Lost Hunger" << endl;

				/*cout << "Pet Name:" << animals[i]->getPetName() << endl;
				cout << "Energy Level: " << animals[i]->getEnergyLevel() << endl;
				cout << "Hunger Level: " << animals[i]->getHungerLevel() << endl;*/
			}
		}



	}

	
};

