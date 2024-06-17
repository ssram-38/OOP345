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
#pragma once
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace seneca {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book() : m_author{ "" }, m_title{ "" }, m_country{ "" }, m_year{ 0 }, m_price{ 0.0 }, m_description{ "" } {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		const double& price() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}
	};
}

#endif // !SENECA_BOOK_H
