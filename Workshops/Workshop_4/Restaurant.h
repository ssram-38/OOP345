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
#pragma once

#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace seneca {
	class Restaurant {
		Reservation** m_reservations;
		size_t m_size;
		size_t m_count;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(Restaurant& other);
		Restaurant& operator=(Restaurant& other);
		Restaurant(Restaurant&& other) noexcept;
		Restaurant& operator=(Restaurant&& other) noexcept;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
	};
}
#endif // !SENECA_RESTAURANT_H