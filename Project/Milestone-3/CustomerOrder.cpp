/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 18-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/

#include "CustomerOrder.h"

namespace seneca {

	size_t CustomerOrder::m_widthField = 1;
	
	// Defualt constructor
	CustomerOrder::CustomerOrder() {
		m_name = { "" };
		m_product = { "" };
		m_cntItem = { 0 };
		m_lstItem = { nullptr };
	}

	// 1-argument constructor
	CustomerOrder::CustomerOrder(const std::string str) {
		Utilities util;
		size_t next_pos = 0;
		bool more = true;

		try {
			// Extract Customer Name
			m_name = util.extractToken(str, next_pos, more);

			// Extract Order Name
			m_product = util.extractToken(str, next_pos, more);

			// Extract Items
			m_cntItem = count(str.begin(), str.end(), util.getDelimiter()) - 1;

			// Allocate memory for the m_lstItem array
			m_lstItem = new Item * [m_cntItem];

			// Extract each item
			for (size_t i = 0; i < m_cntItem; i++) {
				m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
			}

			// Update the widthField if necessary
			m_widthField = std::max(m_widthField, util.getFieldWidth());
		}
		catch (...) {
			throw std::invalid_argument("Invalid argument passed to the extract token function. Customer Order not parsed");
		}
	}

	// Copy constructor (not allowed)
	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw std::string("Copy constructor not allowed");
	}

	// Move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
		*this = std::move(src);
	}

	// Move assignment operator
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this != &src) {

			for (size_t i = 0; i < m_cntItem; i++) {
				// delete the inner array
				delete m_lstItem[i];
			}
			// delete the outer array
			delete[] m_lstItem;
			
			// Move the data from the source to the current object
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;

			// Set the source to a safe state
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	// Destructor
	CustomerOrder::~CustomerOrder() {
		// Loop through each item in the m_lstItem array and delete it
		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}
		// Delete the array itself
		delete[] m_lstItem;
	}

	// isOrderFilled function
	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
		return true;
	}

	// isItemFilled function
	bool CustomerOrder::isItemFilled(const std::string itemName) const {
		// Loop through each item in the order
		for (size_t i = 0; i < m_cntItem; i++) {
			// Check if the item names match
			if (m_lstItem[i]->m_itemName == itemName) {
				// Return the status of the item
				return m_lstItem[i]->m_isFilled;
			}
		}
		return true;
	}

	// fillItem function
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled == false && m_lstItem[i]->m_itemName == station.getItemName()) {

				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << std::setw(11) << std::right;
					os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "] " << std::endl;

					break;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}




	// display function
	void CustomerOrder::display(std::ostream& os) const {
		// Display the customer name and product
		os << m_name << " - " << m_product << std::endl;

		// Loop through each item in the order
		for (size_t i = 0; i < m_cntItem; ++i) {
			// Display serial number with width 6, filled with leading zeros
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";

			// Display item name with width m_widthField
			os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";

			// Display status
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED";
			}
			else {
				os << "TO BE FILLED";
			}

			// End the line
			os << std::endl;
		}
	}

}