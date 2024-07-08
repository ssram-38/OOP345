/*****************************************************************
						Declaration
Name       : Sarandip Sahota Ram
Email      : ssram@myseneca.ca
Student_ID : 106824238
Date       : 03-07-2024

I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party contenppt provider.
*****************************************************************/
#include <iomanip>
#include "Directory.h"


namespace seneca {

	// Constructor that initializes the name of the directory
	Directory::Directory(std::string dir) {
		m_name = dir;
	}

	// Function that updates the parent path of the directory with the given path
	void Directory::update_parent_path(const std::string& path) {
		// Set the parent path for this directory
		m_parent_path = path;

		// Update the absolute path for each resource in this directory
		for (auto* resource : m_contents) {
			std::string new_path = m_parent_path + m_name;
			resource->update_parent_path(new_path);
		}
	}

	// returns type directory
	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	// returns the full path of the directory
	std::string Directory::path() const {
		return m_parent_path + m_name;
	}

	// returns the name of the directory
	std::string Directory::name() const {
		return m_name;
	}

	// returns the number of items in the directory
	int Directory::count() const {
		return m_contents.size();
	}

	// returns the total size of the directory
	size_t Directory::size() const {
		size_t total_size{ 0u };
		// for each resource in the directory, add the size to the total size
		for (const auto* resource : m_contents) {
			total_size += resource->size();
		}
		return total_size;
	}

	// adds a resource to the directory
	Directory& Directory::operator+=(Resource* res) {
		// Check if resource already exists in the directory and throw an exception if it does
		for (const auto* Resource : m_contents) {
			if (Resource->name() == res->name()) {
				throw std::runtime_error("Resource with the same name already exists.");
			}
		}

		// Update the parent path of the resource and add it to the directory
		res->update_parent_path(m_parent_path + m_name);
		m_contents.push_back(res);

		return *this;
	}

	// finds a resource in the directory
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
		// Check if RECURSIVE flag is set and set the recursive flag accordingly
		bool recursive = false;
		for (const auto& flag : flags) {
			if (flag == OpFlags::RECURSIVE) {
				recursive = true;
				break;
			}
		}

		// Search for the resource by name
		for (auto* resource : m_contents) {
			if (resource->name() == name) {
				return resource;
			}

			// If resource is a directory and recursive flag is set, recursively search within it
			if (recursive && resource->type() == NodeType::DIR) {
				auto* dir_resource = dynamic_cast<Directory*>(resource);
				if (dir_resource) {
					auto* found_resource = dir_resource->find(name, flags);
					if (found_resource) {
						return found_resource;
					}
				}
			}
		}

		// If not found, return nullptr
		return nullptr;
	}

	// removes a resource from the directory
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags) {
		Resource* to_remove = nullptr;				// Pointer to the resource to remove

		// Search for the resource by name
		for (auto* resource : m_contents) {
			if (resource->name() == name) {
				to_remove = resource; // Set the pointer to the resource to remove
				break;
			}
		}

		// If resource is not found, throw an exception
		if (!to_remove) {
			throw std::invalid_argument(name + " does not exist in " + m_name);
		}

		// Throw an exception if directory with no recursive flag
		if (to_remove->type() == NodeType::DIR) {
			bool recursive = false;
			for (const auto& flag : flags) {
				if (flag == OpFlags::RECURSIVE) {
					recursive = true;
					break;
				}
			}

			if (!recursive) {
				throw std::invalid_argument(name + " is a directory. Pass the RECURSIVE flag to delete directories.");
			}
		}

		// Remove the resource from the directory
		auto it = std::find(m_contents.begin(), m_contents.end(), to_remove);
		m_contents.erase(it);
		delete to_remove;
	}

	// displays the contents of the directory
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& formatFlags) const {
		size_t total_size = size();										// Get the total size of the directory
		os << "Total size: " << total_size << " bytes" << std::endl;	// Display the total size
		
		// for each resource in the directory, display the resource
		for (const auto* resource : m_contents) {
			if (resource->type() == NodeType::DIR) {
				os << "D | ";
			}
			else {
				os << "F | ";
			}
			os << std::left << std::setw(15) << resource->name() << " |";

			// Check if LONG flag is set
			if (std::find(formatFlags.begin(), formatFlags.end(), FormatFlags::LONG) != formatFlags.end()) {
				if (resource->type() == NodeType::DIR) {
					os << std::right << std::setw(2) << " " << dynamic_cast<const Directory*>(resource)->count() << " | ";
				}
				else {
					os << "    | ";
				}
				os << std::right << std::setw(4) << resource->size() << " bytes | ";
			}

			os << std::endl;
		}
	}

	// Destructor deletes resources in directory
	Directory::~Directory() {
		for (auto* resource : m_contents) {
			delete resource; // Delete each resource
		}
		m_contents.clear();
	}
}