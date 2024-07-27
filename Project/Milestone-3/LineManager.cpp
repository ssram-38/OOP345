/*****************************************************************
Declaration
Name : Sarandip Sahota Ram
Email : ssram@myseneca.ca
Student_ID : 106824238
Date : 26 - 07 - 2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#include <iostream>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
#include <algorithm>

namespace seneca {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities ut;

		std::ifstream input(file);

		if (!input.is_open())
		{
			throw std::string("Unable to open file.");
		}

		std::string data;

		while (!input.eof())
		{
			getline(input, data);
			size_t pos = 0;
			bool more = true;
			std::string currentStation, nextStation;
			currentStation = ut.extractToken(data, pos, more);

			if (more) {
				nextStation = ut.extractToken(data, pos, more);
			}

			Workstation* currentWorkStation = nullptr;
			Workstation* nextWorkstation = nullptr;

			for_each(stations.begin(), stations.end(), [&currentWorkStation, &nextWorkstation, currentStation, nextStation](Workstation* ws)
				{
					if (ws->getItemName() == currentStation) {
						currentWorkStation = ws;
					}

					else if (ws->getItemName() == nextStation)
					{
						nextWorkstation = ws;
					}
				});

			if (m_activeLine.size() == 0)
			{
				m_firstStation = currentWorkStation;
			}

			currentWorkStation->setNextStation(nextWorkstation);
			m_activeLine.push_back(currentWorkStation);
		}

		input.close();

	}

	void LineManager::reorderStations()
	{
		std::vector<Workstation*> new_Stations;

		Workstation* last_Station = nullptr;

		unsigned int count = 0;

		while (count < m_activeLine.size())
		{
			for (unsigned int i = 0; i < m_activeLine.size(); i++)
			{
				if (m_activeLine[i]->getNextStation() == last_Station)
				{
					new_Stations.push_back(m_activeLine[i]);
					last_Station = m_activeLine[i];

					count++;
					break;
				}
			}
		}

		reverse(new_Stations.begin(), new_Stations.end());

		m_firstStation = new_Stations[0];
		m_activeLine = new_Stations;
	}

	bool LineManager::run(std::ostream& os)
	{
		static int count = 0;
		count++;

		os << "Line Manager Iteration: " << count << std::endl;

		if (!g_pending.empty())
		{
			(*m_firstStation) += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->fill(os);
		}

		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->attemptToMoveOrder();
		}

		bool isEmpty = true;
		for (unsigned int i = 0; i < m_activeLine.size(); i++)
		{
			if (!m_activeLine[i]->empty())
			{
				isEmpty = false;
				break;
			}
		}

		return isEmpty;
	}

	void LineManager::display(std::ostream& os) const
	{
		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->display(os);
		}
	}
}