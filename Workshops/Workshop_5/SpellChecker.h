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
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <string>
#include <iostream>

namespace seneca{
	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t m_badWordsCount[6];
	public:
		SpellChecker() : m_badWords{ "" }, m_goodWords{ "" }, m_badWordsCount{ 0 } {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SENECA_SPELLCHECKER_H

