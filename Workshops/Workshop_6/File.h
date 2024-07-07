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
#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "Resource.h"

namespace seneca {
	class File : public Resource {
		std::string m_contents;
	public:
		File(std::string name, std::string cont = "");
		void update_parent_path(const std::string&);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
	};
}


#endif // !SENECA_FILE_H
