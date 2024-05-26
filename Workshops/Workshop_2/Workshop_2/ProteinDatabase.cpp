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

#define _CRT_SECURE_NO_WARNINGS
#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>

using namespace seneca;

// Default constructor
// @brief Initializes the data members to an empty safe state
ProteinDatabase::ProteinDatabase() : m_numProteinSequences(0), m_proteinSequence(nullptr) {};

// Copy constructor
// @brief Copies the data members from the other ProteinDatabase object
ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) : m_numProteinSequences(0), m_proteinSequence(nullptr) {
	*this = other;
}

// Copy assignment operator
// @brief Copies the data members from the other ProteinDatabase object
ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
	if (this != &other) {
		delete[] m_proteinSequence;
		m_numProteinSequences = other.m_numProteinSequences;
		if (other.m_proteinSequence != nullptr) {
			m_proteinSequence = new std::string[m_numProteinSequences];
			for (size_t i = 0; i < m_numProteinSequences; ++i) {
				m_proteinSequence[i] = other.m_proteinSequence[i];
			}
		}
		else {
			m_proteinSequence = nullptr;
		}
	}
	return *this;
}

// Destructor
// @brief Deallocates the memory for the protein sequences
ProteinDatabase::~ProteinDatabase() {
	if (m_proteinSequence != nullptr){
		delete[] m_proteinSequence;
		m_proteinSequence = nullptr;
	}
}

// One argument constructor
// @brief Reads the protein sequences from the file and stores them
ProteinDatabase::ProteinDatabase(const char* filename) : m_numProteinSequences(0), m_proteinSequence(nullptr) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line[0] == '>') {
			++m_numProteinSequences;
		}
	}

	m_proteinSequence = new std::string[m_numProteinSequences];

	file.clear(); // Clear the EOF flag
	file.seekg(0, std::ios::beg); // Return to the beginning of the file

	int currentSequenceIndex = -1;
	std::string currentSequence;
	while (std::getline(file, line)) {
		if (line[0] == '>') {
			if (currentSequenceIndex != -1) {
				m_proteinSequence[currentSequenceIndex] = currentSequence;
				currentSequence.clear();
			}
			++currentSequenceIndex;
		}
		else {
			currentSequence += line;
		}
	}
	if (currentSequenceIndex != -1) {
		m_proteinSequence[currentSequenceIndex] = currentSequence;
	}

	file.close();
}

// size query
// @return The number of protein sequences stored
size_t ProteinDatabase::size() const {
	return m_numProteinSequences;
}

// @param index - the index of the protein sequence to query
// @return The protein sequence at the specified index
std::string ProteinDatabase::operator[](size_t index) const {

	if (m_proteinSequence != nullptr) {
		if (index < m_numProteinSequences) {
			return m_proteinSequence[index];
		}
	}
	return "";
}