#include "stdafx.h"
#include "zapros.h"

void zapros(NOTE *_note, int a)
{
	char fio[20];
	cout << endl << endl << "Vvedite FIO cheloveka, dannye o kotorom vivesty: ";
	cin >> fio;
	for (int i = 0; i < a; i++)
	{
		if (!strcmp(_note[i].fio(), fio))
		{
			cout << "Informaciya po zaprosu: ";
			_note[i].get();
			break;
		}
		else
			if (i == a - 1)
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, 12);
				cout << "Net takogo cheloveka!";
				SetConsoleTextAttribute(handle, 15);
			}
	}
}