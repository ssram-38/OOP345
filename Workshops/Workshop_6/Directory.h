#pragma once
#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "Resource.h"

namespace seneca {
	class Directory : public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(std::string dir);
		void update_parent_path(const std::string&);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource*);
		Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
		void remove(const std::string&, const std::vector<OpFlags>& flags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& formatFlags = {}) const;
		~Directory();
		Directory(Directory&) = delete;
		Directory& operator=(Directory&) = delete;
		Directory(Directory&&) noexcept = delete;
		Directory& operator=(Directory&&) noexcept = delete;

	};
}

#endif // !SENECA_DIRECTORY_H
