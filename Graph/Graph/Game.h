#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include "Selection.h"
#include "Insertion.h"
#include "Bucket.h"
using namespace std;

typedef enum screen
{
	menu = 0,
	selection,
	insertion,
	bucket,
};

typedef enum selector
{
	select = 0,
	insert,
	buck,
};

class game {

public:
	game();
	game(int, int, string);
	bool close();
	void Tick();
	~game();
private:

	int size = 100;
	float selx = 62.5, sely = 500;
	int posx[100], posy[100];
	screen currscreen = menu;
	selector s = select;
	
	selection_sort ssort;
	insertion_sort isort;
	bucket_sort bsort;

	void draw();
	void drawGamemenu();
	void drawSelection();
	void drawInsertion();
	void drawBucket();
	
	void update();
	void updateGamemenu();
	void updateSelection();
	void updateInsertion();
	void updateBucket();
};