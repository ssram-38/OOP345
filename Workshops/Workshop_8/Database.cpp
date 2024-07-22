/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 14-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#include "Database.h"

template <>
void seneca::Database<std::string>::encryptDecrypt(std::string& value);

template <>
void seneca::Database<long long>::encryptDecrypt(long long& value);

template class seneca::Database<std::string>;
template class seneca::Database<long long>;

template <typename T>
std::shared_ptr<seneca::Database<T>> seneca::Database<T>::m_pDatabase = nullptr;