/*
 * FileManager.h
 *
 *  Created on: 28.09.2019
 *      Author: nicdo
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include "DefManager.h"
#include <fstream>

class FileManager
{
	DefManager dManager;
	std::string filename;
	std::string changeWords(std::string &to_change, std::string &to_put, std::string &line);

public:

	FileManager(std::string filename);
	void updateFile();
	void changeFile(std::string filename);
	std::string ppp();
	~FileManager();

};

#endif /* FILEMANAGER_H_ */
