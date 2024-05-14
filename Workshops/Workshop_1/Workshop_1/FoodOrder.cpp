/*****************************************************************
                        Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 19-01-2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#include "FoodOrder.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace seneca;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

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
	count++;
	if (m_customerName[0] == '\0') {
		std::cout << count << ". " << "No Order" << std::endl;
	}
	else
	{
		std::cout << std::setw(2) << std::setfill(' ') << std::left << count << ". " << std::setw(10) << std::left << m_customerName << "|" << std::setw(25) << m_orderDescription
			<< "|" << std::setw(12) << std::fixed << std::setprecision(2) << m_price << "|";
		if (m_dailySpecialStatus == 'Y')
		{
			std::cout << std::setw(13) << std::right << m_price;
		}

		std::cout << std::endl;

	}
}