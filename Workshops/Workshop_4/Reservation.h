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
#pragma once
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iostream>
#include <string>

namespace seneca {

	class Reservation {
		char* m_reservationId{ nullptr };
		std::string m_name;			// name 
		std::string m_email;		// email
		int m_numOfPeople{ 0 };		// number of people in the party
		int m_day{ 0 };				// day of the reservation
		int m_hour{ 0 };			// hour of the reservation
	public:
		Reservation() = default;
		Reservation(const std::string& res);
		Reservation(const Reservation& src);					// copy constructor
		Reservation(Reservation&& src) noexcept;				// move constructor
		~Reservation();											// destructor
		Reservation& operator=(const Reservation& src);			// copy assignment operator
		Reservation& operator=(Reservation&& src) noexcept;		// move assignment operator

		void update(int day, int time);							// modifier

		void display(std::ostream& os) const;					// query

		friend std::ostream& operator<<(std::ostream& os, const Reservation& src); // friend helper function
	};

}

#endif // !SENECA_RESERVATION_H