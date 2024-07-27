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

#include "Utilities.h"
using namespace std;

namespace seneca {

	char Utilities::m_delimiter{ '\0' };

	void Utilities::setFieldWidth(size_t newWidth)
	{
		// Sets the field width of the current object to the value of the parameter
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		// Returns the field width of the current object
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		// keep a local copy of the starting position
		size_t local_start = next_pos;

	// find the next delimiter ( what we are looking from, where we start from)
		next_pos = str.find(m_delimiter, local_start);

		/* CASE 1 */

		// if the delimiter is found at the beginning of the string
		if (next_pos == local_start) {
			more = false;
			// throw error, the beginning of the string is the delimiter
			throw invalid_argument("Delimiter is at the next_pos given");
		}

		/* CASE 2 */

		/*
		* if we dont find the delimiter, 
		* the token is the last and the next_pos will point to
		* greatest possible value for an element of type size_t.
		*/
		if (next_pos == string::npos) {
			// if the delimiter is not found, the token is the last token in the string
			next_pos = str.length();
			more = false;
		}
		else {
			// if the delimiter is found, the token is from the starting position to the delimiter
			more = true;
		}

		// get the token from the string
		string token = str.substr(local_start, next_pos - local_start);

		/* increase the next_pos to skip the delimiter 
		* because it is pointing to the delimiter at the moment 
		* and will trigger case 1
		* so to avoid that we increase the next_pos by 1
		*/
		next_pos += 1;

		// remove leading and trailing spaces from the token
		token.erase(0, token.find_first_not_of(" ")); // for leading space
		token.erase(token.find_last_not_of(" ") + 1); // for trailing space


		if (m_widthField < token.length()) {
			setFieldWidth(token.length());
		}

		return token;
		
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		// Sets the delimiter for this class to the character received
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		// Returns the delimiter character of the current object
		return m_delimiter;
	}
}