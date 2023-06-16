#include "Insertion.h"

void insertion_sort::drawinsertion_sort(int ax[],int ay[],int size)
{
	for (int i = 0; i < size; i++)
	{
		DrawRectangle(ax[i], 1000 - ay[i] * 10, 8, ay[i] * 10, WHITE);
	}
	DrawRectangle(ax[curr], 1000 - ay[curr] * 10, 8, ay[curr] * 10, GREEN);
	if (curr != 100)
	{
		DrawRectangle(ax[ctr], 1000 - ay[ctr] * 10, 8, ay[ctr] * 10, BLUE);
	}
	if (curr == 100)
	{
		DrawText("SORTING\nCOMPLETED", 600, 100, 30, GREEN);
	}
}

void insertion_sort::updateinsertion_sort(int ax[], int ay[], int size)
{
	timer++;
	for (curr; curr < size; curr++)
	{
		if (timer < 2)
		{
			return;
		}
		for (ctr = curr; ctr >= 0 && ay[ctr] > ay[ctr - 1]; ctr--)
		{
			swap(ay[ctr], ay[ctr - 1]);
		}
		timer = 0;
	}
}

void insertion_sort::swap(int& a, int& b)
{
	int backup = a;
	a = b;
	b = backup;
}
