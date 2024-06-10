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

namespace seneca {
    class Restaurant {
        const Reservation** m_reservations{ nullptr }; // Array of pointers to Reservation objects
        size_t m_count{ 0 }; // Number of reservations in the array

    public:
        Restaurant() = default; // Default Constructor
        Restaurant(const Reservation* reservations[], size_t cnt); // 2-ARG Constructor
        Restaurant(const Restaurant& src); // Copy Constructor
        Restaurant(Restaurant&& src) noexcept; // Move Constructor
        ~Restaurant();  // Destructor
        Restaurant& operator=(const Restaurant& src); // Copy Assignment Operator
        Restaurant& operator=(Restaurant&& src) noexcept; // Move Assignment Operator
        size_t size() const; // Query for Size
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res); // Friend Helper Function
    };
}

#endif // !SENECA_RESTAURANT_H