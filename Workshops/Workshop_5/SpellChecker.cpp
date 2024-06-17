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
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
#include "utils.h"
namespace seneca {

	// Constructor

	// @param const char*
	// @return none
	// @brief Initializes the object with the values extracted from the file
	SpellChecker::SpellChecker(const char* filename) : m_badWords { "" }, m_goodWords{ "" }, m_badWordsCount{ 0 } {
		std::ifstream file(filename);
		if (!file) {
			throw std::runtime_error("Bad file name!");
		}
		std::string line;
		size_t index = 0;
		while (std::getline(file, line)) {
			if (line[0] != '#') {
				size_t space = line.find(' ');
				m_badWords[index] = line.substr(0, space);
				m_badWords[index] = utils::trim(m_badWords[index]);
				m_goodWords[index] = line.substr(space + 1);
				m_goodWords[index] = utils::trim(m_goodWords[index]);
				index++;
			}
		}
	}

	// Operator()

	// @param std::string&
	// @return none
	// @brief Replaces the bad words with the good words
	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < 6; i++) {
			size_t pos = 0;
			while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos += m_goodWords[i].size();
				m_badWordsCount[i]++;
			}
		}
	}

	// @param std::ostream&
	// @return none
	// @brief Shows the amount of bad words replaced
	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_badWordsCount[i] << " replacements" << std::endl;
		}
	}
}