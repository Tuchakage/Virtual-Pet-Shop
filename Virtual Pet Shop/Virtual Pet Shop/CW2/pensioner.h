#pragma once
#include "customer.h"
#include <iostream>
using namespace std;
class pensioner : public customer
{
private:
	float discount = 0.5;
	float discounted_price;
public:
	pensioner()
	{
		max_pet = 5;
	}
	void buyPet(float petprice, bool freetrial)
	{
		if (pets_owned < max_pet && (freetrial == false || cfreetrial == false))
		{
			cout << "Price of the Pet without Discount: " << petprice << endl;
			discounted_price = petprice * discount;
			discounted_price = petprice - discounted_price;

			cout << "Price Of Pet with Discount: " << discounted_price << endl;

			while (offerprice != discounted_price)
			{
				cout << "How Much do you want to offer?" << endl;
				cin >> offerprice;

				if (offerprice > discounted_price)
				{
					cout << "Thats too high!" << endl;
				}
				else if (offerprice == discounted_price)
				{
					cout << "You Bought the Dog!!" << endl;
				}
				else
				{
					cout << "Thats too low!!" << endl;
				}

				numofpurchasedpets++;
				pets_owned++;
			}
		}
		else if ((pets_owned < max_pet && freetrial == true) && cfreetrial == true)
		{
			cout << "You have used this free trial to get this pet!!!" << endl;
			numofpetsowned_freetrial++;
			pets_owned++;
		}


	}

};

