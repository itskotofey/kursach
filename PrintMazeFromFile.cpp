#include "PrintMazeFromFile.h"
#include "CreateGraph.h"
#include "DFS.h"

void PrintMazeFromFile()
{
	int NumCells = 0, **Maze = NULL, **Graph = NULL, SizeG = 0, *Visited = NULL, *Parent = NULL, Entry = 0, Exit = 0;
	char filename[25];
	FILE* file;
	
	printf("Введите имя файла для того чтобы загрузить лабиринт\n");

	do
	{
		scanf("%s", filename);
		file = fopen(filename, "r");

		if (file == NULL)
		{
			printf("Имя файла не соответствует регламенту\n");
		}

	} while (file == NULL);
	
	fscanf(file, "%d ", &NumCells);
	fscanf(file, "%d ", &Entry);
	fscanf(file, "%d ", &Exit);

	Maze = (int**)malloc(sizeof(int) * NumCells);
	for (int i = 0; i < NumCells; i++) 
	{
		Maze[i] = (int*)malloc(sizeof(int) * NumCells);
		
		for (int j = 0; j < NumCells; j++) 
		{
			fscanf(file, "%d", &Maze[i][j]);
		}
	}
	fclose(file);

	Graph = CreateGraph(NumCells, Maze);

	SizeG = NumCells * NumCells;

	Visited = (int*)malloc(SizeG * sizeof(int));
	if (Visited) memset(Visited, 0, SizeG * sizeof(int));

	Parent = (int*)malloc(SizeG * sizeof(int));	
	if (Parent)	memset(Parent, 0, SizeG * sizeof(int));
	
	DFS(Graph, Maze, Visited, Parent, NumCells, Entry, Exit);

	for (int i = 0; i < SizeG; i++)
	{
		free(Graph[i]);
	}
	free(Graph);

	for (int i = 0; i < NumCells; i++)
	{
		free(Maze[i]);
	}
	free(Maze);
}