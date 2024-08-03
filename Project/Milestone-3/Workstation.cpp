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

#include "Workstation.h"


namespace seneca {

	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	Workstation::Workstation(const std::string& str) : Station(str) {};

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {
		if (m_orders.empty()) {
			return false;
		}

		if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() == 0) {
			if (m_pNextStation == nullptr) {

				if (m_orders.front().isOrderFilled())
				{
					g_completed.push_back(std::move(m_orders.front()));
				}
				else
				{
					g_incomplete.push_back(std::move(m_orders.front()));
				}
			}
			else
			{
				(*m_pNextStation) += std::move(m_orders.front());
			}

			m_orders.pop_front();
			return true;
		}
		return false;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> ";
		if (m_pNextStation == nullptr) {
			os << "End of Line";
		}
		else {
			os << m_pNextStation->getItemName();
		}
		os << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

	bool Workstation::empty() const
	{
		return m_orders.empty();
	}
}