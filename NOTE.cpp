#include "stdafx.h"
#include "NOTE.h"


NOTE::NOTE()
{
	FIO[0] = '\0';
	telefon[0] = '\0';
	DR[0] = '\0';
	cout << "Administration#";
}

NOTE::NOTE(char _FIO[10], char _telefon[11], int _DR[3])
{
	for (int i = 0; i < 10; i++)
		FIO[i] = _FIO[i];
	for (int i = 0; i < 11; i++)
		telefon[i] = _telefon[i];
	for (int i = 0; i < 3; i++)
		DR[i] = _DR[i];
}

NOTE::~NOTE()
{
	cout << "#Administration";
}

void NOTE::set()
{
	cout << endl << "Vvedite FIO: " << endl;
	cin >> FIO;
	cout << "Vvedite telefon: " << endl;
	cin >> telefon;
	cout << "Vvedite den' rozhdeniya: " << endl;
	cin >> DR[0];
	cout << "Vvedite mesyac rozhdeniya: " << endl;
	cin >> DR[1];
	cout << "Vvedite god rozhdeniya: " << endl;
	cin >> DR[2];
}

void NOTE::get()
{
	cout << endl << "FIO: " << FIO << endl;
	cout << "Telefon': " << telefon << endl;
	cout << "Data rozhdeniya: ";
	for (int i = 0; i < 3; i++)
	{
		cout << DR[i];
		if (i == 2)
			break;
		cout << ".";
	}
	cout << endl;
}

char *  NOTE::TEL()
{
	return telefon;
}

char * NOTE::fio()
{
	return FIO;
}