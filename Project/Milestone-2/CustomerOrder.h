#pragma once
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
#ifndef SENECE_CUSTOMER_ORDER_H
#define SENECE_CUSTOMER_ORDER_H

#include <algorithm>
#include "Station.h"
#include "Utilities.h"

namespace seneca {
	class CustomerOrder {
		// Item structure definition
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		// Class members
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		// Public member functions
		CustomerOrder();
		CustomerOrder(const std::string str);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

}

#endif // !SENECE_CUSTOMER_ORDER_H
