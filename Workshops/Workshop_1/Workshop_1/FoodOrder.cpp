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
#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace seneca;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

FoodOrder::FoodOrder() {
	m_customerName[0] = '\0';
	m_orderDescription = nullptr;
	m_price = 0.0;
	m_dailySpecialStatus = '\0';
}

FoodOrder::FoodOrder(const FoodOrder& other) {
	*this = other;
};

FoodOrder& FoodOrder::operator=(const FoodOrder& other) {
	if (this != &other) {
		this->m_orderTag = other.m_orderTag;
		strcpy(this->m_customerName, other.m_customerName);
		if (other.m_orderDescription != nullptr) {
			this->m_orderDescription = new char[strlen(other.m_orderDescription) + 1];
			strcpy(this->m_orderDescription, other.m_orderDescription);
		}
		else {
			this->m_orderDescription = nullptr;
		}
		this->m_price = other.m_price;
		this->m_dailySpecialStatus = other.m_dailySpecialStatus;
	}
	return *this;
};

std::istream& FoodOrder::read(std::istream& in) {
	if (in.good())
	{
		char temp[100];
		in.getline(m_customerName, MAX_NAME_SIZE, ',');

		if (m_orderDescription != nullptr)
		{
			delete[] m_orderDescription;
			m_orderDescription = nullptr;
		}
		if (in.getline(temp, MAX_DESC_SIZE, ',')) {
			m_orderDescription = new char[strlen(temp) + 1];
			strcpy(m_orderDescription, temp);
		}
		else
		{
			m_orderDescription = nullptr;
		}
		in >> m_price;
		in.ignore();
		in >> m_dailySpecialStatus; 
		in.ignore(1000, '\n');
	}
	return in;
}

void FoodOrder::display() const {
	static int count = 0;
	double tax = m_price * g_taxrate;
	count++;
	if (m_customerName[0] == '\0' && m_orderDescription == nullptr) {
		std::cout << count << ". " << "No Order" << std::endl;
	}
	else
	{
		std::cout << std::setw(2) << std::setfill(' ') << std::left << count << ". " << std::setw(10) << std::left << m_customerName << "|";
		std::cout << std::setw(25) << m_orderDescription << "|";
		std::cout << std::setw(12) << std::fixed << std::setprecision(2) << m_price + tax << "|";
		if (m_dailySpecialStatus == 'Y')
		{
			std::cout << std::setw(13) << std::right << m_price + tax - g_dailydiscount;
		}

		std::cout << std::endl;

	}
}

FoodOrder::~FoodOrder() {
	if (m_orderDescription != nullptr) {
		delete[] m_orderDescription;
		m_orderDescription = nullptr;
	}
}