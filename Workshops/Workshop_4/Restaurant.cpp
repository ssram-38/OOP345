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

	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = move(src);
	}

	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < m_count; ++i) {
			delete m_reservations[i]; // Delete each dynamically allocated Reservation
		}
		delete[] m_reservations; // Delete the array of pointers
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		// 1. check for self-assignment (and NOTHING else)
		if (this != &src)
		{
			// 2. clean up (deallocate previously allocated dynamic memory)
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i]; // Delete each dynamically allocated Reservation
			}
			delete[] m_reservations;
			// 3. shallow copy (copy non-resource variables)
			m_count = src.m_count;
			// 4. deep copy (copy the resource)
			if (src.m_count > 0) {
				// 4.1 allocate new dynamic memory, if needed
				m_reservations = new const Reservation * [m_count];
				// 4.2 copy the resource data
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
		// 1. check for self-assignment (and NOTHING else)
		if (this != &src)
		{
			// 2. clean up (deallocate previously allocated dynamic memory)
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i]; // Delete each dynamically allocated Reservation
			}
			delete[] m_reservations;
			// 3. shallow copy (copy non-resource variables)
			m_count = src.m_count;
			// 4. move the resource
			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
			src.m_count = 0;
		}
		return *this;
	}

	size_t Restaurant::size() const
	{
		return m_count;
	}
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