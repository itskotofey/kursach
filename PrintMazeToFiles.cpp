#include "PrintMazeToFiles.h"

void PrintMazeToFiles(int** Maze, int NumCells, int Entry, int Exit)
{
    char filename[25];
    FILE* file;
    
    printf("Введите имя файла для того чтобы сохранить лабиринт (формата .txt)\n");

    do
    {
        scanf("%s", filename);
        file = fopen(filename, "w");

        if (file == NULL)
        {
            printf("Имя файла не соответствует регламенту\n");
        }

    } while (file == NULL);

    printf("\n");

    fprintf(file, "%d ", NumCells);
    fprintf(file, "%d ", Entry);
    fprintf(file, "%d ", Exit);
    fprintf(file, "\n");

    for (int i = 0; i < NumCells; i++)
    {
        for (int j = 0; j < NumCells; j++)
        {
            if (Maze[i][j] == 0) printf(" *");
            else printf("  "); 
            fprintf(file, "%d ", Maze[i][j]);
        }
        printf("\n");
        fprintf(file, "\n");
    }

    fclose(file);
}