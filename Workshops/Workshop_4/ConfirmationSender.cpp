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

#include "ConfirmationSender.h"
#include <algorithm>

namespace seneca {

	// Default constructor
    ConfirmationSender::ConfirmationSender() : m_reservations(nullptr), m_count(0) {}

	// Copy constructor
	// Calls the copy assignment operator to copy the data from the source object to the current object
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) {
        *this = other;
    }

	// Copy assignment operator
	// Copies the data from the source object to the current object
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] m_reservations;
            m_count = other.m_count;
            if (m_count > 0)
            {
                m_reservations = new const Reservation * [m_count];
                for (size_t i = 0; i < m_count; ++i) {
                    m_reservations[i] = other.m_reservations[i];
                }
            }
            else
            {
                m_reservations = nullptr;
            }
        }
        return *this;
    }

	// Move constructor
	// Calls the move assignment operator to move the data from the source object to the current object
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept {
		*this = std::move(other);
    }

	// Move assignment operator
	// Moves the data from the source object to the current object
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            delete[] m_reservations;
            m_reservations = other.m_reservations;
            m_count = other.m_count;
            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

	// Destructor
    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
		m_reservations = nullptr;
    }

	// overloaded operator+=
	// adds the reservation to the list of reservations
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        bool found = false;
        for (size_t i = 0; i < m_count; ++i) {
            if (m_reservations[i] == &res) {
                found = true;
                break;
            }
        }

        if (!found) {
            const Reservation** temp = new const Reservation * [m_count + 1];
            for (size_t i = 0; i < m_count; ++i) {
                temp[i] = m_reservations[i];
            }
            temp[m_count] = &res;
            delete[] m_reservations;
            m_reservations = temp;
            ++m_count;
        }

        return *this;
    }

	// overloaded operator-=
	// removes the reservation from the list of reservations
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_reservations[i] == &res) {
                m_reservations[i] = nullptr;
                const Reservation** temp = new const Reservation * [m_count - 1];
                size_t index = 0;
                for (size_t j = 0; j < m_count; ++j) {
                    if (m_reservations[j] != nullptr) {
                        temp[index++] = m_reservations[j];
                    }
                }
                delete[] m_reservations;
                m_reservations = temp;
                --m_count;
                break;
            }
        }
        return *this;
    }

	// overloaded operator<<
	// displays the list of reservations
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if (sender.m_count == 0) {
            os << "There are no confirmations to send!" << std::endl;
        }
        else {
            for (size_t i = 0; i < sender.m_count; ++i) {
                os << *sender.m_reservations[i];
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }

}
