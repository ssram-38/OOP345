/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 21-05-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#pragma once
#ifndef SENECA_PROTEINBASE_H
#define SENECA_PROTEINBASE_H
#include <string>

namespace seneca {
	// ProteinDatabase class to store the protein sequences
	class ProteinDatabase {
		// Private data members
		int m_numProteinSequences;									// The number of protein sequences currently stored
		std::string* m_proteinSequence = nullptr;					// The array of protein sequences
	public:
		// Constructor, Copy Constructor, Copy Assignment Operator and Destructor
		ProteinDatabase();
		ProteinDatabase(const ProteinDatabase& other);
		ProteinDatabase& operator=(const ProteinDatabase& other);
		~ProteinDatabase();

		// One argument constructor
		ProteinDatabase(const char* filename);

		// Public member functions
		size_t size() const;										// query the number of protein sequences currently stored
		std::string operator[](size_t index) const;					// query the protein sequence at the specified index
	};
}

#endif // !SENECA_PROTEINBASE_H
