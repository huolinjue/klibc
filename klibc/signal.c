/*
 * signal.c
 */

#include <signal.h>

__sighandler_t signal(int signum, __sighandler_t handler)
{
  struct sigaction sa;

  sa.sa_handler = handler;
  sa.sa_flags   = SA_RESETHAND;	/* SysV/Linux signal() semantic */
  sigemptyset(&sa.sa_mask);

  if ( sigaction(signum, &sa, &sa) ) {
    return (__sighandler_t)SIG_ERR;
  } else {
    return (__sighandler_t)sa.sa_handler;
  }
}

       
