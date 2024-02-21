/* canonical.4.2Rx2C.c - modified from canonical.c
*/
const char *AUTHOR  = "1to9only";
const char *VERSION = "2024.02.21";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <io.h>
/* 9 x 9 */
#define SUDOKU_SIZE  4
#define SUDOKU_MIN  '0'
#define SUDOKU_ONE  '1'
#define SUDOKU_MAX  '4'
#define SUDOKU_DOT  '.'
#define GRID_SIZE    16

#define NUM_PERMUTATIONS   8
static char permutations[ NUM_PERMUTATIONS][ SUDOKU_SIZE] = {
   { 0, 1, 2, 3},
   { 0, 1, 3, 2},
   { 1, 0, 2, 3},
   { 1, 0, 3, 2},
   { 2, 3, 0, 1},
   { 2, 3, 1, 0},
   { 3, 2, 0, 1},
   { 3, 2, 1, 0}};

void canonicalize( char *sudoku, char *canon, int i, int j)
{
#ifndef _MAXLEX
   register int num = 0;
#endif
#ifdef _MAXLEX
   register int num = SUDOKU_SIZE;
#endif
   int replace[ SUDOKU_SIZE+1] = { 0, -1, -1, -1, -1 };
   for (register int y=0; y<SUDOKU_SIZE; y++ )
   {
      for (register int x=0; x<SUDOKU_SIZE; x++ )
      {
         register int digit = sudoku[ permutations[ i][ y]*SUDOKU_SIZE + permutations[ j][ x]];
         if ( replace[ digit] == -1 )
         {
#ifndef _MAXLEX
            replace[ digit] = ++num;
#endif
#ifdef _MAXLEX
            replace[ digit] = num--;
#endif
         }
         canon[ y*SUDOKU_SIZE+x] = replace[ digit];
      }
   }
}

void check_canon( char *sudoku, char *canon, int i, int j)
{
#ifndef _MAXLEX
   register int num = 0;
#endif
#ifdef _MAXLEX
   register int num = SUDOKU_SIZE;
#endif
   int replace[ SUDOKU_SIZE+1] = { 0, -1, -1, -1, -1 };
   for (register int y=0; y<SUDOKU_SIZE; y++ )
   {
      for (register int x=0; x<SUDOKU_SIZE; x++ )
      {
         register int digit = sudoku[ permutations[ i][ y]*SUDOKU_SIZE + permutations[ j][ x]];
         if ( replace[ digit] == -1 )
         {
#ifndef _MAXLEX
            replace[ digit] = ++num;
#endif
#ifdef _MAXLEX
            replace[ digit] = num--;
#endif
         }
#ifndef _MAXLEX
         if ( replace[ digit] < canon[ y*SUDOKU_SIZE+x] )
#endif
#ifdef _MAXLEX
         if ( replace[ digit] > canon[ y*SUDOKU_SIZE+x] )
#endif
         {
            canonicalize( sudoku, canon, i, j);
            return;
         }
         else
#ifndef _MAXLEX
         if ( replace[ digit] > canon[ y*SUDOKU_SIZE+x] )
#endif
#ifdef _MAXLEX
         if ( replace[ digit] < canon[ y*SUDOKU_SIZE+x] )
#endif
         {
            return;
         }
      }
   }
}

char  canon[ GRID_SIZE+1] = { 0, };
void minlex( char *sudoku)
{
   char  s[ GRID_SIZE+1]; s[ GRID_SIZE] = 0; // sudoku
   char  t[ GRID_SIZE+1]; t[ GRID_SIZE] = 0; // transpose
   for (register int i=0; i<GRID_SIZE; i++ )
   {
      if ( !( sudoku[ i] >= SUDOKU_ONE && sudoku[ i] <= SUDOKU_MAX) )
      {
         sudoku[ i] = SUDOKU_MIN;
      }
      s[ i] = sudoku[ i] - SUDOKU_MIN;
   }
   for (register int y=0; y<SUDOKU_SIZE; y++ )
   {
      for (register int x=0; x<SUDOKU_SIZE; x++ )
      {
         t[ y*SUDOKU_SIZE+x] = s[ x*SUDOKU_SIZE+y];
      }
   }

   canon[ GRID_SIZE] = 0;
   canonicalize( s, canon, 0, 0);

   for (register int i=0; i<NUM_PERMUTATIONS; i++ )
   {
      for (register int j=0; j<NUM_PERMUTATIONS; j++ )
      {
         check_canon( s, canon, i, j);
         check_canon( t, canon, i, j);
      }
   }

   for (register int i=0; i<GRID_SIZE; i++ )
   {
      canon[ i] += SUDOKU_MIN;
      if ( canon[ i] == SUDOKU_MIN ) { canon[ i] = SUDOKU_DOT; }
   }
   printf( "%s\n", canon);
}

int main( int argc, char *argv[])
{
   char buffer[ 1024] = { 0, };
   char *sudoku = buffer;

   for (register int i=1; i<argc; i++ )
   {
      if ( ( argv[i][0]=='-' || argv[i][0]=='/' )
        && ( argv[i][1]=='v' || argv[i][1]=='V' )
          && argv[i][2]==0 )
      {
#ifndef _OPENMP
         printf( "VERSION:%s, single_thread.\n", VERSION);
#endif
#ifdef _OPENMP
         printf( "VERSION:%s, multi_threads.\n", VERSION);
#endif
         exit( 0);
      }
      if ( strlen( argv[i]) == GRID_SIZE )      // is sudoku line
      {
         sudoku = argv[i];
         minlex( sudoku);
      }
      else                                      // is sudoku file
      {
         struct _stat st = { 0, };
         if ( _stat( argv[i], &st) == 0 )
         {
            FILE *f = fopen( argv[i], "r");
            if ( f != (FILE*)0 )
            {
               while( fgets( sudoku, 1020, f) )          // read one line
               {
                  sudoku[ strcspn( sudoku, "\r\n")] = 0; // remove CR, LF, CRLF, LFCR, ...
                  if ( strlen( sudoku) >= GRID_SIZE )
                  {
                     minlex( sudoku);
                  }
               }
               fclose( f);
            }
         }
         else
         {
            printf( "file '%s' not found!\n", argv[i]);
            exit( 1);
         }
      }
   }

   return 0;
}

