#include "stdafx.h"
#include "sort.h"

void sort(int a, NOTE *_note)
{
	int i, j, k;
	NOTE helper;
	for (i = 0; i < 3; i++)
		for (j = 0; j < a; j++)
			for (k = 0; k < a; k++)
				if (_note[j].TEL()[i] < _note[k].TEL()[i])
				{
					helper = _note[j];
					_note[j] = _note[k];
					_note[k] = helper;
				}
}