/* alloca.c -- allocate automatically reclaimed memory
   (Mostly) portable public-domain implementation -- D A Gwyn

   This implementation of the PWB library alloca function,
   which is used to allocate space off the run-time stack so
   that it is automatically reclaimed upon procedure exit,
   was inspired by discussions with J. Q. Johnson of Cornell.
   J.Otto Tennant <jot@cray.com> contributed the Cray support.

   There are some preprocessor constants that can
   be defined when compiling for your specific system, for
   improved efficiency; however, the defaults should be okay.

   The general concept of this implementation is to keep
   track of all alloca-allocated blocks, and reclaim any
   that are found to be deeper in the stack than the current
   invocation.  This heuristic does not reclaim storage as
   soon as it becomes invalid, but it will do so eventually.

   As a special case, alloca(0) reclaims storage without
   allocating any.  It is a good idea to use alloca(0) in
   your main control loop, etc. to force garbage collection.  */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* If compiling with GCC, this file's not needed.  */
#ifndef alloca

#ifdef emacs
#ifdef static
/* actually, only want this if static is defined as ""
   -- this is for usg, in which emacs must undefine static
   in order to make unexec workable
   */
#ifndef STACK_DIRECTION
you
lose
-- must know STACK_DIRECTION at compile-time
#endif /* STACK_DIRECTION undefined */
#endif /* static */
#endif /* emacs */

/* If your stack is a linked list of frames, you have to
   provide an "address metric" ADDRESS_FUNCTION macro.  */

#ifdef CRAY
long i00afunc ();
#define ADDRESS_FUNCTION(arg) (char *) i00afunc (&(arg))
#else
#define ADDRESS_FUNCTION(arg) &(arg)
#endif

#if __STDC__
typedef void *pointer;
#else
typedef char *pointer;
#endif

#define	NULL	0