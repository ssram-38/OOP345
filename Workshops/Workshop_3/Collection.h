/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 02-06-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
*****************************************************************/
#pragma once
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <type_traits>
#include "Book.h"

namespace seneca {
	// Templated Collection class
	template <typename T, unsigned C>
    class Collection {
    protected:
		static T m_smallestItem;
        static T m_largestItem;

		T m_items[C];                       // Array of items
		unsigned m_size{ 0 };               // Number of items in the collection
		bool m_initialized{ false };        // Flag to indicate if the collection is initialized

		// Operator[] overload
		// @brief Returns the item at the specified index
		// @param index: The index of the item
        T& operator[](unsigned index) {
            return m_items[index];
        }

		// incrSize
		// @brief Increments the size of the collection
		// @param None
        void incrSize() {
            m_size++;
        }

		// setSmallestItem
		// @brief Sets the smallest item in the collection
		// @param item: The item to compare
        void setSmallestItem(const T& item) {
            if (!m_initialized || item < m_smallestItem) {
                m_smallestItem = item;
            }
        }

		// setLargestItem
		// @brief Sets the largest item in the collection
		// @param item: The item to compare
        void setLargestItem(const T& item) {
            if (!m_initialized || item > m_largestItem) {
                m_largestItem = item;
            }
        }
    public:
		// Default constructor
		// @brief Initializes the object to a safe empty state
		// @param None
        static T getSmallestItem() {
            return m_smallestItem;
        }

		// getLargestItem
		// @brief Returns the largest item in the collection
		// @param None
        static T getLargestItem() {
            return m_largestItem;
        }

		// size
		// @brief Returns the number of items in the collection
        unsigned size() const {
            return m_size;
        }

		// capacity
		// @brief Returns the capacity of the collection
        unsigned capacity() const {
            return C;
        }

		// Operator+= overload
		// @brief Adds an item to the collection
		// @param item: The item to add
		// @return True if the item was added, false otherwise
        bool operator+=(const T& item) {
            if (m_size < C) {
                if (!m_initialized) {
                    setSmallestItem(item);
                    setLargestItem(item);
                    m_initialized = true;
                }
                else {
                    if (item < m_smallestItem)
                        setSmallestItem(item);
                    if (item > m_largestItem)
                        setLargestItem(item);
                }
                m_items[m_size++] = item;
                return true;
            }
            return false;
        }

		// print
		// @brief Prints the collection
		// @param os: The output stream
        void print(std::ostream& os) const {
            if constexpr (std::is_same_v<T, Book> && (C == 10 || C == 72)) {
                for (unsigned i = 0; i < m_size; ++i) {
                    if (i == 0) {
                        os << "| ---------------------------------------------------------------------------|\n";
                    }
                    os << "| ";
                    m_items[i].print(os) << " |\n";
                }
                os << "| ---------------------------------------------------------------------------|\n";
            }
            else {
                os << "[";
                for (unsigned i = 0; i < m_size; ++i) {
                    os << m_items[i];
                    if (i < m_size - 1) {
                        os << ",";
                    }
                }
                os << "]\n";
            }
        }
    };
	// Static member initialization
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T();

	// Static member initialization
    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T();
}
#endif // !SENECA_COLLECTION_H

