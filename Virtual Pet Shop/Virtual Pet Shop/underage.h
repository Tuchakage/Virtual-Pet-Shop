#pragma once
#include "customer.h"
#include <iostream>
using namespace std;
class underage : public customer
{
public:
	underage() 
	{
	}
	void buyPet(int petprice)  
	{
		cout << "Price Of Pet(Child): " << petprice << endl;

		cout << "How Much do you want to offer?" << endl;
		cin >> offerprice;


	}
};

