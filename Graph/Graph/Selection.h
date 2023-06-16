#pragma once
#include <iostream>
#include <raylib.h>
class selection_sort
{
public:
	void drawSelection_sort(int ax[], int ay[], int);
	void updateSelection_sort(int ax[], int ay[], int);
	int minelm = 0,r=0;
	int timer = 0;
	int min(int a[],int, int);
	void swap(int&, int&);
};