#pragma once
/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 03-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H

#include "Directory.h"

namespace seneca {
	class Filesystem {
		// Member variables that store the root and current directory
		Directory* m_root;
		Directory* m_current;
	public:
		Filesystem(std::string fileName, std::string root = "");
		Filesystem(Filesystem&) = delete;
		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string& newCurentDir = "");
		Directory* get_current_directory() const;
		~Filesystem();
	};
}

#endif // !SENECA_FILESYSTEM_H
