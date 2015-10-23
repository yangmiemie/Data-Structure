#include "timer.h"

/* Return 1 if the difference is negative, otherwise 0.  */
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(struct timeval *tv)
{
    char buffer[30] = {0};
    time_t curtime;

    // printf("%ld.%06ld", tv->tv_sec, tv->tv_usec);
    // printf("\n");
    curtime = tv->tv_sec;
    strftime(buffer, 30, "%m-%d-%Y  %T", localtime(&curtime));
    printf(" = %s.%06ld\n", buffer, tv->tv_usec);
}

struct timeval time_print()
{
  struct timeval tvBegin, tvEnd, tvDiff;
  gettimeofday(&tvBegin, NULL);
  timeval_print(&tvBegin);
  return tvBegin;
}

void time_diff_print(struct timeval *tvDiff, struct timeval *tvEnd, struct timeval *tvBegin)
{
  timeval_subtract(tvDiff, tvEnd, tvBegin);      
  printf("%ld.%06ld\n", (*tvDiff).tv_sec, (*tvDiff).tv_usec);
}