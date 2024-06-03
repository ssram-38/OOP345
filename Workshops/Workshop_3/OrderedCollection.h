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
#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {
	// Templated OrderedCollection class derived from Collection
    template <typename T>
    class OrderedCollection : public Collection<T, 72> { 
    public:
		// Operator+= overload
		// @brief Adds an item to the collection
		// @param item: The item to add
		// @return True if the item was added, false otherwise
        bool operator+=(const T& item) {
            if (this->m_size < this->capacity()) {
                int i = this->m_size;
                while (i > 0 && this->operator[](i - 1) > item) {
                    this->operator[](i) = this->operator[](i - 1);
                    --i;
                }
                this->operator[](i) = item;
                this->incrSize();

                if (!this->m_initialized || item < this->m_smallestItem)
                    this->setSmallestItem(item);
                if (!this->m_initialized || item > this->m_largestItem)
                    this->setLargestItem(item);

                this->m_initialized = true;
                return true;
            }
            return false;
        }
    };
}
#endif // !SENECA_ORDEREDCOLLECTION_H
