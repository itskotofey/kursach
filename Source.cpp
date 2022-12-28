#include <locale.h>
#include "GenerMaze.h"
#include "PrintMazeFromFile.h"

int main() 
{
    char* Check = (char*)malloc(100 * sizeof(char));
   
    setlocale(LC_ALL, "RU");

    printf("��������� �������� ��� �������������? (������������� - 1, ��������� - 2)\n");

    if (Check)
    {
        memset(Check, 0, 100);
    
        do 
        {
            scanf("%s", Check);

            if (Check[0] != '1' && Check[0] != '2')
            {
                printf("������� ���������� ��������\n");
            }

        } while (Check[0] != '1' && Check[0] != '2');
    
        if (Check[0] == '1')
        {
            GenerMaze(); // ��������� ��������� (�� ������������������ �����)
            printf("\n���������� �� ������ ��������!!!\n");
        }
        else
        {
            PrintMazeFromFile(); // ���������� ��������� � ����� � ����� � �������
            printf("\n���������� �� ������ ��������!!!\n");
        }
    }

    free(Check);

    system("pause");
    return 0;
}