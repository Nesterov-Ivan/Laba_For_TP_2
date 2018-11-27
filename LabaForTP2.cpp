#include "stdafx.h"

#include "NOTE.h"
#include "Zadanie2.h"
#include "sort.h"
#include "zapros.h"

int main()
{
	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 12);
	cout << "Vnimanie! Pri vvode teksta vmesto probelov ispol'zuyte: _" << endl << endl;
	SetConsoleTextAttribute(handle, 15);
	string fail;
	int a = 3, switcha = 1, switcha2;
	NOTE *note = new NOTE[a];
	Zadanie2 zadanie2;

	while (switcha)
	{
		cout << endl << "Vyberite deystvie: " << endl
			<< "1 - 1 Zadanie " << endl
			<< "2 - 2 Zadanie " << endl
			<< "0 - Exit" << endl;
		cin >> switcha;
		switch (switcha)
		{
		case 1: 
			cout << "Vyberite deystvie: " << endl
				<< "1 - Vvesty dannye s klaviatury" << endl
				<< "2 - Vypolnit' zapros" << endl
				<< "3 - Otsortirovat' dannye po nomeram telefonov" << endl
				<< "4 - Vivesty dannye na ekran" << endl
				<< "0 - Nazad" << endl;
			cin >> switcha2;
			switch (switcha2)
			{
			case 1: 
				for (int i = 0; i < a; i++)
					note[i].set();
				break;
			case 2:
				zapros(note, a);
				break;
			case 3:
				sort(a, note);
				break;
			case 4:
				for (int i = 0; i < a; i++)
					note[i].get();
				break;
			case 0:
				break;
			}
			break;
		case 2:
			cout << "Vvedite nazvanie faila: ";
			cin >> fail;
			fail << zadanie2;
			fail >> zadanie2;
			break;
		case 0:
			break;
		}
	}
	delete[] note;
	system("pause");
    return 0;
}