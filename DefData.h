/*
 * DefData.h
 *
 *  Created on: 27.09.2019
 *      Author: nicdo
 */

#ifndef DEFDATA_H_
#define DEFDATA_H_
#include<string>
#include<iostream>

class DefData {
private:
	std::string before;
	std::string after;
	int lineNb;
public:
	DefData();
	DefData(std::string bef, std::string aft, int line);
	std::string getBefore();
	std::string getAfter();
	int getLine();

	friend std::ostream & operator<<(std::ostream &os, const DefData &d);

};

#endif /* DEFDATA_H_ */
