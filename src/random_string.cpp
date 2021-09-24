#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
     char a[256];
     int n,l=0,j,i;
     FILE *file1;
     
     printf( "How many random strings do you want to be generated? " );
     scanf( "%d", &n );
     do
     {
        if (l > 256)
           printf( "\nERROR: length of strings must be fewer than or equal to 256.\n", n );
        printf( "\nWhat should be the length of each random string? " );
        scanf( "%d", &l );
        
     } while (l > 256);
     printf( "\nPlease wait for %d seconds.\n", n );
     for (i = 1 ; i <= n ; i++)
     {
         srand( time( NULL ) );
         for (j = 0 ; j < l ; j++)
         {
             a[j] = ( rand() % 93 ) + 33;
         }
         a[l] = '\0';
         printf( "\n%d. %s\n", i, a );
         file1 = fopen( "file.txt", "a" );
         fprintf( file1, "%s\n", a );
         fclose( file1 );
         Sleep( 1000 );
     }
     getch();
     return 0;
}
