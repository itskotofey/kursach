#include <time.h>
#include "GenerMaze.h"
#include "InitGrid.h"
#include "PrintMazeToFiles.h"
#include "CreateGraph.h"
#include "DFS.h"

void GenerMaze() 
{
    int **Maze = NULL, NumCells = 0;
    
    srand(time(NULL));

    printf("Введите размер сетки лабиринта\n");
    
    scanf("%d", &NumCells);
    NumCells = 2 * NumCells + 1;
    
    Maze = (int**)malloc(sizeof(int) * NumCells);
    
    InitGrid(NumCells, Maze); // Инициализирует сетку (NumCells - количество клеток сетки)

    for (int i = 1; i < NumCells; i += 2) // Алгоритм создания лабиринта (двоичное дерево)
    { 
        for (int j = 1; j < NumCells; j += 2) 
        {
            if (rand() % 2 == 0)
            {
                if (j != NumCells - 2) 
                {
                    Maze[i][j + 1] = 1;
                }
                else 
                {
                    Maze[i - 1][j] = 1;
                }
            }
            else 
            {
                if (i > 1)
                {
                    Maze[i - 1][j] = 1;
                }
                else 
                {
                    if (j != NumCells - 2) 
                    {
                        Maze[i][j + 1] = 1;
                    }
                    else 
                    {
                        Maze[i - 1][j] = 1;
                    }
                }
            }
        }
    }

    if (Maze) Maze[0][NumCells - 2] = 0;

    int Entry = 0, Exit = 0;
    if (rand() % 2 == 0) 
    {
        int ran = rand() % NumCells;
        
        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }
        
        Maze[0][ran] = 1; // вход сверху
        Entry = ran;

        ran = rand() % NumCells;
        
        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }
        
        Maze[NumCells - 1][ran] = 1; //выход снизу
        Exit = NumCells * (NumCells - 1) + ran;
    }
    else 
    {
        int ran = rand() % NumCells;

        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }

        Maze[ran][NumCells - 1] = 1; // вход справа
        Entry = NumCells * (ran + 1) - 1;

        ran = rand() % NumCells;
        
        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }
        
        Maze[ran][0] = 1; // выход слева
        Exit = NumCells * ran;
    }

    PrintMazeToFiles(Maze, NumCells, Entry, Exit); // Выводит на экран лабиринт и сохраняет его в файл

    int **Graph = NULL, SizeG = 0, *Visited = NULL, *Parent = NULL;

    Graph = CreateGraph(NumCells, Maze); // Создает матрицу смежности по созданному лабиринту
    SizeG = NumCells * NumCells; // Размер графа = количество элементво массива лабиринта

    Visited = (int*)malloc(SizeG * sizeof(int));
    if (Visited) memset(Visited, 0, SizeG * sizeof(int));

    Parent = (int*)malloc(SizeG * sizeof(int));
    if (Parent) memset(Parent, 0, SizeG * sizeof(int));

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