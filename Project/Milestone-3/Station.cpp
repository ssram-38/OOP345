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
#include "Station.h"
using namespace std;

namespace seneca {

	// Initialize static class members
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;

	Station::Station(const std::string& str)
	{
		//Local utilities object
		Utilities u;

		/*rest part needed for the extract token function */

		//Local variable to keep track of the position
		size_t next_pos = 0;
		//Local variable to keep track of the more
		bool more = true;

		try{
			/* First extraction before description */
			m_name = u.extractToken(str, next_pos, more);

			/*
			* The extract was always setting the
			* m_widthField to the width of the last token
			* for the utility module so the utility module
			* has the max length already stored in it
			*/

			if (m_widthField < u.getFieldWidth()) {
				m_widthField = u.getFieldWidth();
			}

			/* Extract the serial number, quantity and description */
			m_serialNumber = stoi(u.extractToken(str, next_pos, more));
			m_qty = stoi(u.extractToken(str, next_pos, more));
			m_desc = u.extractToken(str, next_pos, more);

			// Set the id
			m_id = ++id_generator;
		}
		catch (...) {
			throw invalid_argument("Invalid argument passed to the extract token function. Station not parsed");
		}
	}

	// The name of the station
	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	// The next serial number plus one is returned
	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	// The remaining quantity in stock in the station
	size_t Station::getQuantity() const
	{
		return m_qty;
	}

	void Station::updateQuantity()
	{
		// If the quantity is greater than 0
		if (m_qty > 0) {
			m_qty-=1; // SUBTRACT ONE FROM QUANTITY
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << setw(3)
			<< right
			<< setfill('0')
			<< m_id  // ID of the station printed
			<< " | ";

		os << setw(m_widthField)
			<< left
			<< setfill(' ')
			<< m_name // Name of the station printed
			<< " | ";

			os << setw(6)
				<< right
				<< setfill('0')
				<< m_serialNumber // Serial number of the station printed
				<< " | ";

		// If the full flag is true
		if (full) {
			os << setw(4)
				<< setfill(' ')
				<< right
				<< m_qty // Quantity of the station printed
				<< " | ";

				os << m_desc; // Description of the station printed
		}

		os << endl;
	}
}