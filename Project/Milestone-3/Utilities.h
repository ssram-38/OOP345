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

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include <string>

namespace seneca
{

	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;
	public: 
		// Sets the field width of the current object to the value of the parameter
		void setFieldWidth(size_t newWidth);

		// Returns the field width of the current object
		size_t getFieldWidth() const;

		// Extracts tokens from the first parameter
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		// Sets the delimiter for this class to the character received
		static void setDelimiter(char newDelimiter);

		// Returns the delimiter character of the current object
		static char getDelimiter();
	};

}

#endif // !SENECA_UTILITIES_H
