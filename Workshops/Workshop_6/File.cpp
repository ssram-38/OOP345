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
#include "File.h"

namespace seneca {

	// Constructor initializes name and contents of the file
	File::File(std::string name, std::string cont) {
		m_name = name;
		m_contents = cont;
	}

	// Function that updates the parent path of the file with the given path
	void File::update_parent_path(const std::string& path){
		m_parent_path = path;
	}

	// returns type file
	NodeType File::type() const {
		return NodeType::FILE;
	}

	// returns the full path of the file
	std::string File::path() const
	{
		return m_parent_path + m_name;
	}

	// returns the name of the file
	std::string File::name() const {
		return m_name;
	}

	// returns -1
	int File::count() const {
		return -1;
	}

	// returns the size of the file
	size_t File::size() const {
		return m_contents.size();
	}
}