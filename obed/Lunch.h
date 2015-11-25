#include <string>

class Lunch
{
	std::string creditor;
	int summCredit;
	unsigned int numberOffdeDebtor =-1;
	std::map<std::string, int> debtors;
public:
	Lunch()
	{

	}
	void setCreditor(std::string str, int &_summCredit)
	{
		creditor = str;
		summCredit = _summCredit;
	}
	void addDebtor(std::string debtor, int &summ)
	{
		debtors[debtor] = summ;
		++numberOffdeDebtor;
	}
	std::string getstring()
	{
		std::string result;
		result=creditor+" "+std::to_string(summCredit);
		for (std::map<std::string, int>::iterator iter=debtors.begin(); iter != debtors.end(); ++iter)
		{
			result += " ";
			result += iter->first;
			result += " ";
			result += std::to_string(iter->second);
		}
		result += ";";
		return result;
	}
	std::string setCreditor()
	{
		return creditor;
	}
	unsigned int GetNumberOffDebtord ()
	{
		return numberOffdeDebtor;
	}

	std::map<std::string, int>* getListDebtors()
	{
		return &debtors;
	}
	std::string GetCreditor()
	{
		return creditor;
	}

};