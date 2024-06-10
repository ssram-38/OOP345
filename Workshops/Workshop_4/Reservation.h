/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 06-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#pragma once
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {
    class Reservation {
        char* m_id;
        std::string m_name;
        std::string m_email;
        int m_partysize;
        int m_day;
        int m_hour;
    public:
        // Default constructor
        Reservation();

        // Constructor with one argument
        Reservation(const std::string& res);

        // Copy constructor
        Reservation(const Reservation& other);

        // Copy assignment operator
        Reservation& operator=(const Reservation& other);

        // Move constructor
        Reservation(Reservation&& other) noexcept;

        // Move assignment operator
        Reservation& operator=(Reservation&& other) noexcept;

        // Destructor
        ~Reservation();

        // Utility function to trim whitespace from a string
        static std::string trim(const std::string& str);

        // Function to update day and time
        void update(int day, int time);

        // Friend function to overload the output stream operator
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // !SENECA_RESERVATION_H

