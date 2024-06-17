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
#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <string>

namespace utils {
	// Trim function
	// @param const std::string&
	// @return std::string
	// @brief Returns a string with leading and trailing spaces removed
	inline const std::string trim(const std::string& str) {
		size_t first_non_space = str.find_first_not_of(' ');
		size_t last_non_space = str.find_last_not_of(' ');

		return str.substr(first_non_space, last_non_space - first_non_space + 1);
	}
}
#endif // !UTILS_H
