#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
     HANDLE stdOutput;
     COORD pos;
     stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     pos.X = x;
     pos.Y = y;
     SetConsoleCursorPosition(stdOutput, pos);
}

void TwoDigit(int A, char s[])
{
    int l = 0, i = 0;
    int r = 0, t;
    
    t = A;
    while (A != 0)
    {
        r = A % 10;
        A = A / 10;
        l++;
    }
    
    A = t;
    switch ( l )
    {
       case 0:
       case 1:
           s[2] = '\0';
           s[1] = A + 48;
           s[0] = 48;
           break;
       case 2:
           s[2] = '\0';
           i = 0;
           while (A != 0)
           {
                 r = A % 10;
                 A = A / 10;
                 i++;
                 s[l - i] = r + 48;
           }
           break;
    }
} 
        
int main()
{
    long int T;
    char str[256];
    int C,H,M,S;
    do
    {
        gotoxy(0,0);
        T = time(NULL);
        C = T % 86400 + 12600;
        H = C / 3600;
        M = (C - H*3600)/60;
        S= C - H*3600 - M*60;
        TwoDigit(H,str);
        printf("%s:",str);
        TwoDigit(M,str);
        printf("%s:",str);
        TwoDigit(S,str);
        printf("%s",str);
        Sleep(1000);
    } while (1);
    
    return 0;
}
