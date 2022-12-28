#include "DFS.h"

void DFS(int** Graph, int** Maze, int* Visited, int* Parent, int NumCells, int Input, int Exit)
{
    int SizeG = NumCells * NumCells;
    Visited[Input] = 1;

    Maze[Input / NumCells][Input % NumCells] = 2;

    for (int i = 0; i < NumCells; i++)
    {
        for (int j = 0; j < NumCells; j++)
        {
            if (Maze[i][j] == 0) printf(" *");
            if (Maze[i][j] == 1) printf("  ");
            if (Maze[i][j] == 2) printf(" +");
        }
        printf("\n");
    }
    
    printf("\n");
    Sleep(100);
    system("cls");
    
    Maze[Input / NumCells][Input % NumCells] = 1;
    
    for (int i = 0; i < SizeG; i++) 
    {
        if (Graph[Input][i] == 1 && Visited[i] == 0 && Visited[Exit] == 0) 
        {
            Parent[i] = Input;
            DFS(Graph, Maze, Visited, Parent, NumCells, i, Exit);
        }
    }
    
    for (int i = 0; i < SizeG; i++) 
    {
        if (Visited[Exit] == 0) 
        {
            Input = Parent[Input];
            DFS(Graph, Maze, Visited, Parent, NumCells, Input, Exit);
        }
    }
}