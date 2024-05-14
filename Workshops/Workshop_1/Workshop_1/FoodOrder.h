/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 14-05-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#pragma once
#include <iostream>
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca {
	class FoodOrder {
		char m_orderTag;
		char m_customerName[10] = { '\0' };
		char m_orderDescription[25] = { '\0' };
		double m_price;
		char m_dailySpecialStatus;
	public:
		FoodOrder() {};
		std::istream& read(std::istream& in);
		void display() const;
	};
}

#endif // !SENECA_FOODORDER_H
