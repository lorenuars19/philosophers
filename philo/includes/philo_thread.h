#ifndef PHI_THREAD
#define PHI_THREAD


#ifndef NODEBUGU
# define return(RET)	\
{dprintf(2, "\033[33;1mTHID %d | %s:%d in %s \033[0m \033[60G|%s R %#-8lx : %-8ld : " #RET "\033[0m\n" , getpid(), __FILE__, __LINE__, __FUNCTION__, (((long)RET) == 0) ? ("\033[32;1m") : ((((long)RET) == 1) ? ("\033[31;1m") : ("\033[0;1m")), ((long)RET), ((long)RET)); return(RET);}
#endif

#include "philo.h"

#endif
