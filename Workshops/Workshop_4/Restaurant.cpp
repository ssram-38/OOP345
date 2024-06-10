/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 06-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#include "Restaurant.h" 
namespace seneca {
	// Default constructor
	// Initializes the member variables to safe empty state
	Restaurant::Restaurant() : m_reservations{ nullptr }, m_count{ 0 } {}

	// Copy constructor
	// Calls the copy assignment operator to copy the data from the source object to the current object
	Restaurant::Restaurant(Restaurant& other) {
		*this = other;
	}

	// Constructor with 2 arguments
	// Initializes the member variables with the data provided
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_reservations{ nullptr }, m_count{ 0 } {
		if (cnt > 0) {
			m_count = cnt;
			m_reservations = new const Reservation * [m_count];
			for (size_t i = 0; i < m_count; i++) {
				this->m_reservations[i] = new Reservation(*reservations[i]);
			}
		}
	}

	// Copy assignment operator
	// Copies the data from the source object to the current object
	Restaurant& Restaurant::operator=(Restaurant& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i];
			}
			delete[] m_reservations;
			m_count = other.m_count;
			if (other.m_count > 0) {
				m_reservations = new const Reservation * [m_count];
				for (size_t i = 0; i < m_count; i++) {
					m_reservations[i] = new Reservation(*other.m_reservations[i]);
				}
			}
			else {
				m_reservations = nullptr;
			}
		}
		return *this;
	}
	
	// Move constructor
	// Calls the move assignment operator to move the data from the source object to the current object
	Restaurant::Restaurant(Restaurant&& other) noexcept {
		*this = std::move(other);
	}

	// Move assignment operator
	// Moves the data from the source object to the current object and nullifies the source object
	Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
		if (this != &other) {
			for (size_t i = 0; i < m_count; ++i) {
				delete m_reservations[i];
			}
			delete[] m_reservations;

			m_reservations = other.m_reservations;
			m_count = other.m_count;

			other.m_reservations = nullptr;
			other.m_count = 0;
		}
		return *this;
	}

	// Destructor
	// Deallocates the memory allocated for the reservations
	Restaurant::~Restaurant() {
		for (size_t i = 0; i < m_count; ++i) {
			delete m_reservations[i];
		}
		delete[] m_reservations;
	}

	// Overloaded insertion operator
	// Inserts the data of the restaurant object into the output stream
	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
		static size_t call_count = 0;
		++call_count;

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << call_count << ")" << std::endl;
		os << "--------------------------" << std::endl;

		if (restaurant.m_count == 0) {
			os << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < restaurant.m_count; ++i) {
				os << *restaurant.m_reservations[i];
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}
}