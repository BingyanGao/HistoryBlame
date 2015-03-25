#include <sys/types.h> //comment
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
//Hello!
//Hallo!
//change the world !!! Exam timetable!!  Disaster!!
//UKFC
//benjour!!
//let it go!!!
//AWS
//Cloud
//river flows in you

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
