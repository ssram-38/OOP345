/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 16-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#include <iomanip>
#include "Movie.h"
#include "utils.h"

namespace seneca {

	// Constructor

	// @param const std::string&
	// @return none
	// @brief Initializes the object with the values from the string
	Movie::Movie(const std::string& strMovie) : m_title{ "" }, m_year{ 0 }, m_description{ "" } {

		size_t titlePos = strMovie.find(',');											// Find the position of the first comma
		std::string tmpTitle = strMovie.substr(0, titlePos);							// Extract the title
		m_title = utils::trim(tmpTitle);												// Trim the title
		
		// Same process as above
		size_t yearPos = strMovie.find(',', titlePos + 1);
		std::string tmpYear = strMovie.substr(titlePos + 1, yearPos - titlePos - 1);
		m_year = std::stoi(utils::trim(tmpYear));

		// Extract the rest of the string for the description and trim it
		std::string tempDesc = strMovie.substr(yearPos + 1);									
		m_description = utils::trim(tempDesc);
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::right << std::setw(40) << movie.title() << " | "
			<< std::right << std::setw(4) << movie.m_year << " | "
			<< std::left << movie.m_description << std::endl;
		return os;
	}
}