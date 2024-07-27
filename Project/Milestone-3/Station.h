/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 13-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iomanip>
#include "Utilities.h"

namespace seneca {

	class Station {

		/* INSTANCE VARIABLE */
		int m_id;
		std::string m_name;
		std::string m_desc;
		size_t m_serialNumber;
		size_t m_qty;

		/* CLASS VARIABLE */
		static size_t m_widthField;
		static int id_generator; 
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}


#endif // !SENECA_STATION_H
