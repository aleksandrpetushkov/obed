#include <iostream>
#include <fstream>
#include <string>
#include "obed.h"

using namespace std;


int main()
{
	string filename;
	filename = "in_data.txt";
	fstream inFile(filename, ios::in);
	if (!inFile)
	{
		cout << "Error open file \"" << filename << "\". " << "Resolve this problem and to begin again." << endl;
		cin.get();
		return 0;
	}
	dbObed dbober;
	string tmp;

	while(!inFile.eof())
	{
		getline(inFile, tmp);
		cout << tmp << endl;
		dbober.add(tmp);

	}

	for (unsigned int i = 0; i <= dbober.Size(); ++i)
	{
		cout << i << "  " << dbober[i]<<endl;
	}

	map<string, int> *kk = dbober.getMassReport(0, 5);
	for (map<string, int>::iterator iter = (*kk).begin(); iter != (*kk).end(); ++iter)
	{
		cout << iter->first << "  " << iter->second<<endl;
	}

	cin.get();
	return 0;

}