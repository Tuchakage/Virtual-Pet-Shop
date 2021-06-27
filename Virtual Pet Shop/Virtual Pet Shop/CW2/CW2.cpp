#include <iostream>
#include "customer.h"
#include "company.h"
#include "adult.h"
#include "pensioner.h"
#include "cat.h"
#include "parrot.h"
#include "fish.h"
#include "hamster.h"
#include "lizard.h"
using namespace std;


int main()
{
	cout << "Welcome To The PetStore!!" << endl;
	company petstore;
	
	int user_input = 0;
	while (user_input != 9) 
	{
		cout << "Create another account(1), Add another Pet to the shop(2)" << endl;
		cout << "List all accounts (3), List All Pets (4)" << endl;
		cout << "Buy a Pet(5), Check Pets that have been bought (6)," << endl;
		cout << "Feed a Pet(7), Check Pet Stats(8)" << endl;
		cout << "Exit Petstore(9)" << endl;
		cout << " " << endl;
	
		cin >> user_input;
		if (user_input == 1)
		{
			petstore.CreateAccount();
			petstore.decreaseLevel();
		}

		if (user_input == 2)
		{
			petstore.addPet();
			petstore.decreaseLevel();
		}

		if (user_input == 3)
		{
			petstore.listAllAccounts();
			petstore.decreaseLevel();
		}
		if (user_input == 4) 
		{
			petstore.listAllPets();
			petstore.decreaseLevel();
		}

		if (user_input == 5)
		{
			petstore.buyPet();
			petstore.decreaseLevel();
		}
		if (user_input == 6)
		{
			petstore.showBoughtPets();
			petstore.decreaseLevel();
		}

		
		if (user_input == 7) 
		{
			petstore.Feed();
		}
		
		if (user_input == 8)
		{
			petstore.getPetStats();
			petstore.decreaseLevel();
		}
		
	}

	cout << "Thank you for vising our Petshop!!!" << endl;

	
}