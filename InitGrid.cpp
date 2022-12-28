#include "InitGrid.h"

void InitGrid(int NumCells, int** Grid) 
{
    for (int i = 0; i < NumCells; i++) 
    {
        Grid[i] = (int*)malloc(NumCells * sizeof(int));
        
        if (Grid[i])
        {
            for (int j = 0; j < NumCells; j++)
            {
                if (i % 2 == 0)
                {
                    Grid[i][j] = 0;
                }
                else
                {
                    if (j % 2 == 0)
                    {
                        Grid[i][j] = 0;
                    }
                    else 
                    { 
                        Grid[i][j] = 1; 
                    }
                }
            }
        }
    }
}