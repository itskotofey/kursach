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

    printf("������� ������ ����� ���������\n");
    
    scanf("%d", &NumCells);
    NumCells = 2 * NumCells + 1;
    
    Maze = (int**)malloc(sizeof(int) * NumCells);
    
    InitGrid(NumCells, Maze); // �������������� ����� (NumCells - ���������� ������ �����)

    for (int i = 1; i < NumCells; i += 2) // �������� �������� ��������� (�������� ������)
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
        
        Maze[0][ran] = 1; // ���� ������
        Entry = ran;

        ran = rand() % NumCells;
        
        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }
        
        Maze[NumCells - 1][ran] = 1; //����� �����
        Exit = NumCells * (NumCells - 1) + ran;
    }
    else 
    {
        int ran = rand() % NumCells;

        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }

        Maze[ran][NumCells - 1] = 1; // ���� ������
        Entry = NumCells * (ran + 1) - 1;

        ran = rand() % NumCells;
        
        while (ran % 2 == 0) 
        {
            ran = rand() % NumCells;
        }
        
        Maze[ran][0] = 1; // ����� �����
        Exit = NumCells * ran;
    }

    PrintMazeToFiles(Maze, NumCells, Entry, Exit); // ������� �� ����� �������� � ��������� ��� � ����

    int **Graph = NULL, SizeG = 0, *Visited = NULL, *Parent = NULL;

    Graph = CreateGraph(NumCells, Maze); // ������� ������� ��������� �� ���������� ���������
    SizeG = NumCells * NumCells; // ������ ����� = ���������� ��������� ������� ���������

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