#include "Game.h"

int main()
{
	const int screen_width = 1000, screen_height = 1000;
	game graph(screen_width, screen_height, "GRAPH");
	while (!graph.close())
	{
		graph.Tick();
	}
	return 0;
}