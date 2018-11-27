#pragma once

class Zadanie2
{
	char stroka[100];
public:
	Zadanie2();
	~Zadanie2();
	template<typename T>
	friend void operator<<(const string file, T data);
	template<typename T>
	friend void operator>>(const string file, T data);
};

Zadanie2::Zadanie2()
{
	stroka[0] = '\0';
	cout << "Zadanie2#" << endl;
}

Zadanie2::~Zadanie2()
{
	cout << "#Zadanie2" << endl;
}


template<typename T>
inline void operator<<(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream f;
	try
	{
		f.open(file, ios::binary | ios::app);
		if (!f.is_open()) {
			throw 777;
		}
		int switcha;
		while (true)
		{
			cout << "Vvedite dannye: ";
			cin >> data.stroka;
			f.write(reinterpret_cast<char*>(&data), sizeof(T));
		LOOP2:
			cout << "Vveli vse dannyii? \n1 - YES\n2 - NO " << endl;
			cin >> switcha;
			if (switcha != 1 && switcha != 2)
			{
				cout << "Oshibka! Neverno vyibrali variant. Povtorite vvod: " << endl;
				goto LOOP2;
			}
			else if (switcha == 1)
				break;
		}
		f.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}
}

template<typename T>
inline void operator>>(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream in;
	try
	{
		in.open(file, ios::binary | ios::in);
		if (!in.is_open()) {
			throw 777;
		}
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T)));
		/*вывод нв экран*/
		char mas[10][10] = { "NULL","ONE","TWO","THREE" ,"FOUR" ,"FIVE" ,"SIX" ,"SEVEN" ,"EIGHT","NINE" };
		char mass[10] = { '0','1','2','3','4','5','6','7','8','9' };
		int j = 0;

		while (data.stroka[j] != '\0')
		{
		LOOP:
			for (int i = 0; i < 10; i++)
			{
				if (data.stroka[j] == mass[i])
				{
					cout << mas[i];
					j++;
					goto LOOP;
				}
			}
			if (data.stroka[j] == '.')
			{
				cout << data.stroka[j] << '\n';
				j++;
				goto LOOP;
			}
			cout << data.stroka[j];
			j++;
		}
		cout << endl;
		in.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}
}
