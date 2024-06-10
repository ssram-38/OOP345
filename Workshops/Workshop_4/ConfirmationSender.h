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
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {
    class ConfirmationSender {
        const Reservation** m_reservations{ nullptr };       // Array of pointers to Reservation objects
        size_t m_cnt{ 0 };                                  // Number of reservations in the array

    public:
        ConfirmationSender() = default;
        ConfirmationSender(const ConfirmationSender& src);
        ConfirmationSender& operator=(const ConfirmationSender& src);
        ConfirmationSender(ConfirmationSender&& src) noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // SENECA_CONFIRMATIONSENDER_H
