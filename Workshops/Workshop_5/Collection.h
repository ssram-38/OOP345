/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 16-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#pragma once
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <iomanip>
#include <string>

namespace seneca {
	// Templated collection class
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_items;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&);
	public:
		// Constructor
		Collection(const std::string& name) : m_name{ name }, m_items{ nullptr }, m_size{ 0 }, m_observer{ nullptr } {};
		// Copy and move operations are deleted
		Collection(const Collection& src) = delete;
		Collection(Collection&& src) = delete;
		Collection& operator=(Collection&& src) = delete;
		Collection& operator=(const Collection& src) = delete;

		// Destructor
		// @brief Deletes the dynamically allocated memory
		~Collection() {
			delete[] m_items;
		}

		// Query functions

		// @brief Returns the name of the collection
		// @param none
		// @return const std::string&
		const std::string& name() const {
			return m_name;
		}

		// @brief Returns the number of items in the collection
		// @param none
		// @return size_t
		size_t size() const {
			return m_size;
		}

		// @brief Sets the observer function
		// @param void (*observer)(const Collection<T>&, const T&)
		// @return void
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		// @brief Adds an item to the collection
		// @param const T&
		// @return Collection<T>&
		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == item.title()) {
					return *this;
				}
			}

			T* temp = new T[m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temp[i] = m_items[i];
			}
			temp[m_size] = item;
			delete[] m_items;
			m_items = temp;
			m_size++;
			if (m_observer != nullptr) {
				m_observer(*this, item);
			}
			return *this;
		}

		// @brief Returns the item from the specified index
		// @param size_t
		// @return T&
		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				std::string error_msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(error_msg);
			}
			return m_items[idx];
		}

		// @brief Returns the item from the specified title
		// @param const std::string&
		// @return T*
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == title) {
					return &m_items[i];
				}
			}
			return nullptr;
		}

		// @brief Overloaded operator<< to display the collection
		// @param std::ostream&, const Collection&
		// @return std::ostream&
		friend std::ostream& operator<<(std::ostream& os, const Collection& collection) {
			for (size_t i = 0; i < collection.size(); i++) {
				os << collection[i];
			}
			return os;
		}
	};
}
#endif // !SENECA_COLLECTION_H
