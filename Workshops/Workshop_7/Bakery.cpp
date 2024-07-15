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

#include "Bakery.h"
using namespace std;

namespace seneca {

	

	std::string Bakery::trim(const std::string& str)
	{
		auto start = str.find_first_not_of(" ");
		auto end = str.find_last_not_of(" ");
		return (start == std::string::npos || end == std::string::npos)
			? ""
			: str.substr(start, end - start + 1);
	}

	Bakery::Bakery(const std::string& filename)
	{
		ifstream file(filename);

		// CANNOT OPEN FILE 
		if (!file) {
			throw runtime_error("Unable to open file" + string(filename));
		}

		string line;
		while (getline(file, line)) {

			BakedGood b;

			// get the type of the baked good
			string temp = line.substr(0, 8);
			temp = trim(temp);

			if (temp == "Bread") {
				b.s_type = BakedType::BREAD;
			}
			else if (temp == "Pastry") {
				b.s_type = BakedType::PASTERY;
			}

			// get the description of the baked good
			temp = line.substr(8, 20);
			temp = trim(temp);
			b.s_description = temp;


			// get the shelf of the baked good
			temp = line.substr(28, 14);
			temp = trim(temp);
			b.s_shelf = stoi(temp);

			// get the stock of the baked good
			temp = line.substr(42, 8);
			temp = trim(temp);
			b.s_stock = stoi(temp);

			// get the price of the baked good
			temp = line.substr(50, 8);
			temp = trim(temp);
			b.s_price = stod(temp);

			// append to the baked Goods vector in the class
			bakedGoods.push_back(b);
		}
	}

	void Bakery::showGoods(std::ostream& os) const
	{
		for_each(bakedGoods.begin(), bakedGoods.end(), [&os](const BakedGood& good) {
			os << good 
				<< endl;
		    }
		);

		// using the accumulate from numeric
		int total_stock = accumulate(bakedGoods.begin(), bakedGoods.end(), 0, 
			[](int stock_sum, const BakedGood& b) {
				return stock_sum + b.s_stock;
			}
		);

		double total_price = accumulate(bakedGoods.begin(), bakedGoods.end(), 0.0,
			[](double price_sum, const BakedGood& b) {
				return price_sum +  b.s_price;
			}
		);

		os << "Total Stock: " << total_stock << endl;
		os << "Total Price: " << fixed << setprecision(2) << total_price << endl;
	}

	void Bakery::sortBakery(const std::string& fieldName)
	{
		// description sort
		if (fieldName == "Description") {
			sort(bakedGoods.begin(), bakedGoods.end(), 
				[](const BakedGood& a, const BakedGood& b) {
					return a.s_description < b.s_description;
				}
			);
		}

		// shelf sort
		else if (fieldName == "Shelf") {
			sort(bakedGoods.begin(), bakedGoods.end(),
				[](const BakedGood& a, const BakedGood& b) {
					return a.s_shelf < b.s_shelf;
				}
			);
		}

		// stock sort
		else if (fieldName == "Stock") {
			sort(bakedGoods.begin(), bakedGoods.end(),
				[](const BakedGood& a, const BakedGood& b) {
					return a.s_stock < b.s_stock;
				}
			);
		}

		// price sort
		else if (fieldName == "Price") {
			sort(bakedGoods.begin(), bakedGoods.end(),
				[](const BakedGood& a, const BakedGood& b) {
					return a.s_price < b.s_price;
				}
			);
		}

		// unhandled field name
		else {
			cout << "Invalid field name given" << endl;
		}

	}

	std::vector<BakedGood> Bakery::combine(const Bakery& src) const
	{

		vector<BakedGood> ret(bakedGoods.size() + src.bakedGoods.size());

		//sort original by price
		Bakery original = *this;
		original.sortBakery("Price");
		
		Bakery copy = src;
		copy.sortBakery("Price");

		//merge original and copy into ret and sort by price
		merge(original.bakedGoods.begin(), original.bakedGoods.end(), copy.bakedGoods.begin(), copy.bakedGoods.end(), ret.begin(),
			[](const BakedGood& a, const BakedGood& b) {
				return a.s_price < b.s_price;
			}
		);

		return ret;
	}

	bool Bakery::inStock(const std::string& description, BakedType srcType) const
	{
		// find the baked good with the description and type
		auto it = find_if(bakedGoods.begin(), bakedGoods.end(),
			[&description, &srcType](const BakedGood& b) {
				return b.s_description == description && b.s_type == srcType;
			}
		);

		// if the baked good is found return true
		if (it != bakedGoods.end()) {
			return true;
		}

		// if the baked good is not found return false
		return false;
	}

	std::list<BakedGood> Bakery::outOfStock(BakedType srcType) const
	{
		std::list<BakedGood> outOfStockGoods;

		std::copy_if(bakedGoods.begin(), bakedGoods.end(), std::back_inserter(outOfStockGoods), [srcType](const BakedGood& good) {
			return good.s_type == srcType && good.s_stock == 0;
			}
		);

		// sort by price
		outOfStockGoods.sort([](const BakedGood& a, const BakedGood& b) {
			return a.s_price < b.s_price;
			}
		);

		return outOfStockGoods;
	}

	

	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* ";
		if (b.s_type == BakedType::BREAD) {
			out << setw(10)
				<< left
				<< "Bread"
				<< " * ";
		}
		else {
			out << setw(10)
				<< left
				<< "Pastry"
				<< " * ";
		}
		out	<< setw(20)
			<< b.s_description
			<< " * "
			<< setw(5)
			<< b.s_shelf
			<< " * "
			<< setw(5)
			<< b.s_stock
			<< " * "
			<< setw(8)
			<< right
			<< fixed
			<< setprecision(2)
			<< b.s_price
			<< " * ";
		return out;
	}

}

