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
#include <string>
#include <iostream>

namespace seneca {
	class Reservation {
		std::string m_id;
		std::string m_name;
		std::string m_email;
		int m_partysize;
		int m_day;
		int m_hour;
	public:
		Reservation();
		static std::string trim(const std::string& str);
		Reservation(const std::string& res);
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif // !SENECA_RESERVATION_H
