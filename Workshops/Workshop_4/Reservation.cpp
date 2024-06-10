/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 06-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Reservation.h"
using namespace std;

namespace seneca {

	std::string trim(const std::string& str) {
		// Find the position of the first non-space character from the beginning
		size_t first_non_space = str.find_first_not_of(' ');
		// Find the position of the last non-space character from the end
		size_t last_non_space = str.find_last_not_of(' ');

		// Extract the substring containing non-space characters only
		return str.substr(first_non_space, last_non_space - first_non_space + 1);
	}

	Reservation::Reservation(const std::string& res)
	{
		// Extracting information from the string
		size_t idPos = res.find(':');
		std::string idString = res.substr(0, idPos); // Extract the ID string
		idString = trim(idString); // Trim any leading or trailing spaces (optional)
		m_reservationId = new char[idString.length() + 1]; // Allocate memory for ID
		strcpy(m_reservationId, idString.c_str()); // Copy ID string to m_reservationId

		size_t commaPos1 = res.find(',', idPos + 1);
		size_t commaPos2 = res.find(',', commaPos1 + 1);

		std::string tempName = res.substr(idPos + 1, commaPos1 - idPos - 1);
		m_name = trim(tempName); // Trim any leading or trailing spaces

		std::string tempEmail = res.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
		m_email = trim(tempEmail); // Trim any leading or trailing spaces

		size_t numOfPeoplePos = res.find(',', commaPos2 + 1);
		m_numOfPeople = std::stoi(res.substr(commaPos2 + 1, numOfPeoplePos - commaPos2 - 1));

		size_t dayPos = res.find(',', numOfPeoplePos + 1);
		m_day = std::stoi(res.substr(numOfPeoplePos + 1, dayPos - numOfPeoplePos - 1));

		size_t hourPos = res.find(',', dayPos + 1);
		m_hour = std::stoi(res.substr(dayPos + 1, hourPos - dayPos - 1));
	}

	Reservation::Reservation(const Reservation& src)
	{
		*this = src;
	}
	Reservation::Reservation(Reservation&& src) noexcept
	{
		*this = move(src);
	}
	Reservation::~Reservation()
	{
		delete[] m_reservationId;
		m_reservationId = nullptr;
	}
	Reservation& Reservation::operator=(const Reservation& src)
	{
		// 1. check for self-assignment
		if (this != &src)
		{
			// 2. clean-up the resource used by the current instance
			delete[] m_reservationId;
			// 3. shallow copy
			m_name = src.m_name;
			m_email = src.m_email;
			m_numOfPeople = src.m_numOfPeople;
			m_day = src.m_day;
			m_hour = src.m_hour;
			// 4. deep copy (copy the resource)
			if (src.m_reservationId != nullptr)
			{
				// 4.1 allocate new dynamic memory, if needed
				m_reservationId = new char[strlen(src.m_reservationId) + 1];
				// 4.2 copy the resource data
				strcpy(m_reservationId, src.m_reservationId);
			}
			else
			{
				m_reservationId = nullptr;
			}
		}
		return *this;
	}
	Reservation& Reservation::operator=(Reservation&& src) noexcept
	{
		// 1. check for self-assignment
		if (this != &src)
		{
			// 2. clean-up the resource used by the current instance
			delete[] m_reservationId;
			// 3. shallow copy
			m_name = src.m_name;
			m_email = src.m_email;
			m_numOfPeople = src.m_numOfPeople;
			m_day = src.m_day;
			m_hour = src.m_hour;
			// 4. move the resource
			m_reservationId = src.m_reservationId;
			src.m_reservationId = nullptr; // he parameter doesn't have the resource anymore so the destructor won't delete it
		}
		return *this;
	}
	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}
	void Reservation::display(std::ostream& os) const
	{
		os << "   ";
		if (m_hour >= 6 && m_hour <= 9) {
			os << "Breakfast";
		}
		else if (m_hour >= 11 && m_hour <= 15) {
			os << "Lunch";
		}
		else if (m_hour >= 17 && m_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << m_day << " @ " << m_hour << ":00 for " << m_numOfPeople;
		if (m_numOfPeople == 1)
			os << " person." << std::endl;
		else
			os << " people." << std::endl;
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& src)
	{
		os << "Reservation "
			<< setw(10)
			<< right
			<< src.m_reservationId
			<< ": "
			<< setw(20)
			<< right
			<< src.m_name
			<< "  <"
			<< setw(20)
			<< left
			<< src.m_email + ">";
		src.display(os);
		return os;
	}
}