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
#include <iomanip>
#include <string>
#include <cstring>
#include "Reservation.h"

namespace seneca {

    // Default constructor
    Reservation::Reservation() : m_id{ nullptr }, m_name{ '\0' }, m_email{ '\0' }, m_partysize{ 0 }, m_day{ 0 }, m_hour{ 0 } {}

    // trim function
    std::string Reservation::trim(const std::string& str) {
        size_t first_non_space = str.find_first_not_of(' ');
        size_t last_non_space = str.find_last_not_of(' ');

        return str.substr(first_non_space, last_non_space - first_non_space + 1);
    }

    // Constructor with 1 argument
    Reservation::Reservation(const std::string& res) {
        size_t idPos = res.find(':');
        std::string idString = res.substr(0, idPos);
        idString = trim(idString);
        m_id = new char[idString.length() + 1];
        strcpy(m_id, idString.c_str());

        size_t commaPos1 = res.find(',', idPos + 1);
        size_t commaPos2 = res.find(',', commaPos1 + 1);

        std::string tempName = res.substr(idPos + 1, commaPos1 - idPos - 1);
        m_name = trim(tempName);

        std::string tempEmail = res.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
        m_email = trim(tempEmail);

        size_t numOfPeoplePos = res.find(',', commaPos2 + 1);
        m_partysize = std::stoi(res.substr(commaPos2 + 1, numOfPeoplePos - commaPos2 - 1));

        size_t dayPos = res.find(',', numOfPeoplePos + 1);
        m_day = std::stoi(res.substr(numOfPeoplePos + 1, dayPos - numOfPeoplePos - 1));

        size_t hourPos = res.find(',', dayPos + 1);
        m_hour = std::stoi(res.substr(dayPos + 1, hourPos - dayPos - 1));
    }

    // Copy constructor
	// Calls the copy assignment operator to copy the data from the source object to the current object
    Reservation::Reservation(const Reservation& other) {
		*this = other;
    }

    // Copy assignment operator
	// Copies the data from the source object to the current object
    Reservation& Reservation::operator=(const Reservation& other) {
        if (this != &other) {
            delete[] m_id;
            if (other.m_id != nullptr) {
                m_id = new char[strlen(other.m_id) + 1];
                strcpy(m_id, other.m_id);
            }
            else {
                m_id = nullptr;
            }
            m_name = other.m_name;
            m_email = other.m_email;
            m_partysize = other.m_partysize;
            m_day = other.m_day;
            m_hour = other.m_hour;
        }
        return *this;
    }

    // Move constructor
	// Calls the move assignment operator to move the data from the source object to the current object
    Reservation::Reservation(Reservation&& other) noexcept {
		*this = std::move(other);
    }

    // Move assignment operator
	// Moves the data from the source object to the current object
    Reservation& Reservation::operator=(Reservation&& other) noexcept {
        if (this != &other) {
            delete[] m_id;
            m_id = other.m_id;
            other.m_id = nullptr;
            m_name = other.m_name;
            m_email = other.m_email;
            m_partysize = other.m_partysize;
            m_day = other.m_day;
            m_hour = other.m_hour;
        }
        return *this;
    }

    // Destructor
    Reservation::~Reservation() {
        delete[] m_id;
    }

    // update function
	// updates the day and time of the reservation
    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

	// overloaded operator<<
	// displays the reservation details
	std::ostream& operator<<(std::ostream& os, const Reservation& res) {

		// displays the ID, name, email, day, time and partysize with proper formatting
		os << "Reservation " << std::setw(10) << std::right << res.m_id << ": " << std::setw(20) << std::right << res.m_name << "  " << std::setw(20) << std::left << "<" + res.m_email + ">";
		if (res.m_hour >= 6 && res.m_hour <= 9) {
			os << "    Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partysize << " " << (res.m_partysize > 1 ? "people" : "person") << ".";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			os << "    Lunch on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partysize << " " << (res.m_partysize > 1 ? "people" : "person") << ".";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			os << "    Dinner on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partysize << " " << (res.m_partysize > 1 ? "people" : "person") << ".";
		}
		else {
			os << "    Drinks on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partysize << " " << (res.m_partysize > 1 ? "people" : "person") << ".";
		}
		os << std::endl;
		return os;
	}
}