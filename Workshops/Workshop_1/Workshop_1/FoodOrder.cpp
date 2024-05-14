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
#include "FoodOrder.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace seneca;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;
static int count = 0;

std::istream& FoodOrder::read(std::istream& in) {
	if (in.good())
	{
		in.getline(m_customerName, 10, ',');
		in.getline(m_orderDescription, 25, ',');
		in >> m_price;
		in.ignore();
		in >> m_dailySpecialStatus; 
		in.ignore(1000, '\n');
	}
	return in;
}

void FoodOrder::display() const {
	double tax = m_price * g_taxrate;
	count++;
	if (m_customerName[0] == '\0') {
		std::cout << count << ". " << "No Order" << std::endl;
	}
	else
	{
		std::cout << std::setw(2) << std::setfill(' ') << std::left << count << ". " << std::setw(10) << std::left << m_customerName << "|" << std::setw(25) << m_orderDescription
			<< "|" << std::setw(12) << std::fixed << std::setprecision(2) << m_price + tax << "|";
		if (m_dailySpecialStatus == 'Y')
		{
			std::cout << std::setw(13) << std::right << m_price + tax - g_dailydiscount;
		}

		std::cout << std::endl;

	}
}