#pragma once
#include <raylib.h>

class insertion_sort
{
public:
	void drawinsertion_sort(int ax[],int ay[],int);
	void updateinsertion_sort(int ax[], int ay[], int);
	int timer = 0;
	int curr = 0,ctr = curr;
	void swap(int& a, int& b);
};