#include <time.h>
#include <iostream>
#include <string>
#include <map>
#include "Lunch.h"
#include <list>
#include <time.h>


class dbObed
{
	unsigned int size=-1;
	std::map<unsigned int, Lunch> Lunches;
	std::string creditor; //Тот кто платил
public:
	void add(std::string &str)
	{
		if(str.size()==0)
		{
			throw "string is empty";
		}
		int tmpTmStamp;
		int tmpSummObed;
		Lunch tmpLunch;
		std::string tmp;

		//Получаем штамп времени
		size_t pos(0), pos1(0);
		pos1 = str.find_first_of(" \t", pos);
		tmpTmStamp = atoi(str.substr(pos, pos1).c_str());

		//Получаем кредитора в данном обеде
		pos = str.find_first_not_of(" \t", pos1);
		pos1 = str.find_first_of(" \t", pos);
		tmp = str.substr(pos, pos1 - pos);

		//Получаем сумму обеда
		pos = str.find_first_not_of(" \t", pos1);
		pos1 = str.find_first_of(" \t", pos);
		tmpSummObed = atoi(str.substr(pos, pos1 - pos).c_str());
		tmpLunch.setCreditor(tmp, tmpSummObed);
		
		Lunches[tmpTmStamp] = tmpLunch;
		for (; str[pos1] != ';';)
		{

			pos = str.find_first_not_of(" \t;", pos1);
			pos1 = str.find_first_of(" \t;", pos);
			tmp = str.substr(pos, pos1 - pos);

			pos = str.find_first_not_of(" \t;", pos1);
			pos1 = str.find_first_of(" \t;", pos);
			tmpSummObed = atoi(str.substr(pos, pos1 - pos).c_str());

			//Добавляем дебитора в массив 
			Lunches[tmpTmStamp].addDebtor(tmp, tmpSummObed);
		}
		++size;
	}
	std::string operator[] (unsigned int i)
	{
		if(i>size)
		{
			throw "over massive";
		}
		std::string s;
		std::map<unsigned int, Lunch>::iterator iter=Lunches.begin();
		for (;i!=0;--i)
		{
			++iter;
		}
		s += std::to_string((iter->first)+1);
		s += " ";
		s+=iter->second.getstring();
		return s;
	}
	std::string getDate(unsigned int i)
	{
		std::string result;
		std::map<unsigned int, Lunch>::iterator iter = Lunches.begin();
		for (; i != 0; --i)
		{
			++iter;
		}
		char buffer[80];
		char* format = "%Y %B %d";
		time_t seconds = iter->first;
		tm* timeinfo = localtime(&seconds);
		strftime(buffer, 80, format, timeinfo);
		result = buffer;
		return result;
	}

	std::map<std::string, int>* getMassReport(unsigned int dateBegin, unsigned int dateEnd)
	{
		std::map<std::string, int> *MassReport = new std::map<std::string, int>();
		std::string creditor;
		std::map<unsigned int, Lunch>::iterator iter = Lunches.begin();
		for (unsigned int i = dateBegin; i != 0; --i, ++iter){}
		for (unsigned int i = dateBegin; i <= dateEnd; ++i, ++iter)
		{
			creditor = iter->second.GetCreditor();
			std::map<std::string, int> *massDebtors = iter->second.getListDebtors();
			for (std::map<std::string, int>::iterator iter = (*massDebtors).begin(); iter != (*massDebtors).end();++iter)
			{
				(*MassReport)[iter->first + " -> " + creditor] += iter->second;
			}
		}
		return MassReport;
	}
	unsigned int Size()
	{
		return size+1;
	}
};