/*
 * DefManager.cpp
 *
 *  Created on: 27.09.2019
 *      Author: nicdo
 */

#include "DefManager.h"

DefManager::DefManager()
{
}


void DefManager::addData(DefData d)
{
	this->data.push_back(d);
}

void DefManager::addFromFile(std::string filename)
{
	std::fstream file;
	std::string line;
	int lineNb = 0;

	file.open(filename, std::ios::in | std::ios::out);
	if(!file.is_open())
	{
		std::cout << "\nopening failed!\n";
		return;
	}


	while(!file.eof())
	{
		getline(file, line);

		line.begin();

		if(line.find("#define ") != std::string::npos)
		{
			int deflong = 8;
			int n = 0;
			int i = 0;
			while(line[deflong+i] != ' ')
				{
					n++;
					i++;
				}


			int m = 0;
			while(line[deflong+1+i] != ' ' && line[deflong+1+i] != '\0')
				{
					m++;
					i++;
				}

			std::string orig;
			std::string repl;

			for(int j = 0; j < n; j++)
			{
				orig += line[deflong+j];
			}

			for(int j = 0; j < m; j++)
			{
				repl += line[deflong+n+1+j];
			}

			this->data.push_back(DefData(orig, repl, lineNb));
		}
		lineNb++;
	}
	file.close();

}

DefData* DefManager::getData(int nb)
{
	return &data[nb];
}

int DefManager::getDataLength()
{
	return this->data.size();
}

void DefManager::showData(int nb)
{
	std::cout << this->data[nb];
}


int DefManager::getSize()
{
	return this->data.size();
}

void DefManager::resetData()
{
	this->data.clear();
}
