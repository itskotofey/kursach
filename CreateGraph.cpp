#include "CreateGraph.h"

int** CreateGraph(int n, int **Maze) 
{
	int SizeG = n * n; //Размер графа = количество элементво массива лабиринта
    
	int **Graph = (int**)malloc(sizeof(int) * SizeG);
    
    for (int i = 0; i < SizeG; i++) 
    {
        Graph[i] = (int*)malloc(SizeG * sizeof(int));
        
        for (int j = 0; j < SizeG; j++)
        {
            Graph[i][j] = 0;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (Maze[i][j] == 1) 
            {
                if (Maze[i - 1][j] == 1) 
                {
                    Graph[i * n + j][i * n + j - n] = 1;
                    Graph[i * n + j - n][i * n + j] = 1;
                }

                if (Maze[i + 1][j] == 1) 
                {
                    Graph[i * n + j][i * n + j + n] = 1;
                    Graph[i * n + j + n][i * n + j] = 1;
                }

                if (Maze[i][j - 1] == 1) 
                {
                    Graph[i * n + j][i * n + j - 1] = 1;
                    Graph[i * n + j - 1][i * n + j] = 1;
                }

                if (Maze[i][j + 1] == 1) 
                {
                    Graph[i * n + j][i * n + j + 1] = 1;
                    Graph[i * n + j + 1][i * n + j] = 1;
                }
            }
        }
    }
    return Graph;
}