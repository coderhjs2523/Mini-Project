#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void creatematrix(int arr[][4]);
void gamerule(int arr[][4]);
void swap(int *x, int *y);
void showmatrix(int arr[][4]);
int readenterkey();
int winner(int arr[][4]);
int shiftup(int arr[][4]);
int shiftdown(int arr[][4]);
int shiftleft(int arr[][4]);
int shiftright(int arr[][4]);

int main()
 {
    int arr[4][4], maxtry = 1000;
    char name[20], check;

    printf("\nEnter your name: ");
    scanf("%s", name);
    system("cls");

    while (1)
    {
        creatematrix(arr);
        gamerule(arr);
        while (!winner(arr))
        {
            system("cls");
            if (!maxtry)
                break;
            printf("Player name: %s\nMoves remaining: %d\n", name, maxtry);
            showmatrix(arr);
            int key = readenterkey();
            switch (key)
             {
                case 69: // E key
                case 101: // e key
                    printf("\n\a\a\a\a\a Thanks for playing\a\a\a\a\n");
                    printf("\n Press 'Enter' to exit\n");
                    key = readenterkey();
                    return 0;
                case 72: // Up arrow key
                    if (shiftup(arr))
                        maxtry--;
                    break;
                case 80: // Down arrow key
                    if (shiftdown(arr))
                        maxtry--;
                    break;
                case 75: // Left arrow key
                    if (shiftleft(arr))
                        maxtry--;
                    break;
                case 77: // Right arrow key
                    if (shiftright(arr))
                        maxtry--;
                    break;
                default:
                    printf("\n\a\a\a\aNot Allowed\a\a\n");
            }
        }
        if (!maxtry)
            printf("\n!!!!!!!!!!!  YOU LOSE  !!!!!!!!\n");
        else
            printf("\nCongratulations %s! You win the game\n", name);

        fflush(stdin);
        printf("\nPress 'y' to play again\n");
        scanf(" %c", &check);
        if ((check != 'y') && (check != 'Y'))
            break;
        maxtry = 1000;
    }
    return 0;
}

void creatematrix(int arr[][4])
{
    int n = 15;
    int num[n]; // Include 0 for the empty space
    for (int i = 0; i < n; i++)
        num[i] = i + 1;

    srand(time(0));
    int lastindex = n - 1, index;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (lastindex >= 0)
            {
                index = rand() % (lastindex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastindex--];
            }
        }
    arr[3][3] = 0;// Assigning zero for empty space
    }

}

void gamerule(int arr[][4])
{
    printf("\t\t\tNUMBER SHIFTING GAME\n\n");
    printf("\t\tInstructions\n");
    printf("You can move the empty space next to adjacent blocks.\n");
    printf("\tMove UP    : by Up arrow key\n");
    printf("\tMove DOWN  : by Down arrow key\n");
    printf("\tMove LEFT  : by Left arrow key\n");
    printf("\tMove RIGHT : by Right arrow key\n");
    printf("\nArrange the matrix to win!\n");
    printf("\n\t\tWINNING SITUATION:\n");
    printf("    -----------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("    |");
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%2d |", 4*i+j+1);
            else
                printf("   |");
        }
        printf("\n");
    }
    printf("    -----------------\n");
    printf("You can exit game at any time by pressing 'E' and 'e'\n");
    printf("Press any key to start...\n");
    readenterkey();
}

int readenterkey()
{
    char c =_getch();
    if (c == -32)
        c =_getch();
    return c;
}

int winner(int arr[][4])
{
    int k = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != k && k != 16)
                return 0;
            k++;
        }
    }
    return 1;
}

int shiftup(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 0) return 0;
    swap(&arr[i][j], &arr[i - 1][j]);
    return 1;
}

int shiftdown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 3) return 0;
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1;
}

int shiftleft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 0) return 0;
    swap(&arr[i][j], &arr[i][j - 1]);
    return 1;
}

int shiftright(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 3) return 0;
    swap(&arr[i][j], &arr[i][j + 1]);
    return 1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void showmatrix(int arr[][4])
{
    printf("  -----------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("  |");
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%2d |", arr[i][j]);
            else
                printf("   |");
        }
        printf("\n");
    }
    printf("  -----------------\n");
}
