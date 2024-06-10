/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 06-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Restaurant.h"
using namespace std;

namespace seneca {

	// 2 parameter constructor
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		if (cnt > 0) {
			m_count = cnt;
			m_reservations = new const Reservation * [m_count];
			for (size_t i = 0; i < m_count; i++) {
				this->m_reservations[i] = new Reservation(*reservations[i]);
			}
		}
	}

	// Copy Constructor
	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	// Move Constructor
	Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = move(src);
	}

	// Destructor
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < m_count; ++i) {
			delete m_reservations[i]; // Delete each dynamically allocated Reservation
		}
		delete[] m_reservations; // Delete the array of pointers
	}

	// Copy Assignment Operator
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i];
			}
			delete[] m_reservations;
			m_count = src.m_count;
			if (src.m_count > 0) {
				m_reservations = new const Reservation * [m_count];
				for (size_t i = 0; i < m_count; i++) {
					m_reservations[i] = new Reservation(*src.m_reservations[i]);
				}
			}
			else {
				m_reservations = nullptr;
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i];
			}
			delete[] m_reservations;
			m_count = src.m_count;
			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
			src.m_count = 0;
		}
		return *this;
	}

	// size_t operator
	size_t Restaurant::size() const
	{
		return m_count;
	}

	// ostream operator
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		static size_t CALL_CNT = 0;
		++CALL_CNT;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
		os << "--------------------------" << endl;
		if (res.m_count == 0) {
			os << "This restaurant is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < res.m_count; i++) {
				os << *res.m_reservations[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}