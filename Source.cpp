#include <locale.h>
#include "GenerMaze.h"
#include "PrintMazeFromFile.h"

int main() 
{
    char* Check = (char*)malloc(100 * sizeof(char));
   
    setlocale(LC_ALL, "RU");

    printf("Загрузить лабиринт или сгенерировать? (сгенерировать - 1, загрузить - 2)\n");

    if (Check)
    {
        memset(Check, 0, 100);
    
        do 
        {
            scanf("%s", Check);

            if (Check[0] != '1' && Check[0] != '2')
            {
                printf("Введите правильное значение\n");
            }

        } while (Check[0] != '1' && Check[0] != '2');
    
        if (Check[0] == '1')
        {
            GenerMaze(); // Генерация лабиринта (по инициализированной сетке)
            printf("\nПоздравляю вы прошли лабиринт!!!\n");
        }
        else
        {
            PrintMazeFromFile(); // Считывание лабиринта с файла и вывод в консоль
            printf("\nПоздравляю вы прошли лабиринт!!!\n");
        }
    }

    free(Check);

    system("pause");
    return 0;
}