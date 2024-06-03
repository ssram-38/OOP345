/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 02-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#include "Book.h"
#include <iomanip>

using namespace seneca;

// Default constructor
// @brief Initializes the object to a safe empty state
// @param None
Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

// 3-argument constructor
// @brief Initializes the object with the values received
// @param title: The title of the book
// @param nChapters: The number of chapters in the book
// @param nPages: The number of pages in the book
Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) {
	m_title = title;
	m_numChapters = nChapters;
	m_numPages = nPages;
}

// isValid
// @brief Returns true if the book is valid
// @param None
bool Book::isValid() const {
	return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
}

// pagesPerChapter
// @brief Returns the average number of pages per chapter
// @param None
double Book::pagesPerChapter() const {
	return static_cast<double>(m_numPages) / m_numChapters;
}

// print
// @brief Prints the book information
// @param os: The output stream
std::ostream& Book::print(std::ostream& os) const {
	if (isValid()) {
		os << std::right << std::setw(56) << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages)
			<< " | " << std::left << std::setw(15) << "(" + std::to_string(pagesPerChapter()) + ")";
	}
	else {
		os << "| Invalid book data";
	}
	return os;
}

// operator<<
// @brief Overloaded operator<< to print the book information
// @param os: The output stream
// @param bk: The book object
std::ostream& seneca::operator<<(std::ostream& os, const Book& bk) {
	return bk.print(os);
}

// operator<
// @brief Returns true if the number of pages per chapter is less than the other book
// @param other: The other book object
bool Book::operator<(const Book& other) const {
	return pagesPerChapter() < other.pagesPerChapter();
}

// operator>
// @brief Returns true if the number of pages per chapter is greater than the other book
// @param other: The other book object
bool Book::operator>(const Book& other) const {
	return pagesPerChapter() > other.pagesPerChapter();
}

