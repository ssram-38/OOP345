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

#include "Reservation.h"
#include <iomanip>
#include <algorithm>

using namespace seneca;

// Default constructor
// Initializes the member variables to safe empty state
Reservation::Reservation() : m_id{ '\0' }, m_name{ '\0' }, m_email{ '\0' }, m_partysize{ 0 }, m_day{ 0 }, m_hour{ 0 } {};

// update function
// updates the day and time of the reservation
void Reservation::update(int day, int time) {
	m_day = day;
	m_hour = time;
}

// trim function
// trims the white spaces from the string
std::string Reservation::trim(const std::string& str) {
	auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
	auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
	return (start < end) ? std::string(start, end) : std::string();
}

// Constructor with 1 argument
// Initializes the member variables with the data provided
Reservation::Reservation(const std::string& res) {
	// copy the string to temp
	// get the id and remove it from the string and remove the white spaces
	std::string temp = res;												

	m_id = trim(temp.substr(0, temp.find(':')));						
	temp.erase(0, temp.find(':') + 1);

	m_name = trim(temp.substr(0, temp.find(',')));						
	temp.erase(0, temp.find(',') + 1);

	m_email = trim(temp.substr(0, temp.find(',')));
	temp.erase(0, temp.find(',') + 1);

	m_partysize = std::stoi(trim(temp.substr(0, temp.find(','))));
	temp.erase(0, temp.find(',') + 1);

	m_day = std::stoi(trim(temp.substr(0, temp.find(','))));
	temp.erase(0, temp.find(',') + 1);

	m_hour = std::stoi(trim(temp.substr(0, temp.find(','))));

}

// overloaded operator<<
// displays the reservation details
std::ostream& seneca::operator<<(std::ostream& os, const Reservation& res) {

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