/*
 * DefData.cpp
 *
 *  Created on: 27.09.2019
 *      Author: nicdo
 */

#include "DefData.h"

DefData::DefData()
{
	this->before = ' ';
	this->after = ' ';
	this->lineNb = -1;
}

DefData::DefData(std::string bef, std::string aft, int line)
{
	this->before = bef;
	this->after = aft;
	this->lineNb = line;
}

std::string DefData::getBefore()
{
	return this->before;
}

std::string DefData::getAfter()
{
	return this->after;
}

int DefData::getLine()
{
	return this->lineNb;
}

std::ostream & operator <<(std::ostream &os, const DefData &d)
{
	os << "\nBefore: " << d.before
	   << "\nAfter: " << d.after
	   << "\nline " << d.lineNb;
	return os;
}
