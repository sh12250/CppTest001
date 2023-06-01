#include <iostream>
#include <stdio.h>

void SpecialSquare(int size)
{
	if (size % 2 == 0)
	{
		size -= 1;
	}

	int space = 1;
	int save = 1;

	int widthLeft = (size - space) / 2;
	int widthRight = widthLeft;
	int lengthTop = (size - 1) / 2;
	int lengthBottom = lengthTop;

	while (lengthTop > 0)
	{
		widthLeft = (size - space) / 2;
		widthRight = widthLeft;


		while (widthLeft > 0)
		{
			printf("* ");
			widthLeft -= 1;
		}

		if (widthLeft == 0)
		{
			while (space > 0)
			{
				printf("  ");
				space -= 1;
			}

			if (space == 0) {
				save += 2;
				space = save;
			}
		}

		while (widthRight > 0)
		{
			printf("* ");
			widthRight -= 1;

			if (widthRight == 0) {
				printf("\n");
			}
		}

		lengthTop -= 1;
	}

	printf("\n");

	while (lengthBottom > 0)
	{
		save -= 2;
		space = save;
		widthLeft = (size - save) / 2;
		widthRight = widthLeft;


		while (widthLeft > 0)
		{
			printf("* ");
			widthLeft -= 1;
		}

		if (widthLeft == 0)
		{
			while (space > 0)
			{
				printf("  ");
				space -= 1;
			}

			if (space == 0) {
				if (save != size)
				{
					space = save;
				}
			}
		}

		while (widthRight > 0)
		{
			printf("* ");
			widthRight -= 1;

			if (widthRight == 0) {
				printf("\n");
			}
		}

		lengthBottom -= 1;
	}
}

int main() 
{
	int loopCount;

	scanf_s("%d", &loopCount);

	SpecialSquare(loopCount);

	return 0;
}
