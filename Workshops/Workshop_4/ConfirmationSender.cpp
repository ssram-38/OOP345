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
#include "ConfirmationSender.h"
using namespace std;


namespace seneca {
	// Copy Constructor
	// Calls the copy assignment operator
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	// Copy Assignment Operator
	// Copies the data from the source object to the current object
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			delete[] m_reservations;
			m_cnt = src.m_cnt;
			if (m_cnt > 0)
			{
				m_reservations = new const Reservation * [m_cnt];
				for (size_t i = 0; i < m_cnt; i++)
				{
					m_reservations[i] = src.m_reservations[i];
				}
			}
			else
			{
				m_reservations = nullptr;
			}
		}
		return *this;
	}

	// Move Constructor
	// Calls the move assignment operator
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = move(src);
	}

	// Move Assignment Operator
	// Moves the data from the source object to the current object
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_reservations;
			m_cnt = src.m_cnt;
			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
			src.m_cnt = 0;
		}
		return *this;
	}

	// Destructor
	// Deallocates the memory
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_reservations;
		m_reservations = nullptr;
	}

	// Adds the reservation to the array of reservations
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = false;
		for (size_t i = 0; i < m_cnt && !found; i++)
		{
			if (m_reservations[i] == &res)
			{
				found = true;
			}
		}
		if (!found)
		{
			const Reservation** temp = new const Reservation * [m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++)
			{
				temp[i] = m_reservations[i];
			}
			temp[m_cnt] = &res;
			delete[] m_reservations;
			m_reservations = temp;
			m_cnt++;
			temp = nullptr;
		}
		return *this;
	}

	// Removes the reservation from the array of reservations
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < m_cnt; i++)
		{
			if (m_reservations[i] == &res)
			{
				const Reservation** temp = new const Reservation * [m_cnt - 1];
				for (size_t j = 0; j < i; j++)
				{
					temp[j] = m_reservations[j];
				}
				for (size_t j = i; j < m_cnt - 1; j++)
				{
					temp[j] = m_reservations[j + 1];
				}
				delete[] m_reservations;
				m_reservations = temp;
				m_cnt--;
				temp = nullptr;
				break;
			}
		}
		return *this;
	}

	// Displays the reservations
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (sender.m_cnt == 0)
		{
			os << "There are no confirmations to send!" << endl;
		}
		else
		{
			for (size_t i = 0; i < sender.m_cnt; i++)
			{
				os << *sender.m_reservations[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}
