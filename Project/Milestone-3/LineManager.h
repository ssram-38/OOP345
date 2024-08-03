/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 26-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#pragma once

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "CustomerOrder.h"
#include "Workstation.h"

namespace seneca {
	class LineManager {
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{ 0 };
		Workstation* m_firstStation{ nullptr };
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // !SENECA_LINEMANAGER_H
