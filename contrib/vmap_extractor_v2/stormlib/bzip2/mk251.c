
/* Spew out a long sequence of the byte 251.  When fed to bzip2
   versions 1.0.0 or 1.0.1, causes it to die with internal error
   1007 in blocksort.c.  This assertion misses an extremely rare
   case, which is fixed in this version (1.0.2) and above.
*/

#include <stdio.h>

int main ()
{
   int i;
   for (i = 0; i < 48500000 ; i++)
     putchar(251);
   return 0;
}
