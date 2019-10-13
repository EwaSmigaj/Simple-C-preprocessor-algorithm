/*
 * FileManager.cpp
 *
 *  Created on: 28.09.2019
 *      Author: nicdo
 */

#include "FileManager.h"
#include <bits/stdc++.h>

FileManager::FileManager(std::string filename)
{

	this->filename = filename;
}

void FileManager::updateFile()
{
	this->dManager.addFromFile(this->filename);
	this->file.open(this->filename, std::ios::in | std::ios::out);
	if(!this->file.is_open())
	{
		std::cout << "\nopening failed!\n";
		return;
	}
	std::fstream newFile;
	std::string newFileName = this->filename;
	for(int i = 0; i < 4; i++)
	{
		newFileName.pop_back();
	}
	newFileName+="NEW.txt";
	newFile.open(newFileName, std::fstream::in | std::fstream::out | std::fstream::trunc);

	if(!newFile.is_open())
	{
		std::cout << "\n please make sure the file is open. ";
		return;
	}

	if (this->dManager.getSize() < 1) //chceck if there is any #define in this file
	{
		std::cout<< "\n there is nothing to update \n";
		return;
	}



	int i = 0;
	int lineNb = 0;
	std::string line;
	this->file.seekg(0);


	while(!this->file.eof())
	{
		std::string nLine;
		bool xd =0;
		getline(this->file, line);
		if(lineNb > this->dManager.getData(i)->getLine() && i < this->dManager.getDataLength())
			{
				i++;
			}

		for(int j = 0; j < i; j++)
		{
			if(line.find(this->dManager.getData(j)->getBefore()) != std::string::npos)
			{
				std::string bef = this->dManager.getData(j)->getBefore();
				std::string aft = this->dManager.getData(j)->getAfter();
				nLine = this->changeWords(bef, aft, line);
				xd = 1;

			}
		}
		lineNb++;
		if(xd == 1)
			{
			newFile << nLine;
			newFile << "\n";
			}
		else
			{
			newFile << line << std::endl;
			}
	}
}

void FileManager::changeFile(std::string filename)
{
	if (this->file.is_open()) this->file.close();
	this->dManager.resetData();
	file.open(filename, std::ios::in | std::ios::out);
	if(!file.is_open())
	{
		std::cout << "\nopening new file failed!\n";
		return;
	}
}

std::string FileManager::changeWords(std::string &to_change, std::string &to_put, std::string &line)
{
	std::vector<std::string> tokens;
	std::stringstream a(line);
	std::string word;
	int word_count = 0;
	while(getline(a, word, ' '))
	{
		if(word == to_change) tokens.push_back(to_put);
		else tokens.push_back(word);
		word_count++;
	}
	std::string newLine;
	for(int i = 0; i < word_count; i++)
	{
		newLine += (tokens[i]+" ");

	}
	return newLine;
}

FileManager::~FileManager()
{
	if (this->file.is_open()) this->file.close();
}



