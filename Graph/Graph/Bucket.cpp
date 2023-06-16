#include "Bucket.h"

bucket_sort::bucket_sort()
{
}

void bucket_sort::drawbucket_sort(int a[],int size)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			DrawRectangleLines(i * 100, j * 100, 80, 80, RED);
		}
	}
}

