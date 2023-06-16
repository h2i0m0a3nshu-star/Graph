#include "Selection.h"

int selection_sort::min(int a[],int start, int end)
{
	int x = a[start], y = start;
	for (int i = start; i < end; i++)
	{
		if (a[i] <= x)
		{
			x = a[i];
			y = i;
		}
	}
	return y;
}

void selection_sort::swap(int& a, int& b)
{
	int backup = a;
	a = b;
	b = backup;
}

void selection_sort::drawSelection_sort(int ax[], int ay[], int size)
{
	for (int i = 0; i < size; i++)
	{
		DrawRectangle(ax[i], 1000 - ay[i] * 10, 8, ay[i]*10, WHITE);
	}
	DrawRectangle(ax[minelm], 1000 - ay[minelm] * 10, 8, ay[minelm] * 10, RED);
	DrawRectangle(ax[r-1], 1000 - ay[r-1] * 10, 8, ay[r-1] * 10, GREEN);
	if (r-1 == 99)
	{
		DrawText("SORTING\nCOMPLETED", 10, 10, 50, GREEN);
	}
}

void selection_sort::updateSelection_sort(int ax[], int ay[], int size)
{
	minelm = min(ay, 0, size);
	timer++;
	for (static int i = 0; i < size; i++)
	{
		if (timer < 5)
		{
			return;
		}
		minelm = min(ay, i, size);
		if (ay[i] > ay[minelm])
		{
			swap(ay[i], ay[minelm]);
		}
		r++;
		timer = 0;
	}
	
}
