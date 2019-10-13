/*
 * DefManager.h
 *
 *  Created on: 27.09.2019
 *      Author: nicdo
 */

#ifndef DEFMANAGER_H_
#define DEFMANAGER_H_
#include <vector>
#include <string>
#include<fstream>
#include "DefData.h"

class DefManager
{
private:
	std::vector<DefData> data;


public:
	DefManager();
	void addData(DefData d);
	void addFromFile(std::string filename);
	DefData* getData(int nb);
	int getDataLength();
	void showData(int nb);
	int getSize();
	void resetData();

};

#endif /* DEFMANAGER_H_ */
