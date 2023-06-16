#include "Game.h"

game::game()
{
	for (int i = 0; i < size; i++)
	{
		posx[i] = 0;
		posy[i] = 0;
	}
	ifstream in("test.txt");
	if (!in.is_open()) {
		cout << "Failed to open file" << endl;
		// Handle the error accordingly
	}
	else {
		// Read data from the file
		// ...

		for (int i = 0; i < size; i++)
		{
			in >> posy[i];
			if (i == 0) {
				continue;
			}
			posx[i] += posx[i - 1] + 10;
		}
	}
}

game::game(int width, int height, std::string name):game()
{
	InitWindow(width,height,name.c_str());
	SetTargetFPS(60);

}

bool game::close()
{
	return WindowShouldClose();
}

void game::Tick()
{
	update();
	draw();
}

game::~game()
{
	CloseWindow();
}

void game::draw()
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(0,0);
		switch (currscreen)
		{
		case menu:
			drawGamemenu();
			break;
		case selection:
			drawSelection();
			break;
		case insertion:
			drawInsertion();
			break;
		case bucket:
			drawBucket();
			break;
		default:
			break;
		}
	EndDrawing();
}
//game menu drawing function
void game::drawGamemenu()
{
	ClearBackground(BLACK);
	DrawText("SELECTION \n    SORT", 72.5, 510, 40, WHITE);
	DrawRectangleLines(62.5, 500, 250, 120, WHITE);
	DrawText("INSERTION \n    SORT", 391.5, 510, 40, WHITE);
	DrawRectangleLines(381.5, 500, 250, 120, WHITE);
	DrawText("BUCKET \n SORT", 734, 510, 40, WHITE);
	DrawRectangleLines(694, 500, 250, 120, WHITE);
	DrawRectangleLines(selx, sely, 250, 120, RED);
}

void game::drawSelection()
{
	ClearBackground(BLACK);
	ssort.drawSelection_sort(posx,posy,size);
}

void game::drawInsertion()
{
	ClearBackground(BLACK);
	isort.drawinsertion_sort(posx,posy,size);
}

void game::drawBucket()
{
	ClearBackground(BLACK);
	bsort.drawbucket_sort(posy,size);
}

void game::update()
{
	switch (currscreen)
	{
	case menu:
		updateGamemenu();
		break;
	case selection:
		updateSelection();
		break;
	case insertion:
		updateInsertion();
		break;
	case bucket:
		updateBucket();
		break;
	default:
		break;
	}
}

//game menu updating function
void game::updateGamemenu()
{
	// the ctr checks for condition and decides where to go
		switch (s)
		{
		case select:
			selx = 62.5;
			if (IsKeyPressed(KEY_RIGHT)) s = insert;
			break;
		case insert:
			selx = 381.5;
			if (IsKeyPressed(KEY_RIGHT)) s = buck;
			break;
		case buck:
			selx = 694;
			if (IsKeyPressed(KEY_RIGHT)) s = select;
			break;
		default:
			break;
		}
	if (IsKeyPressed(KEY_SPACE) && s == select)currscreen = selection;
	else if (IsKeyPressed(KEY_SPACE) && s == insert)currscreen = insertion;
	else if (IsKeyPressed(KEY_SPACE) && s == buck)currscreen = bucket; 
}

void game::updateSelection()
{
	ssort.updateSelection_sort(posx,posy,size);
	if (IsKeyPressed(KEY_A))
	{
		currscreen = menu;
	}
}

void game::updateInsertion()
{
	isort.updateinsertion_sort(posx, posy, size);
	if (IsKeyPressed(KEY_A))
	{
		currscreen = menu;
	}
}

void game::updateBucket()
{
	if (IsKeyPressed(KEY_A))
	{
		currscreen = menu;
	}
}

