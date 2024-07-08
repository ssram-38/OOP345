#pragma once
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H

#include "Directory.h"

namespace seneca {
	class Filesystem {
		Directory* m_root;
		Directory* m_current;
	public:
		Filesystem(std::string fileName, std::string root = "");
		Filesystem(Filesystem&) = delete;
		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string& newCurentDir = "");
		Directory* get_current_directory() const;
		~Filesystem();
	};
}

#endif // !SENECA_FILESYSTEM_H
