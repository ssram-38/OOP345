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
#pragma once
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H
#include <chrono>
#include <cstring>
#include "string"
#include <iostream>

namespace seneca {
	constexpr int MAX_UNIT_LEN = 50;							// The maximum length of the time units
	constexpr int MAX_TASKS = 10;								// The maximum number of tasks that can be stored

	// Task structure to store the task name, time units and task duration
	struct Task {
		char* m_taskName = nullptr;								// The task name
		std::string m_timeUnits;								// The units of time
		std::chrono::steady_clock::duration m_taskDuration;		// The task duration

		// Default constructor to initialize the data members to a safe empty state
		Task() : m_taskName(nullptr), m_taskDuration(std::chrono::steady_clock::duration::zero()) {};
	};

	// TimedTask class to store the task records
	class TimedTask {
		// Private data members
		int m_numRecords;										// The number of records currently stored
		std::chrono::steady_clock::time_point m_startTime;		// The start time of the task
		std::chrono::steady_clock::time_point m_endTime;		// The end time of the task
		Task m_taskRecords[10];									// The array of task records
	public:
		// Constructor, Copy Constructor, Copy Assignment Operator and Destructor
		TimedTask();
		TimedTask(const TimedTask& other);
		TimedTask& operator=(const TimedTask& other);
		~TimedTask();

		// Public member functions
		void startClock();										// Sets the start time of the task
		void stopClock();										// Sets the end time of the task
		void addTask(const char* TaskName);						// Adds a task to the task list
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& task);	// Overloaded insertion operator
	};
}
#endif // !SENECA_TIMEDTASK_H