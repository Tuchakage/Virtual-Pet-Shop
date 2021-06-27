#pragma once
#include <string>
#include <iostream>
using namespace std;

class customer
{
protected:
	int age;
	string firstname;
	string lastname;
	string address;
	bool cfreetrial;
	string freetrialanswer;
	int numofpetsowned_freetrial;
	int numofpurchasedpets;
	int pets_owned;
	int max_pet;
	float offerprice;
	//Associate with the company class?
	
	customer()
	{
		numofpetsowned_freetrial = 0;
		numofpurchasedpets = 0;
		pets_owned = 0;
		cfreetrial = false;
		cout << "Create An Account: " << endl;
		cout << "What is your Firstname?" << endl;
		cin >> firstname;

		cout << "What is your Surname" << endl;
		cin >> lastname;

		cout << "What is your address?" << endl;
		cin >> address;

		cout << "Do you want to activate your free trial? Yes Or No" << endl;
		cin >> freetrialanswer;

		if (freetrialanswer == "yes" || freetrialanswer == "Yes")
		{
			cfreetrial = true;
		}
		else if (freetrialanswer == "no" || freetrialanswer == "No")
		{
			cfreetrial = false;
		}
		else 
		{
			cout << "That is not the correct input!" << endl;
		}


		

	}

public:

	virtual void buyPet(float petprice, bool freetrial) = 0;

	void getAccountDetails() 
	{
		cout << "Name: " << firstname << " " << lastname << endl;
		cout << "Address: " << address << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Free Trial Status: " << cfreetrial << endl;
	}


	void getAccountName(int count)
	{
		cout << "Account Number " << count << ":" << firstname << " " << lastname << endl;
		
	}

	int setAge(int a) 
	{
		age = a;
		return age;
	}

	int getAge()
	{
		return age;
	}
	
	bool getFreeTrialStatus() 
	{
		return cfreetrial;
	}

	int getPetOwned() 
	{
		return pets_owned;
	}
	int getMaxPet() 
	{
		return max_pet;
	}


};

