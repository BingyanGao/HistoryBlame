/* hello -- print a greeting message and exit. */
/* AIX requires this to be the first thing in the file!!!  */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <errno.h>//modified in Revision 35
#include "getopt.h"
static char *progname;

int
main (argc, argv)
     int argc;
     char *argv[];
{
  int optc;
  int h = 0, v = 0, t = 0, m = 0, lose = 0, z = 0;

  progname = argv[0];

}

//change the world !!! Exam timetable!!


char *
xmalloc (size)
     unsigned int size;
{
  char *ptr = malloc (size);
  if (! ptr)
    {
      fprintf (stderr, "%s: virtual memory exhausted\n", progname);
      exit (1);
    }
  return ptr;
}
