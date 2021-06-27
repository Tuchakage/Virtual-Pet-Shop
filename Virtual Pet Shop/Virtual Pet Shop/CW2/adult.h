#pragma once
#include "customer.h"
#include <iostream>
using namespace std;
class adult : public customer
{
private:

public:
	adult()
	{
		max_pet = 6;
	}
	void buyPet(float petprice, bool freetrial)
	{
		if (pets_owned < max_pet && (freetrial == false || cfreetrial == false))
		{
			cout << "Price of the Pet : " << petprice << endl;

			while (offerprice != petprice)
			{
				cout << "How Much do you want to offer?" << endl;
				cin >> offerprice;

				if (offerprice > petprice)
				{
					cout << "Thats too high!" << endl;
				}
				else if (offerprice == petprice)
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

