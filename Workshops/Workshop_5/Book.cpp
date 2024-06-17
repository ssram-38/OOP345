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
#include "Book.h"
#include "utils.h"

namespace seneca {
	// Query functions:

	// @param none
	// @return const std::string&
	// @brief Returns the title of the book
	const std::string& Book::title() const {
		return m_title;
	}

	// @param none
	// @return const std::string&
	// @brief Returns the country of the book
	const std::string& Book::country() const {
		return m_country;

	}

	// @param none
	// @return const size_t&
	// @brief Returns the year of the book
	const size_t& Book::year() const {
		return m_year;
	}

	// @param none
	// @return const double&
	// @brief Returns a constsant unmodifiable price of the book (Overloaded)
	const double& Book::price() const {
		return m_price;

	}

	// @param none
	// @return double&
	// @brief Returns a modifiable price of the book (Overloaded)
	double& Book::price() {
		return m_price;
	}

	// Constructor

	// @param const std::string&
	// @return none
	// @brief Initializes the object with the values extracted from the string
	Book::Book(const std::string& strBook) : m_author{ "" }, m_title{ "" }, m_country{ "" }, m_year{ 0 }, m_price{ 0.0 }, m_description{ "" } {

		size_t authPos = strBook.find(',');													// find the position of the first comma
		std::string tempAuth = strBook.substr(0, authPos);									// extract the author from the string	
		m_author = utils::trim(tempAuth);													// remove leading and trailing spaces and assign the author to the object

								// Same process for the rest of the values expect of the description
		size_t titlePos = strBook.find(',', authPos + 1);									
		std::string tempTitle = strBook.substr(authPos + 1, titlePos - authPos - 1);
		m_title = utils::trim(tempTitle);

		size_t countryPos = strBook.find(',', titlePos + 1);								
		std::string tempCountry = strBook.substr(titlePos + 1, countryPos - titlePos - 1);
		m_country = utils::trim(tempCountry);

		size_t pricePos = strBook.find(',', countryPos + 1);
		std::string tempPrice = strBook.substr(countryPos + 1, pricePos - countryPos - 1);
		m_price = std::stod(utils::trim(tempPrice));
		
		size_t yearPos = strBook.find(',', pricePos + 1);
		std::string tempYear = strBook.substr(pricePos + 1, yearPos - pricePos - 1);
		m_year = std::stoi(utils::trim(tempYear));

		std::string tempDesc = strBook.substr(yearPos + 1);									// capture the rest of the string for description
		m_description = utils::trim(tempDesc);												// remove leading and trailing spaces and assign the description to the object
	}
	
	// Output stream operator

	// @param std::ostream&, const Book&
	// @return std::ostream&
	// @brief Overloads the << operator to display the book object
	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::right << std::setw(20) << book.m_author << " | "
			<< std::right << std::setw(22) << book.title() << " | "
			<< std::right << std::setw(5) << book.country() << " | "
			<< std::right << std::setw(4) << book.year() << " | "
			<< std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.price() << " | "
			<< std::left << std::setw(22) << book.m_description << std::endl;
		return os;
	}
}