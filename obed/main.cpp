#include <iostream>
#include <fstream>
#include <string>
#include "obed.h"

using namespace std;


int main()
{
	try
	{
		char i('n');
		unsigned int numberDateBegin(0), numberDateEnd(0);
		string filename;
		filename = "in_data.txt";
		fstream inFile(filename, ios::in);
		map<string, int> *report;
		if (!inFile)
		{
			cout << "Error open file \"" << filename << "\". " << "Resolve this problem and to begin again." << endl;
			cin.get();
			return 0;
		}
		dbObed dbober;
		string tmp;

		cout << "Load Lunches from file...\n";
		while (!inFile.eof())
		{
			getline(inFile, tmp);
			cout << tmp << endl;
			dbober.add(tmp);
		}
		cout << "Load Lunches complete.\n----------------------------------------------------\n";

		cout << dbober[100];
		for (unsigned int i = 0; i < dbober.Size(); ++i)
		{
			cout << i + 1 << "  " << dbober[i] << endl;
		}
		cout << "Report lunches:\n";
		while (i != 'y')
		{
			cout << "Enter number date begin(no more " << dbober.Size() << "): ";
			while (true)
			{
				cin >> numberDateBegin;
				if (cin.fail() || numberDateBegin > dbober.Size())
				{
					cin.sync();
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cerr << "Error: incorrect enter, reenter: ";
				}
				else
				{
					break;
				}
			}
			cout << "Enter number date end(no more " << dbober.Size() << "): ";
			while (true)
			{
				cin >> numberDateEnd;
				if (cin.fail() || numberDateBegin > dbober.Size() || numberDateEnd < numberDateBegin)
				{
					cin.sync();
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cerr << "Error: incorrect enter, reenter: ";
				}
				else
				{
					break;
				}
			}
			report = dbober.getMassReport(numberDateBegin - 1, numberDateEnd - 1);
			for (map<string, int>::iterator iter = (*report).begin(); iter != (*report).end(); ++iter)
			{
				cout << iter->first << "  " << iter->second << endl;
			}
			cout << "Exit? (y/n): ";
			while (true)
			{
				cin >> i;
				if (cin.fail() || (i != 'y' && i != 'n'))
				{
					cin.sync();
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cerr << "Error: incorrect enter, reenter: ";
				}
				else
				{
					break;
				}
			}
		}
		return 0;
	}
	catch(char e[])
	{
		cerr << e << endl;
		system("pause");
	}
}