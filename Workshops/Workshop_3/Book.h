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
#pragma once
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <string>
#include <iostream>
namespace seneca
{
	// Book class
	class Book
	{
		std::string m_title{};		// Book title
		unsigned m_numChapters{};	// Number of chapters
		unsigned m_numPages{};		// Number of pages
	public:
		Book();																	// Default constructor
		Book(const std::string& title, unsigned nChapters, unsigned nPages);	// 3-argument constructor
		bool isValid() const;													// Returns true if the book is valid
		double pagesPerChapter() const;											// Returns the average number of pages per chapter
		bool operator<(const Book& other) const;								// Returns true if the average number of pages per chapter is less than the other book
		bool operator>(const Book& other) const;								// Returns true if the average number of pages per chapter is greater than the other book
		std::ostream& print(std::ostream& os) const;							// Prints the book information
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);		// Overloaded operator<<
}
#endif // !SENECA_BOOK_H

