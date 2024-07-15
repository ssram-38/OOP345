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
#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>
#include <iomanip>

namespace seneca {

	enum class BakedType {
		BREAD,
		PASTERY
	};

	struct BakedGood {
		BakedType s_type;
		std::string s_description{""};
		int s_shelf{0};
		int s_stock{0};
		double s_price{0.0};
	};

	class Bakery {
		std::vector<BakedGood> bakedGoods;
		static std::string trim(const std::string& str);
	public:
		Bakery(const std::string& filename);
		void showGoods(std::ostream& os) const;
		void sortBakery(const std::string& fieldName);
		std::vector<BakedGood> combine(const Bakery& src) const;
		bool inStock(const std::string& description, BakedType srcType) const;
		std::list<BakedGood> outOfStock(BakedType srcType) const; // from the list library, if it is not there it wont work
	};

	std::ostream& operator<<(std::ostream& out, const BakedGood& b);

}

#endif // !SENECA_BAKERY_H

