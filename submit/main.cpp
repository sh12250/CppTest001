#include <iostream>
#include <stdio.h>

void SquareMaker(int squareSize)
{
	int width = squareSize;
	int length = squareSize;

	while (length > 0)
	{
		width = squareSize;

		while (width > 0)
		{
			printf("* ");
			width -= 1;

			if (width == 0)
			{
				printf("\n");
			}
		}

		length -= 1;
	}
}

int main() 
{
	int loopCount;

	scanf_s("%d", &loopCount);

	SquareMaker(loopCount);

	return 0;
}
