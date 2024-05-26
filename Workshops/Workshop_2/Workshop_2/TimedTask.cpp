/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 21-05-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#define _CRT_SECURE_NO_WARNINGS

// Includes necessary headers
#include "TimedTask.h"

using namespace seneca;

// Default constructor
// @brief Initializes an empty TimedTask
TimedTask::TimedTask() : m_numRecords(0), m_startTime(), m_endTime() {};

// Copy constructor
// @brief Creates a copy of another TimedTask
TimedTask::TimedTask(const TimedTask& other) {
	*this = other;
}

// Copy assignment operator
// @brief Assigns data from another TimedTask
TimedTask& TimedTask::operator=(const TimedTask& other) {
	if (this != &other)
	{
		this->m_numRecords = other.m_numRecords;
		this->m_startTime = other.m_startTime;
		this->m_endTime = other.m_endTime;
		for (int i = 0; i < m_numRecords; i++)
		{
			if (other.m_taskRecords[i].m_taskName != nullptr) {
				delete[] this->m_taskRecords[i].m_taskName;
				this->m_taskRecords[i].m_taskName = new char[strlen(other.m_taskRecords[i].m_taskName) + 1];
				strcpy(this->m_taskRecords[i].m_taskName, other.m_taskRecords[i].m_taskName);
			}
			else {
				this->m_taskRecords[i].m_taskName = nullptr;
			}
			this->m_taskRecords[i].m_timeUnits = other.m_taskRecords[i].m_timeUnits;
			this->m_taskRecords[i].m_taskDuration = other.m_taskRecords[i].m_taskDuration;
		}

	}// if the current object is the same as the other object, does nothing.
	return *this;
}

// Destructor
// @brief Cleans up dynamic memory for task names
TimedTask::~TimedTask() {
	for (int i = 0; i < m_numRecords; i++)
	{
		delete[] m_taskRecords[i].m_taskName;
		m_taskRecords[i].m_taskName = nullptr;
	}
}

// @brief Starts the clock
void TimedTask::startClock() {
	m_startTime = std::chrono::steady_clock::now();
}

// @brief Stops the clock
void TimedTask::stopClock() {
	m_endTime = std::chrono::steady_clock::now();
}

/// Adds a task to the task records array
// @param TaskName - The name of the task to add
void TimedTask::addTask(const char* TaskName) {
	const std::string tUnit = "nanoseconds";
	if (m_numRecords < 10) {
		m_taskRecords[m_numRecords].m_taskName = new char[strlen(TaskName) + 1];
		strcpy(m_taskRecords[m_numRecords].m_taskName, TaskName);
		m_taskRecords[m_numRecords].m_timeUnits = tUnit;
		m_taskRecords[m_numRecords].m_taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_numRecords++;
	}
}

// friend insertion operator function
// Overloads the insertion operator to output task data
