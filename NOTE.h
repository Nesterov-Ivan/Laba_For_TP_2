#pragma once

class NOTE
{
	char FIO[20];
	char telefon[11];
	int DR[3];
public:
	NOTE();
	NOTE(char _FIO[10], char _telefon[11], int _DR[3]);
	~NOTE();
	void set();
	void get();
	char* TEL();
	char* fio();
};